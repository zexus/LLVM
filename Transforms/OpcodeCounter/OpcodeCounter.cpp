
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "hello"

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct OpcodeCounter : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    OpcodeCounter() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
        errs() << "Function Name: " << F.getName() << "\n";
        std::map<std::string, int> opcodeMap;
        for (inst_iterator I = inst_begin(F), E = inst_end(F); I != E; ++I) {
            if(opcodeMap.find(I->getOpcodeName()) == opcodeMap.end())
                opcodeMap[I->getOpcodeName()] = 1;
            else
                opcodeMap[I->getOpcodeName()] += 1;
        }

    	// for(Function::iterator bb = F.begin(), e = F.end(); bb!=e; bb++)
    	// {
    	// 	for(BasicBlock::iterator i = bb->begin(), i2 = bb->end(); i!=i2; i++)
    	// 	{
    	// 		if(opcodeMap.find(i->getOpcodeName()) == opcodeMap.end())
        //             opcodeMap[i->getOpcodeName()] = 1;
        //         else
        //             opcodeMap[i->getOpcodeName()] += 1;
    	// 	}
    	// }

        for (std::map<std::string, int>::iterator iterator_start = opcodeMap.begin(), iterator_end = opcodeMap.end(); iterator_start != iterator_end; iterator_start++) {
            outs()<< iterator_start->first << " " << iterator_start->second << " times\n";
        }

        return false;
    }
  };
}

char OpcodeCounter::ID = 0;
static RegisterPass<OpcodeCounter> X("opcodecounter", "Opcode Counter Pass",
                                false /* Only looks at CFG */,
                                false /* Analysis Pass */);
