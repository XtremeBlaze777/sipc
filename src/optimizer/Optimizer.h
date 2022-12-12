#pragma once

#include "llvm/IR/Module.h"
#include <map>

/*! \namespace Optimizer
 *  \brief routines to optimize generated code.
 */
namespace Optimizer {

  //! \brief keys for optimization passes that can be disabled
  enum DisoptPass {all, no, pm, ic, re, gvn, cfgs, dce, licm, lun, lfl, del, merf, fi, NumPasses };

  //! \brief strings for optimization pass keys
  static const constexpr char* const cmdLine[NumPasses] = {
    "disable all optimizations",
    "disable no optimizations",
    "disable promote memory to register",
    "disable instruction combining",
    "disable reassociation",
    "disable global value numbering",
    "disable CFG simplification",
    "disable dead code elimination",
    "disable loop invariant hoisting",
    "disable loop unrolling",
    "disable loop flattening",
    "disable dead loop elimination",
    "disable function merging",
    "disable function inlining",
  };

  /*! \brief optimize LLVM module. 
   *
   * Apply a series of basic optimization passes to the given LLVM module.
   * \param theModule an LLVM module to be optimized
   * \param pass an LLVM optimization pass to disable
   */
  void optimize(llvm::Module* theModule, DisoptPass pass);
}
