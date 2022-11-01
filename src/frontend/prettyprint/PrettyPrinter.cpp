#
#include "PrettyPrinter.h"

#include <iostream>
#include <sstream>

void PrettyPrinter::print(ASTProgram *p, std::ostream &os, char c, int n) {
    PrettyPrinter visitor(os, c, n);
    p->accept(&visitor);
}

/**
 * join last sz items from the visitedResults with delimiter delim. Then, remove these items from the stack
 * 
 * the delimiter before the last skip items are not appended (e.g. to not add trailing commas) 
 * 
 * returns the joined string
 */
std::string joinWithDelim(std::vector<std::string>& visitResults, std::string delim, int sz, int skip) {
    std::string out;
    int i;
    for (i = visitResults.size() - sz; i < visitResults.size() - skip; i++) {
        out += visitResults[i];
        out += delim;
    }
    // skip the delimiter for the last several tokens
    for (; i < visitResults.size(); i++)
        out += visitResults[i];
    visitResults.erase(visitResults.begin() + visitResults.size() - sz, visitResults.end());
    return out;
}

void PrettyPrinter::endVisit(ASTProgram * element) {
    os << joinWithDelim(visitResults, "\n", element->getFunctions().size(), 1);
    os.flush();
}

/*
 * General approach taken by visit methods.
 * - visit() is used to increase indentation (decrease should happen in endVisit).  
 * - endVisit() should expect a string for all of its AST nodes in reverse order in visitResults.
 *   Communicate the single string for the visited node by pushing to the back of visitedResults.
 */

/* 
 * Before visiting function, record string for signature and setup indentation for body.
 * This visit method pushes a string result, that the endVisit method should extend.
 */
bool PrettyPrinter::visit(ASTFunction * element) {
    indentLevel++;
    return true;
}

/*
 * After visiting function, collect the string representations for the:
 *   statements, declarations, formals, and then function name
 * they are on the visit stack in that order.
 */
void PrettyPrinter::endVisit(ASTFunction * element) {
    auto bodyString = joinWithDelim(visitResults, "\n", element->getStmts().size(), 0);
    auto declString = joinWithDelim(visitResults, "\n", element->getDeclarations().size(), 0);
    auto formalsString = joinWithDelim(visitResults, ", ", element->getFormals().size(), 1);

    // function name is last element on stack
    // we modify it in place
    visitResults.back() += "(" + formalsString + ") \n{\n" + declString + bodyString + "}\n";
    indentLevel--;
}

void PrettyPrinter::endVisit(ASTNumberExpr * element) {
    visitResults.push_back(std::to_string(element->getValue()));
}

void PrettyPrinter::endVisit(ASTVariableExpr * element) {
    visitResults.push_back(element->getName());
}

void PrettyPrinter::endVisit(ASTBinaryExpr * element) {
    std::string rightString = visitResults.back();
    visitResults.pop_back();
    std::string leftString = visitResults.back();
    visitResults.pop_back();
    
    visitResults.push_back("(" + leftString + " " + element->getOp() + " " + rightString + ")");
}

void PrettyPrinter::endVisit(ASTInputExpr * element) {
    visitResults.push_back("input");
}

void PrettyPrinter::endVisit(ASTFunAppExpr * element) {
    auto actualsString = joinWithDelim(visitResults, ", ", element->getActuals().size(), 1);
    visitResults.back() += "(" + actualsString + ")";
}

void PrettyPrinter::endVisit(ASTAllocExpr * element) {
    std::string init = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back("alloc " + init);
}

void PrettyPrinter::endVisit(ASTRefExpr * element) {
    std::string var = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back("&" + var);
}

void PrettyPrinter::endVisit(ASTDeRefExpr * element) {
    std::string base = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back("*" + base);
}

void PrettyPrinter::endVisit(ASTNullExpr * element) {
    visitResults.push_back("null");
}

void PrettyPrinter::endVisit(ASTFieldExpr * element) {
    std::string init = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(element->getField() + ":" + init);
}

void PrettyPrinter::endVisit(ASTRecordExpr * element) {
    visitResults.push_back("{" + joinWithDelim(visitResults, ", ", element->getFields().size(), 1) + "}");
}

void PrettyPrinter::endVisit(ASTAccessExpr * element) {
    std::string accessString = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(accessString + '.' + element->getField());
}

void PrettyPrinter::endVisit(ASTDeclNode * element) {
    visitResults.push_back(element->getName());
}

void PrettyPrinter::endVisit(ASTDeclStmt * element) {
    visitResults.push_back(indent() + "var " + joinWithDelim(visitResults, ", ", element->getVars().size(), 1) + ";");
}

void PrettyPrinter::endVisit(ASTAssignStmt * element) {
    std::string rhsString = visitResults.back();
    visitResults.pop_back();
    std::string lhsString = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(indent() + lhsString + " = " + rhsString + ";");
}

bool PrettyPrinter::visit(ASTBlockStmt * element) {
    indentLevel++;
    return true;
}

void PrettyPrinter::endVisit(ASTBlockStmt * element) {
    indentLevel--;
    visitResults.push_back(indent() + "{\n" + joinWithDelim(visitResults, "\n", element->getStmts().size(), 0) + indent() + "}");
}

/*
 * For a while the body should be indented, but not the condition.
 * Since conditions are expressions and their visit methods never indent
 * incrementing here works.
 */
bool PrettyPrinter::visit(ASTWhileStmt * element) {
    indentLevel++;
    return true;
}

void PrettyPrinter::endVisit(ASTWhileStmt * element) {
    std::string bodyString = visitResults.back();
    visitResults.pop_back();
    std::string condString = visitResults.back();
    visitResults.pop_back();

    indentLevel--;

    std::string whileString = indent() + "while (" + condString + ") \n" + bodyString;
    visitResults.push_back(whileString);
}

bool PrettyPrinter::visit(ASTIfStmt * element) {
    indentLevel++;
    return true;
}

void PrettyPrinter::endVisit(ASTIfStmt * element) {
    std::string elseString;
    if (element->getElse() != nullptr) {
        elseString = visitResults.back();
        visitResults.pop_back();
    }

    std::string thenString = visitResults.back();
    visitResults.pop_back();

    std::string condString = visitResults.back();
    visitResults.pop_back();

    indentLevel--;

    std::string ifString = indent() + "if (" + condString + ") \n" + thenString;

    if (element->getElse() != nullptr) {
        ifString += "\n" + indent() + "else\n" + elseString;
    }

    visitResults.push_back(ifString);
}

void PrettyPrinter::endVisit(ASTOutputStmt * element) {
    std::string argString = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(indent() + "output " + argString + ";");
}

void PrettyPrinter::endVisit(ASTErrorStmt * element) {
    std::string argString = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(indent() + "error " + argString + ";");
}

void PrettyPrinter::endVisit(ASTReturnStmt * element) {
    std::string argString = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(indent() + "return " + argString + ";");
}

// SIP Extensions begin

void PrettyPrinter::endVisit(ASTUnaryExpr * element) {
    std::string varString = visitResults.back();
    visitResults.pop_back();
    if (element->getOp() == "not") {
        visitResults.push_back(element->getOp() + " " + varString);
    } else {
        visitResults.push_back(element->getOp() + varString);
    }
}

void PrettyPrinter::endVisit(ASTTernaryExpr * element) {
    std::string elseString = visitResults.back();
    visitResults.pop_back();
    std::string ifString = visitResults.back();
    visitResults.pop_back();
    std::string condString = visitResults.back();
    visitResults.pop_back();

    visitResults.push_back('(' + condString + " ? " + ifString + " : " + elseString + ')');
}

void PrettyPrinter::endVisit(ASTIncDecStmt * element) {
    std::string exprString = visitResults.back();
    visitResults.pop_back();
    visitResults.push_back(indent() + exprString + element->getOp() + ";");
}

void PrettyPrinter::endVisit(ASTMainArray * element) {
    std::vector<std::string> elements;
    int range = element->getChildren().size();

    for (int i = 0; i < range; i++) {
        std::string element = visitResults.back();
        visitResults.pop_back();
        elements.push_back(element);
    }
    reverse(elements.begin(), elements.end());
    int n = elements.size();
    std::string results = "[";
    for (int i = 0; i < n - 1; i++) {
        results += elements[i] + ", ";
    }
    if (elements.size() > 0) {
        results += elements[n-1];
    }
    results += "]";
    visitResults.push_back(results);
}

void PrettyPrinter::endVisit(ASTAlternateArray * element) {
    std::string endString = visitResults.back();
    visitResults.pop_back();
    std::string startString = visitResults.back();
    visitResults.pop_back();

    visitResults.push_back("[" + startString + " of " + endString + "]");
}

void PrettyPrinter::endVisit(ASTArrIndex * element) {
    std::string idxString = visitResults.back();
    visitResults.pop_back();
    std::string arrString = element->getArr();
    visitResults.push_back(arrString + "[" + idxString + "]");
}
bool PrettyPrinter::visit(ASTForEachStmt * element) {
    indentLevel++;
    return true;
}

bool PrettyPrinter::visit(ASTForStmt * element) {
    indentLevel++;
    return true;
}

void PrettyPrinter::endVisit(ASTForStmt * element) {
    std::string doString = visitResults.back();
    visitResults.pop_back();
    std::string stepString;
    if (element->getStep() != nullptr) {
        stepString = visitResults.back();
        visitResults.pop_back();
    } else {
        stepString = "1";
    }
    std::string endString = visitResults.back();
    visitResults.pop_back();
    std::string startString = visitResults.back();
    visitResults.pop_back();
    std::string elemString = visitResults.back();
    visitResults.pop_back();

    indentLevel--;
    visitResults.push_back(indent() + "for (" + elemString + " : " + startString + " .. " + endString + " by " + stepString + ") \n" + doString);
}

void PrettyPrinter::endVisit(ASTForEachStmt * element) {
    std::string doString = visitResults.back();
    visitResults.pop_back();
    std::string arrString = visitResults.back();
    visitResults.pop_back();
    std::string elemString = visitResults.back();
    visitResults.pop_back();

    indentLevel--;
    visitResults.push_back(indent() + "for (" + elemString + " : " + arrString + ") \n" + doString);
}

void PrettyPrinter::endVisit(ASTBoolExpr * element) {
    std::string boolVal = element->getValue();
    visitResults.push_back(boolVal); 
}

// SIP Extensions end

std::string PrettyPrinter::indent() const {
    return std::string(indentLevel*indentSize, indentChar);
}


