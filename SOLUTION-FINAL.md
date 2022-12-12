# Deliverable 5: Optimization

In this delieverable, we were expected to improve on the current tipc optimizer by expanding upon the one-pass optimization it currently does and include/remove new optimization passes in LLVM.

# Testing Methodology 

For our testing, we decided to create a folder in the top of the directory called opt\_tests that would store each of our tests for all the optimizations we were testing so far. We went with the testing methodology that we would test how an optimization would perform on our current optimizer with and without it. If there was a case where the pass would improve the code in any way (ex. line of codes or speed), then we would include it into our optimizer. 

Some optimizations, such as loop unrolling, would not benefit from a lines of code metric since it's goal is to increase the number of lines to reduceloop usage. We decided to use our prior knowledge in computer architecture to explain why loop unrolling would be beneficial to the optimizer.

# Testing existing tip optimizations
The PromoteMemoryToRegister optimization was one that was difficult to test on the current optimizer, so we decided to test it standalone compared to no optimizer. We found that with the PMR pass, it would remove all the alloca, stores, and loads done for simple operations such as addition and subtraction. It reduced the line of codes tremendously, from 40 LOC in the block to 5 LOC. Furthermore, it does not use heavy operations such as load and store, which further shows why PMR pass is a solid choice for the optimizer. We tested this on pmr.tip with only the PMR optimization.

The CreateFlowGraphSimplification optimization was more straightforward, as we were able to create cfgs.tip and reduced the number of lines used in the LLVM bitcode from 10 lines to 4 lines. 

Same with the Reassociation Pass, we were able to look at the documentation and see how the pass actually reorganized the LLVM bitcode. It would modify where the math would be done for operations such as addition and subtraction to reduce the number of instructions needed. We made another example program re.tip that emphasized the abilities of the reassociation pass, reducing the number of lines by 2 in our small program.

For the Global Value Numbering Pass, we noted that it took advantage of removing redundant loads and stores. We were able to reduce the number of lines a lot by creating a sample program gvn.tip, which took advantage of using redundant values so that the pass would reduce the LLVM bitcode.

Unfortunately for the InstructionCombining Pass, we were unable to design a program in tip that would show the benefits of InstructionCombining. We were unable to find enough information about InstructionCombining to take full advantage of its design.

# Loop Unrolling Optimization
lun.tip unrolled 29 lines into 113 lines. This will reduce the number of loops that the program will have to go through, thus reducing the total lines that the code will run through and improving the performance. The downside for such an optimization is that it will increase the size of the file since there are more lines of code that have been unrolled.

# Optimizations We Added and Why
There was no need to add scalar optimizations as GVN seemed to cover all of those in our testing, thus we focused on other items.

We decided to focus on improving the while loop performance in tip. Once notable optimization that we previously knew from Computer Architecture was loop unrolling, which had diminishing benefits for each unroll, but would reduce the lines of code that the program would need to go through overall. We noticed that the loop unrolling pass would unroll the code from 29 lines to 113 lines, but from doing the math on how many lines of code would run, it would run x lines instead of y lines inside of the loop code.

We also focused on optimizing function calls and function storage space. For the latter, we used a `MergeFunctionPass` that recognized when two functions had similar ASTs. Our file, *merf.tip*, contained two functions, foo and bar, that both had identical code to compute the factorial of the input. Both of the functions were then called and summed in main. Without the MergeFunctionPass, both foo() and bar() had identical definitions (save for the names of registers) in the emitted llvm assembly. Runnng the pass, changed the definition of foo() to instead simply call bar(), which reduced the line number from 16 to 2.

Another optimization that we added was the global dead code elimination pass. Unlike the dead code elimination pass, we had to pass this through the overall pass manager, which allowed us to determine whether some functions would be used or not in our code. In the gdce.tip file, it completely removed the unused function that we had defined since it was not called in any shape or form.

# Failed Optimizations on our End

We tested various optimizations such as dead code elimination, loop invariant, loop flattening, and dead loops. For each of these passes, we found that the current optimizations that we had already handled most of the cases that these passes would also handle. One of these passes was the GVN Pass, which we found handled most scalar optimizations. There could be possible edge cases where these optimizations would have a benefit, but through our testing we were unable to find a reason to include these into our final Optimizer.

# Big Bang Test

Our big bang test was called bigbang.tip and is included in our opt\_tests folder. This combined each of the programs that we had used for testing so far into one big program to demonstrate how much faster and smaller the program would be compared to no optimizer.

# Conclusion
There were some curious issues with developing on Windows (WSL) vs. a Mac: many of the create pass calls would not be included when running on WSL which made it harder to test optimizations ( notably createMergeFunction() and createFunctionInlining() ).
The aggresiveness of GVN made it very hard to confirm the usefulness of any scalar optimization. particularly the ones that were already present in base tipc. In essence, GVN acted as an "uber" optimization in the sense that it performed all the optimizations that the others would have performed.

# Notes
DeadCodeElimination needs InstructionCombine to run
LoopFLattening needs LoopInvariantCM to run

# Failed tests
dce.tip (dead code elimination)
licm.tip (loop invariant)
lfl.tip (loop flattening)
del.tip (dead loops)
