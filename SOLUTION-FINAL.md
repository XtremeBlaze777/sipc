# Deliverable 5: Optimization

In this delieverable, we were expected to improve on the current tipc optimizer by expanding upon the one-pass optimization it currently does and include/remove new optimization passes in LLVM.

# Testing Methodology 

For our testing, we decided to create a folder in the top of the directory called opt\_tests that would store each of our tests for all the optimizations we were testing so far. We went with the testing methodology that we would test how an optimization would perform on our current optimizer with and without it. If there was a case where the pass would improve the code in any way (ex. line of codes or speed), then we would include it into our optimizer. 

Some optimizations, such as loop unrolling, would not benefit from a lines of code metric since it's goal is to increase the number of lines to reduceloop usage. 

# Testing existing tip optimizations
The PromoteMemoryToRegister optimization was one that was difficult to test on the current optimizer, so we decided to test it standalone compared to no optimizer. We found that with the PMR pass, it would remove all the alloca, stores, and loads done for simple operations such as addition and subtraction. It reduced the line of codes tremendously, from 40 LOC in the block to 5 LOC. Furthermore, it does not use heavy operations such as load and store, which further shows why PMR pass is a solid choice for the optimizer. We tested this on pmr.tip with only the PMR optimization.

cfgs.tip dropped from 10 lines to 4 lines. 

# Loop Unrolling Optimization
lun.tip unrolled 29 lines into 113 lines. This will reduce the number of loops that the program will have to go through, thus reducing the total lines that the code will run through and improving the performance. The downside for such an optimization is that it will increase the size of the file since there are more lines of code that have been unrolled.



# To test on a Mac
merf.tip (MergeFunctions with identical AST)
fi.tip (Function Inlining)

# Optimizations We Added and Why
There was no need to add scalar optimizations as GVN seemed to cover all of those in our testing, thus we focused on other items.

We decided to focus on improving the while loop performance in tip. Once notable optimization that we previously knew from Computer Architecture was loop unrolling, which had diminishing benefits for each unroll, but would reduce the lines of code that the program would need to go through overall. We noticed that the loop unrolling pass would unroll the code from 29 lines to 113 lines, but from doing the math on how many lines of code would run, it would run x lines instead of y lines inside of the loop code.

# Failed Optimizations on our End

One of the optimization passes we decided to test was the MergeFunctionsPass, but for some reason when adding this optimization it would not work as intended. We changed the order that it was placed in the pass manager, but it would still result in a segmentation fault. Thus, we could not have conclusive testing on whether or not it would benefit our optimizer. We did include a file merf.tip that was intended to see whether or not the pass would benefit our optimizer.

Furthermore, we also had the same results when we were testing out FunctionInlining. There 
# Big Bang Test

# Conclusion
There were some curious issues with developing on Windows (WSL) vs. a Mac: many of the create pass calls would not be included when running on WSL which made it harder to test optimizations ( notably createMergeFunction() and createFunctionInlining() ).
The aggresiveness of GVN made it very hard to confirm the usefulness of any scalar optimization. particularly the ones that were already present in base tipc. In essence, GVN acted as an "uber" optimization in the sense that it performed all the optimizations that the others would have performed.

# Notes
DeadCodeExecution needs InstructionCombine to run
LoopFLattening needs LoopInvariantCM to run

# Failed tests
licm.tip (loop invariant)
lfl.tip (loop flattening)
del.tip (dead loops)
