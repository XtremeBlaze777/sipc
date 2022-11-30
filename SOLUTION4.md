# Deliverable 4: Code Generation

For this assignment, we were expected to extend the code generation functions for the new SIP types. Along with that, we also included a new -dt command line option to disable type inference and create new system tests to ensure the new code generation functions were working as intended.

# Challenges

The biggest challenge with this assignment was understanding how to use the LLVM library to create the new SIP type codegen functions. This required us to read a lot of the previous TIP types to see how LLVM was used to create the bitcode necessary. A lot of errors would occur as we created the new function, and we would see the bugs in our bitcode by using the -do -asm commandline options to further debug issues.

The ultimate challenge that came to us was all the SIP types that revolved around arrays, such as the comma constructor, array indexing, and the for each loop. Looking at previous code types such as ASTAllocExpr was foreign to us. Because a lot of these SIP extensions relied on arrays working, a lot of them were held up by obtaining an understanding of how to implement the arrays. Unfortunately, we were unable to come up with a working solution for these functions. However, the others work, but we were not able to fix it in time in testing for the runtest suite to work properly. We included possible implementations of arrays and other functions in the codegen file just in case.

# Testing Approach

For this deliverable, we mostly created system tests in the selftests folder. Before putting each of the new files in, we had a separate siptests folder at the top of the directory where we would compile and run each of the system tests to ensure they were working as intended before including it into the test suite. This was useful, as it allowed us to check off what parts of the new SIP types were done so we didn't have to worry about those anymore. In addition, to test some of the internal error lines, some tests were added to the CodeGenFunctionsTest file under unit tests.