# Deliverable 3: Semantic Analysis`

For this assignment, we were expected to extend semantic analysis of the TIP to support SIP extensions, which required creating new subtypes and adding more constraints to the TypeConstraintVisitor. Furthermore, modifications were made to the weeding pass and the substituter.

# Challenges

The biggest challenge for this assignment was understanding what the possible type constraints could be for each extension. Furthermore, we had to go back and modify previous TIP types to support the new SIP types too, such as if and while statements now taking in a bool condition.

TipAlpha was notorious for causing confusion in our group, since we had some misconceptions on what would happen if a constraint was set to alpha. After further exploration, we discovered that if we did set something as alpha, the type could be inferred later on in the union-find algorithm, so we did make some constraints more complicated than needed be!

Finally, TipArr was a challenge to support for both the comma constructor and of constructor. With Professor Dwyer's suggestion on only considering the first element, we were able to come to a conclusion on how to determine the constraints. Combined with our knowledge of alpha, we also handled the empty array constructor for the comma constructor, but knew that we wouldn't need to worry about it for of constructor (it will be handled in deliverable 4!).

# Testing Approach

We tackled testing by splitting up tests based on the SIP extension, so we had one for boolean, one for inc/dec statements, etc. It was particularly tricky to make these tests due to the specifics of the program (ex. figuring out the right line/columns of the expressions, all the unicode, etc.). 

We had some troubles finishing up our test cases for this assignment, it mainly had to due with working with system test suite cases failing. Otherwise, all other tests were working perfectly. We ran into an issue where we had a unify error with a<null> with int.