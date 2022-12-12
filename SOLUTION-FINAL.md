# Deliverable 5: Optimization

In this delieverable, we were expected to improve on the current tipc optimizer by expanding upon the one-pass optimization it currently does and include/remove new optimization passes in LLVM.

# Testing existing tip optimizations
cfgs.tip dropped from 10 lines to 4 lines

# Testing our Optimization
lun.tip unrolled 29 lines into 113 lines

# To test on a Mac
merf.tip (MergeFunctions with identical AST)
fi.tip (Function Inlining)

# Optimizations We Added and Why
There was no need to add scalar optimizations as GVN seemed to cover all of those, thus we focused on other items. On of the areas not yet covered was loops, thus we implemented loop unrolling.

# Big Bang Test

# Conclusion
There were some curious issues with developing on Windows (WSL) vs. a Mac: many of the create pass calls would not be included when running on WSL which made it harder to test optimizations ( notably createMergeFunction() and createFunctionInlining() ).
The aggresiveness of GVN made it very hard to confirm the usefulness of any scalar optimization. particularly the ones that were already present in base tipc. In essence, GVN acted as an "uber" optimization in the sense that it performed all the optimizations that the others would have performed.

# Notes
DeadCodeExecution needs InstructionCombine to run
LoopFLattening needs LoopInvariantCM to run

# Failed tests
pmr.tip (use registers instead of stack/memory)
licm.tip (loop invariant)
lfl.tip (loop flattening)
del.tip (dead loops)
