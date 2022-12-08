#include "Optimizer.h"

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
  if (Optimizer::DisoptPass::all == pass) { 
    auto TheFPM = std::make_unique<legacy::FunctionPassManager>(theModule);

    // Promote allocas to registers.
    if (Optimizer::DisoptPass::pmr == pass)
      TheFPM->add(createPromoteMemoryToRegisterPass());

    // Do simple "peephole" optimizations
    if (Optimizer::DisoptPass::ic == pass)
      TheFPM->add(createInstructionCombiningPass());

    // Reassociate expressions.
    if (Optimizer::DisoptPass::re == pass)
      TheFPM->add(createReassociatePass());

    // Eliminate Common SubExpressions.
    if (Optimizer::DisoptPass::gvn == pass) 
      TheFPM->add(createGVNPass());

    // Simplify the control flow graph (deleting unreachable blocks, etc).
    if (Optimizer::DisoptPass::cfgs == pass)
      TheFPM->add(createCFGSimplificationPass());

    // initialize and run simplification pass on each function
    TheFPM->doInitialization();
    for (auto &fun : theModule->getFunctionList()) {
      LOG_S(1) << "Optimizing function " << fun.getName().str();

      TheFPM->run(fun);
    }
  }
}
