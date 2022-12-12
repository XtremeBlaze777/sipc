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

    // Multiple pass throughs
    for (int i = 0; i < 5; i++) {

      // Promote allocas to registers.
      if (Optimizer::DisoptPass::pm != pass) {
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
      if (Optimizer::DisoptPass::dce != pass && Optimizer::DisoptPass::ic != pass) {
        TheFPM->add(createDeadCodeEliminationPass());
        std::cout << "Running DCE Pass" << std::endl;
      }

      // Hoists loop invariants
      if (Optimizer::DisoptPass::licm != pass) {
        TheFPM->add(createLICMPass());
        std::cout << "Running LICM Pass" << std::endl;
      }

      // Flattens a nested loop into a single loop
      if (Optimizer::DisoptPass::lfl != pass && Optimizer::DisoptPass::licm != pass) {
        TheFPM->add(createLoopFlattenPass());
        std::cout << "Running Loop Flatten Pass" << std::endl;
      }

      // Unrolls loops in while loop code to improve LOC performance
      if (Optimizer::DisoptPass::lun != pass) {
        TheFPM->add(createLoopUnrollPass());
        std::cout << "Running Loop Unroll Pass" << std::endl;
      }

      // Deletes dead loops
      if (Optimizer::DisoptPass::del != pass) {
        TheFPM->add(createLoopDeletionPass());
        std::cout << "Running Loop Deletion Pass" << std::endl;
      }

      // Merges identical functions
      if (Optimizer::DisoptPass::merf != pass) {
        TheFPM->add(createMergeFunctionsPass());
        std::cout << "Running Function Merge Pass" << std::endl;
      }

      // Inlines functions
      if (Optimizer::DisoptPass::fi != pass) {
        TheFPM->add(createFunctionInliningPass());
        std::cout << "Running Inlining Pass" << std::endl;
      }

    }


    // initialize and run simplification pass on each function
    TheFPM->doInitialization();
    for (auto &fun : theModule->getFunctionList()) {
      LOG_S(1) << "Optimizing function " << fun.getName().str();

      TheFPM->run(fun);
    }
  }
}
