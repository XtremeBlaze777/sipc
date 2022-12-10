#include "Optimizer.h"

#include <iostream>
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"

#include "loguru.hpp"

using namespace llvm;

void Optimizer::optimize(Module* theModule, DisoptPass pass) {
  LOG_S(1) << "Optimizing program " << theModule->getName().str();

  // Create a pass manager to simplify generated module
  if (Optimizer::DisoptPass::all != pass) { 
    auto TheFPM = std::make_unique<legacy::FunctionPassManager>(theModule);

    // Promote allocas to registers.
    if (Optimizer::DisoptPass::pmr != pass) {
      TheFPM->add(createPromoteMemoryToRegisterPass());
      std::cout << "Running PMR Pass" << std::endl;
    }

    // Do simple "peephole" optimizations
    if (Optimizer::DisoptPass::ic != pass) {
      TheFPM->add(createInstructionCombiningPass());
      std::cout << "Running IC Pass" << std::endl;
    }

    // Reassociate expressions.
    if (Optimizer::DisoptPass::re != pass) {
      TheFPM->add(createReassociatePass());
      std::cout << "Running RE Pass" << std::endl;
    }

    // Eliminate Common SubExpressions.
    if (Optimizer::DisoptPass::gvn != pass) {
      TheFPM->add(createGVNPass());
      std::cout << "Running GVN Pass" << std::endl;
    }

    // Simplify the control flow graph (deleting unreachable blocks, etc).
    if (Optimizer::DisoptPass::cfgs != pass) {
      TheFPM->add(createCFGSimplificationPass());
      std::cout << "Running CFGS Pass" << std::endl;
    }

    // Remove any dead code that is not being used (Dead Code Elimination)
    if (Optimizer::DisoptPass::dce != pass) {
      TheFPM->add(createDeadCodeEliminationPass());
      std::cout << "Running DCE Pass" << std::endl;
    }

    // Unrolls loops in while loop code to improve LOC performance
    /*if (Optimizer::DisoptPass::lun != pass) {
      TheFPM->add(createLoopUnrollPass());
      std::cout << "Running Loop Unroll Pass" << std::endl;
    }*/


    // initialize and run simplification pass on each function
    TheFPM->doInitialization();
    for (auto &fun : theModule->getFunctionList()) {
      LOG_S(1) << "Optimizing function " << fun.getName().str();

      TheFPM->run(fun);
    }
  }
}
