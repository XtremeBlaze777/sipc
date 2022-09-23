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
that the approach is successful. Some trickier operator precedences like ternary operator inside a ternary operator were finnicky and we had to ensure that testing was working for it. Ternary operators specifically revealed that we had to ensure we were following the proper associativity rules, as they are Right-to-left associative. We always used the C operator precedence guide throughout the assignment to make sure the ordering of our expressions were similar to C's. To validate that the parsing was working, we made test cases for every new addition to ensure everything is working. Testing also revealed that, at the moment, Boolean true/false could not be left as keywords. Placing a semicolon after true/false (such as in an assignment), would cause the parser to not register it as a keyword and thus we failed our test cases. This was corrected by defining Boolean with the string literals of 'true' and 'false', rather than as keywords.

## Testing Approach
For our approach in testing, we made sure that each of the new additions to the sipc language were parsable by the parser.
To do so, we created a separate unit test for each of the new operations we added and experimented with all possible variations of parsing 
expressions. 

For testing operator precedence, we decided to only create unit tests that will check the operator with higher precedence and operator with lower
precedence of each of the new operators. This is because all of the other TIP operators that exist have already been 100% tested in TIP, so we just 
need to verify that it is valid for the its neighboring operators to be good. We initially thought between that and having test cases between all TIPC expressions, but that was not necessary since TIPC was already ordered properly and SIPC extensions just had to be tested with adjacent expressions in the TIP.g4 file. In the end, we decided with the first approach we talked about.

There were also specific cases that we had to test to ensure parsing was working correctly, like ternary operator in ternary operator. We had to make surethose cases were working with unique assertions in their respective test cases. When implementing the new SIP additions, some test cases in TIP would fail because of additions of "<=" which did not exist previously. We replaced that with new invalid expressions such as "<==" and "===" so that the TIP cases are still functioning properly.

