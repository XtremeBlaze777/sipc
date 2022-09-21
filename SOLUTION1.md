## Deliverable 1: Extending the Parser

For this assignment, we were expected to extend the our TIP parser to include the following additions:
- Arrays, array referencing and array lengths
- Boolean operations (and, or, not, true, false)
- Ternary conditional expressions
- Additional arithmetic operators (% and -)
- Inc and dec statements
- Variations of for loops

## Challenges
The two biggest challenges of this assignment were how to define the operator precedence of our new operations and our approach to testing to validate
that the approach is successful.

TODO: Finish up challenges and other possible alternatives we had to take



## Testing Approach

For our approach in testing, we made sure that each of the new additions to the sipc language were parsable by the parser.
To do so, we created a separate unit test for each of the new operations we added and experimented with all possible variations of parsing 
expressions. 

For testing operator precedence, we decided to only create unit tests that will check the operator with higher precedence and operator with lower
precedence of each of the new operators. This is because all of the other TIP operators that exist have already been 100% tested in TIP, so we just 
need to verify that it is valid for the its neighboring operators to be good.

