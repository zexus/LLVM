#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
  struct SkeletonPass : public FunctionPass {
    static char ID;
    SkeletonPass() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
        for (Function::iterator BB=F.begin(),EB=F.end(); BB!=EB; ++BB) {
            for (BasicBlock::iterator BN=BB->begin(),EN=BB->end(); BN!=EN; ++BN) {
                if (BN->isBinaryOp()) {
                    if (BN->getOpcode() == Instruction::Add) {
                        Skeleton(cast<BinaryOperator>(BN));
                    }
                }
            }
        }

        return false;
    }

    void Skeleton(BinaryOperator *originOperator) {
        BinaryOperator *destOperator = NULL;
        if (originOperator->getOpcode() == Instruction::Add) {
            // 生成（-b）
            destOperator = BinaryOperator::CreateNeg(originOperator->getOperand(1), "", originOperator);
            // 生成 a-(-b)
            destOperator = BinaryOperator::Create(Instruction::Sub, originOperator->getOperand(0), destOperator, "", originOperator);

            destOperator->setHasNoSignedWrap(originOperator->hasNoSignedWrap());
            destOperator->setHasNoUnsignedWrap(originOperator->hasNoUnsignedWrap());
        }

        originOperator->replaceAllUsesWith(destOperator);
        errs() << "Finished." << "\n";
    }
  };
}

char SkeletonPass::ID = 0;

static void registerSkeletonPass(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses RegisterMyPass(
                    PassManagerBuilder::EP_EarlyAsPossible,
                    registerSkeletonPass);