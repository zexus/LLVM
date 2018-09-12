#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
  struct DeadInstElimination : public BasicBlockPass {
    static char ID;
    DeadInstElimination() : BasicBlockPass(ID) {}

    bool runOnBasicBlock(BasicBlock &BB) override {
        if (skipOptnoneFunction(BB))
            return false;
        auto *TLIP = getAnalysisIfAvailable<TargetLibraryInfoWrapperPass>();
        TargetLibraryInfo *TLI = TLIP ? &TLIP->getTLI() : nullptr;
        bool Changed = false;
        for (BasicBlock::iterator DI = BB.begin(); DI != BB.end(); ) {
            Instruction *Inst = &*DI++;
            if (isInstructionTriviallyDead(Inst, TLI)) {
                Inst->eraseFromParent();
                Changed = true;
                errs() << "Changed Instruction." << "\n";
            }
        }

        return Changed;
    }
  };
}

char DeadInstElimination::ID = 0;

static void registerDeadInstElimination(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
  PM.add(new DeadInstElimination());
}
static RegisterStandardPasses RegisterMyPass(
                    PassManagerBuilder::EP_EarlyAsPossible,
                    registerDeadInstElimination);