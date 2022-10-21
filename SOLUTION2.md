# Deliverable 2: Abstract Syntax Trees

For this assignment, we were expected to extend the current TIP abstract syntax tree to support the SIP extensions we created in delivereable 1. Afterwards, we also extended the pretty printer to take in each of the new AST Node types and print out a nice graphic of the whole AST.


# Challenges
We enecountered a lot of challenges during the assignment where we wern't able to complete the whole assignment with testing. 

We first began by designing the AST Nodes that would be used later in the ASTBuilder and prettyprinter. It was important that we derived the right nodes to use for the AST. This was a big obstacle in our design, since once we realized there were conflicts with other node, which resulted in a lot of refactoring.

Another issue we had was how we split up the work near the end of the deliverable. While we did split it up 50/50 on the work we did, there was a split in what stage of the progress we were on which led to inconsistencies. For example, implementations of for/for each were done through pretty printer while arrays were still not done yet. This led to some confusion on design choices and thus a lot of debugging.

We still currently have issues with compiling the build due to linker issues that we were unable to resolve at the time. If we were able to compile the project, we would have the full design of the SIP AST extension down plus the pretty print testing. Some miscommunication in the AST node testing led it to have too many errors, so it was excluded from the overall test suite. 

Since we were unfortunately unable to creating a working AST test suite and compile it from build, we are unable to completly show our work. There is still a significant amount of code that was made through the process and we were happy with what we could do.
