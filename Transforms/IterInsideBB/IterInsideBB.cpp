#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "IterInsideBB"

namespace {
  struct IterInsideBB : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    IterInsideBB() : FunctionPass(ID) {}

    bool runOnFunction(Function &Func) override {
        errs() << "Function name: " << Func.getName() << "\n";
        // ------------------------------------------------------------------------
        // for (Function::iterator BB=Func.begin(), E=Func.end(); BB!=E; ++BB) {
        //     errs() << "Basic block name: " << BB->getName() << ", has "
        //         << BB->size() << " instuctions.\n";
        //     for(BasicBlock::iterator IN=BB->begin(), EN=BB->end(); IN!=EN; ++IN) {
        //         errs() << *IN << "\n";
        //     }
        // }
        // ------------------------------------------------------------------------
        // for (BasicBlock &BB : Func) {
        //     errs() << "Block name: " << BB.getName() << ", has "
        //         << BB.size() << " instructions.\n";
        //     for (Instruction &I : BB) {
        //         errs() << I << "\n";
        //     }
        // }
        // ------------------------------------------------------------------------
        for (inst_iterator I = inst_begin(Func), E = inst_end(Func); I != E; ++I) {
            errs() << *I << "\n";
        }
        // ------------------------------------------------------------------------
        return false;
        }
    };
}

char IterInsideBB::ID = 0;
static RegisterPass<IterInsideBB> X("IterInsideBB", "Iterate inside basicblocks inside a Function",
                                false /* Only looks at CFG */,
                                false /* Analysis Pass */);