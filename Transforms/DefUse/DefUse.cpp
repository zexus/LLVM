#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  struct DefUse : public FunctionPass {
    static char ID;
    DefUse() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
        // Def-Use Find out result of one instruction to user
        for (inst_iterator I = inst_begin(F), E = inst_end(F); I != E; ++I) {
            if (I->getOpcode() == Instruction::Add || I->getOpcode() == Instruction::ICmp) {
                for (User *U : I->users()) {
                    if (Instruction *Inst = dyn_cast<Instruction>(U)) {
                        errs() << "Code:" << I->getOpcodeName() << " used in:" << *Inst << "\n";
                    }
                }
            }
        }

        // Use-Def Find out parameters of one instruction
        for (Function::iterator BB=F.begin(),EB=F.end(); BB!=EB; BB++) {
            for (BasicBlock::iterator IN=BB->begin(),EN=BB->end(); IN!=EN; IN++) {
                Instruction *I = dyn_cast<Instruction>(IN);
                if (I->getOpcode() == Instruction::Add) {
                    for (Use &U : I->operands()) {
                        Value *v = U.get();
                        errs() << *v << "\n";
                    }
                }
            }
        }

        return false;
    }
  };
}

char DefUse::ID = 0;
static RegisterPass<DefUse> X("defuse", "Def-Use Pass",
                                false /* Only looks at CFG */,
                                false /* Analysis Pass */);