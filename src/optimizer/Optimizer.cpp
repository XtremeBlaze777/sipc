#include "Optimizer.h"

#include <iostream>
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/IPO.h"
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
    auto IntraFPM = std::make_unique<legacy::FunctionPassManager>(theModule);
    auto InterFPM = std::make_unique<legacy::PassManager>();

    // Multiple pass throughs
    for (int i = 0; i < 5; i++) {

      // Promote allocas to registers.
      if (Optimizer::DisoptPass::pm != pass) {
        IntraFPM->add(createPromoteMemoryToRegisterPass());
        std::cout << "Running PMR Pass" << std::endl;
      }

      // Do simple "peephole" optimizations
      if (Optimizer::DisoptPass::ic != pass) {
        IntraFPM->add(createInstructionCombiningPass());
        std::cout << "Running IC Pass" << std::endl;
      }

      // Reassociate expressions.
      if (Optimizer::DisoptPass::re != pass) {
        IntraFPM->add(createReassociatePass());
        std::cout << "Running RE Pass" << std::endl;
      }

      // Eliminate Common SubExpressions.
      if (Optimizer::DisoptPass::gvn != pass) {
        IntraFPM->add(createGVNPass());
        std::cout << "Running GVN Pass" << std::endl;
      }

      // Simplify the control flow graph (deleting unreachable blocks, etc).
      if (Optimizer::DisoptPass::cfgs != pass) {
        IntraFPM->add(createCFGSimplificationPass());
        std::cout << "Running CFGS Pass" << std::endl;
      }

      // Was unable to find any benefits for each of these passes
      //
      // Remove any dead code that is not being used (Dead Code Elimination)
      /*if (Optimizer::DisoptPass::dce != pass && Optimizer::DisoptPass::ic != pass) {
        IntraFPM->add(createDeadCodeEliminationPass());
        std::cout << "Running DCE Pass" << std::endl;
      }

      // Hoists loop invariants
      if (Optimizer::DisoptPass::licm != pass) {
        IntraFPM->add(createLICMPass());
        std::cout << "Running LICM Pass" << std::endl;
      }

      // Flattens a nested loop into a single loop
      if (Optimizer::DisoptPass::lfl != pass && Optimizer::DisoptPass::licm != pass) {
        IntraFPM->add(createLoopFlattenPass());
        std::cout << "Running Loop Flatten Pass" << std::endl;
      
      // Deletes dead loops
      if (Optimizer::DisoptPass::del != pass) {
        IntraFPM->add(createLoopDeletionPass());
        std::cout << "Running Loop Deletion Pass" << std::endl;
      }
      }*/

      // Unrolls loops in while loop code to improve LOC performance
      if (Optimizer::DisoptPass::lun != pass) {
        IntraFPM->add(createLoopUnrollPass());
        std::cout << "Running Loop Unroll Pass" << std::endl;
      }

      // Inlines functions
      if (Optimizer::DisoptPass::fi != pass) {
        InterFPM->add(createFunctionInliningPass());
        std::cout << "Running Inlining Pass" << std::endl;
      }

      // Merges identical functions
      if (Optimizer::DisoptPass::merf != pass) {
        InterFPM->add(createMergeFunctionsPass());
        std::cout << "Running Function Merge Pass" << std::endl;
      }

      // Global Dead Code Elimination on all functions
      if (Optimizer::DisoptPass::gdce != pass) {
        InterFPM->add(createGlobalDCEPass());
        std::cout << "Running Global DCE Pass" << std::endl;
      }

    }


    IntraFPM->doInitialization();
    for (auto &fun : theModule->getFunctionList()) {
      LOG_S(1) << "Optimizing function " << fun.getName().str();
      IntraFPM->run(fun);
    }
    IntraFPM->doFinalization();


    // initialize and run simplification pass on each function
    InterFPM->run(*theModule);
  }
}
