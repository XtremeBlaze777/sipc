#include "AST.h"
#include "ParserHelper.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ExceptionContainsWhat.h"
#include "ASTVisitor.h"

#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class RecordPostPrint : public ASTVisitor {
public:
    std::vector<std::string> postPrintStrings;
    void record(ASTNode * element) {
       std::stringstream s; s << *element; postPrintStrings.push_back(s.str()); 
    }
    void endVisit(ASTProgram * element) { record(element); }
    void endVisit(ASTFunction * element) { record(element); }
    void endVisit(ASTNumberExpr * element) { record(element); }
    void endVisit(ASTVariableExpr * element) { record(element); }
    void endVisit(ASTBinaryExpr * element) { record(element); }
    void endVisit(ASTInputExpr * element) { record(element); }
    void endVisit(ASTFunAppExpr * element) { record(element); }
    void endVisit(ASTAllocExpr * element) { record(element); }
    void endVisit(ASTRefExpr * element) { record(element); }
    void endVisit(ASTDeRefExpr * element) { record(element); }
    void endVisit(ASTNullExpr * element) { record(element); }
    void endVisit(ASTFieldExpr * element) { record(element); }
    void endVisit(ASTRecordExpr * element) { record(element); }
    void endVisit(ASTAccessExpr * element) { record(element); }
    void endVisit(ASTDeclNode * element) { record(element); }
    void endVisit(ASTDeclStmt * element) { record(element); }
    void endVisit(ASTAssignStmt * element) { record(element); }
    void endVisit(ASTWhileStmt * element) { record(element); }
    void endVisit(ASTIfStmt * element) { record(element); }
    void endVisit(ASTOutputStmt * element) { record(element); }
    void endVisit(ASTReturnStmt * element) { record(element); }
    void endVisit(ASTErrorStmt * element) { record(element); }
    void endVisit(ASTBlockStmt * element) { record(element); }
    // SIP Nodes
    void endVisit(ASTForStmt * element) { record(element); }
    void endVisit(ASTForEachStmt * element) { record(element); }
    void endVisit(ASTIncDecStmt * element) { record(element); }
    void endVisit(ASTUnaryExpr * element) { record(element); }
    void endVisit(ASTMainArray * element) { record(element); }
    void endVisit(ASTAlternateArray * element) { record(element); }
};

// Helper function that checks for raw node pointer in list
bool contains(std::vector<std::shared_ptr<ASTNode>> nodeList, ASTNode * nodeP) {
  bool found = false;
  for (auto & sharedNodeP : nodeList) {
    if (sharedNodeP.get() == nodeP) {
      found = true;
      break;
    }
  }
  return found;
}

TEST_CASE("ASTNodeTest: ASTForEach", "[ASTNode]") {
    auto elem = std::make_unique<ASTVariableExpr>("A");
    auto elemValue = elem.get();
    auto arrBody = std::make_unique<ASTVariableExpr>("B");
    auto arrValue = arrBody.get();
    auto out = std::make_unique<ASTVariableExpr>("C");
    auto condBody = std::make_unique<ASTOutputStmt>(std::move(out));
    auto condValue = condBody.get();

    auto for_each = std::make_unique<ASTForEachStmt>(std::move(elem), std::move(arrBody), std::move(condBody));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *for_each;
    REQUIRE(nodePrintStream.str() == "for (A : B) output C;");

        // Test getters 
    REQUIRE(elemValue == for_each->getElem());
    REQUIRE(arrValue == for_each->getArr());
    REQUIRE(condValue == for_each->getDo());

    // Test getChildren
    auto children = for_each->getChildren();
    REQUIRE(children.size() == 3);
    REQUIRE(contains(children, elemValue));
    REQUIRE(contains(children, arrValue));
    REQUIRE(contains(children, condValue));


    // Test accept
    RecordPostPrint visitor;
    for_each->accept(&visitor);
    std::string expected[] = { "A", "B", "C", "output C;","for (A : B) output C;" };
    for (int i=0; i < 5; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: ASTFor", "[ASTNode]") {
    auto start = std::make_unique<ASTVariableExpr>("A");
    auto end = std::make_unique<ASTVariableExpr>("B");
    auto begin = std::make_unique<ASTVariableExpr>("C");
    auto out = std::make_unique<ASTVariableExpr>("D");
    auto stmt = std::make_unique<ASTOutputStmt>(std::move(out));
    auto B = nullptr;
    // Record the raw pointers for these values because rhs and lhs will not be 
    // usable after the call to the constructor below.  This is because of the
    // move semantics associated with unique pointers, i.e., after the move the
    // locals rhs and lhs are nullptrs
    auto startValue = start.get();
    auto endValue = end.get();
    auto beginValue = begin.get();
    auto stmtValue = stmt.get();
    
    auto ForRange = std::make_unique<ASTForStmt>(std::move(start), std::move(end),std::move(begin), B, std::move(stmt));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *ForRange;
    REQUIRE(nodePrintStream.str() == "for (A : B .. C) output D;");

    // Test getters 
    REQUIRE(startValue == ForRange->getStart());
    REQUIRE(endValue == ForRange->getEnd());

    REQUIRE(beginValue == ForRange->getBegin());
    REQUIRE(stmtValue == ForRange->getDo());

    // Test getChildren
    auto children = ForRange->getChildren();
    REQUIRE(children.size() == 4);
    REQUIRE(contains(children, startValue));
    REQUIRE(contains(children, endValue));
    REQUIRE(contains(children, beginValue));
    REQUIRE(contains(children, stmtValue));


    // Test accept
    RecordPostPrint visitor;
    ForRange->accept(&visitor);
    std::string expected[] = { "A", "B", "C", "D","output D;","for (A : B .. C) output D;" };
    for (int i=0; i < 6; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: ASTMainArray", "[ASTNode]") {
    std::vector<std::unique_ptr<ASTExpr>> elements;
    std::vector<ASTExpr*> vals;
    std::string exprs[] = {"A", "B", "C"};
    for (auto e : exprs) {
        std::unique_ptr<ASTVariableExpr> foo = std::make_unique<ASTVariableExpr>(e);
        elements.push_back( std::move(foo) );
        vals.push_back(foo.get());
    }

    auto arr = std::make_unique<ASTMainArray>( std::move(elements) );

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *arr;
    REQUIRE(nodePrintStream.str() == "[A, B, C]");

    auto children = arr->getChildren();
    REQUIRE(children.size() == 3);

    std::vector<ASTExpr*> gotten = arr->getElements();

    for (int i = 0; i < vals.size(); i++) {
        auto foo = vals[i];

        std::cout << "value: " << foo << "\tgotten: " << gotten[i] << "\n\n";

        // Test getters
        REQUIRE(foo == gotten[i]);

        // Test getChildren
        REQUIRE(contains(children, foo));
    }

    // Test accept
    RecordPostPrint visitor;
    arr->accept(&visitor);
    std::string expected[] = { "A", "B", "C", "[A, B, C]" };
    for (int i=0; i < 4; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
    std::cout << "\n" << std::endl;
}

TEST_CASE("ASTNodeTest: ASTAssign", "[ASTNode]") {
  auto rhs = std::make_unique<ASTNumberExpr>(42);
  auto lhs = std::make_unique<ASTVariableExpr>("x");

  // Record the raw pointers for these values because rhs and lhs will not be 
  // usable after the call to the constructor below.  This is because of the
  // move semantics associated with unique pointers, i.e., after the move the
  // locals rhs and lhs are nullptrs
  auto rhsValue = rhs.get();
  auto lhsValue = lhs.get();

  auto assign = std::make_unique<ASTAssignStmt>(std::move(lhs), std::move(rhs));

  // Test Print Method
  std::stringstream nodePrintStream;
  nodePrintStream << *assign;
  REQUIRE(nodePrintStream.str() == "x = 42;");

  // Test getters 
  REQUIRE(rhsValue == assign->getRHS());
  REQUIRE(lhsValue == assign->getLHS());

  // Test getChildren
  auto children = assign->getChildren();
  REQUIRE(children.size() == 2);
  REQUIRE(contains(children, rhsValue));
  REQUIRE(contains(children, lhsValue));

  // Test accept
  RecordPostPrint visitor;
  assign->accept(&visitor);
  std::string expected[] = { "x", "42", "x = 42;" };
  for (int i=0; i < 3; i++) {
    REQUIRE(visitor.postPrintStrings[i] == expected[i]);
  }
}

TEST_CASE("ASTNodeTest: AlternateArray_ArrLen_ArrIndex", "[ASTNode]") {
    auto start = std::make_unique<ASTVariableExpr>("A");
    auto startValue = start.get();
    auto end = std::make_unique<ASTVariableExpr>("B");
    auto endValue = end.get();
    auto name = std::make_unique<ASTVariableExpr>("arr");
    auto nameValue = name.get();
    auto index = std::make_unique<ASTNumberExpr>(0);
    auto indexValue = index.get();

    //Debug
    std::cout << "expressions good\n\n";

    auto arr = std::make_unique<ASTAlternateArray>( std::move(start), std::move(end) );
    auto arrValue = arr.get();
    auto stmt = std::make_unique<ASTAssignStmt>( std::move(name), std::move(arr) );
    auto len = std::make_unique<ASTUnaryExpr>("#", std::move(name) );
    auto indexArr = std::make_unique<ASTArrIndex>( std::move(index), std::move(name) );
    
    //Debug
    std::cout << "statements good\n\n";

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *arr;
    REQUIRE(nodePrintStream.str() == "[A of B]");
    std::stringstream nodePrintStream2;
    nodePrintStream2 << *len;
    REQUIRE(nodePrintStream2.str() == "#arr");
    std::stringstream nodePrintStream3;
    nodePrintStream2 << *indexArr;
    REQUIRE(nodePrintStream3.str() == "arr[0]");
    
    //Debug
    std::cout << "printing good\n\n";

    // Test getters 
    REQUIRE(startValue == arr->getStart());
    REQUIRE(endValue == arr->getEnd());
    REQUIRE(nameValue == len->getRight());
    REQUIRE("#" == len->getOp());
    REQUIRE(nameValue == indexArr->getArr());
    REQUIRE(indexValue == indexArr->getIdx());
    
    //Debug
    std::cout << "getters good\n\n";

    // Test getChildren
    auto children = arr->getChildren();
    REQUIRE(children.size() == 2);
    REQUIRE(contains(children, startValue));
    REQUIRE(contains(children, endValue));

    auto children2 = len->getChildren();
    REQUIRE(children2.size() == 1);
    REQUIRE(contains(children2, arrValue));

    auto children3 = indexArr->getChildren();
    REQUIRE(children3.size() == 1);
    REQUIRE(contains(children3, indexValue));
    
    //Debug
    std::cout << "children good\n\n";

    // Test accept
    RecordPostPrint visitor, visitor2, visitor3;
    arr->accept(&visitor);
    len->accept(&visitor2);
    indexArr->accept(&visitor3);
    std::string arrExpected[] = { "A", "B", "[A of B]" };
    std::string lenExpected[] = { "#", "arr", "#arr" };
    std::string indexExpected[] = { "0", "arr", "arr[0]" };
    for (int i=0; i < 3; i++) {
        REQUIRE(visitor.postPrintStrings[i] == arrExpected[i]);
        REQUIRE(visitor2.postPrintStrings[i] == lenExpected[i]);
        REQUIRE(visitor3.postPrintStrings[i] == indexExpected[i]);
    }

    std::cout << "\n" << std::endl;
}

TEST_CASE("ASTNodeTest: BoolExpr", "[ASTNode]") {
    auto True = std::make_unique<ASTBoolExpr>("true");
    auto trueVal = True.get();
    auto False = std::make_unique<ASTBoolExpr>("false");
    auto falseVal = False.get();

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *True;
    REQUIRE(nodePrintStream.str() == "true");
    std::stringstream nodePrintStream2;
    nodePrintStream2 << *False;
    REQUIRE(nodePrintStream2.str() == "false");

    // Test getter
    REQUIRE(True->getValue() == "true");
    REQUIRE(False->getValue() == "false");

    // BoolExpr has no children! So no tests!

    // Test accept
    RecordPostPrint visitor, visitor2;
    True->accept(&visitor);
    False->accept(&visitor2);
    REQUIRE(visitor.PostPrintStrings[0] == "true");
    REQUIRE(visitor2.PostPrintStrings[0] == "false");

}

TEST_CASE("ASTNodeTest: IncStmt", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto inc = std::make_unique<ASTIncDecStmt>(std::move(a), "++");

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *inc;
    REQUIRE(nodePrintStream.str() == "A++;");

    // Test getters 
    REQUIRE(aVal == inc->getExpr());

    // Test getChildren
    auto children = inc->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    inc->accept(&visitor);
    std::string expected[] = { "A", "A++;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: DecStmt", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto dec = std::make_unique<ASTIncDecStmt>(std::move(a), "--");

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *dec;
    REQUIRE(nodePrintStream.str() == "A--;");

    // Test getters 
    REQUIRE(aVal == dec->getExpr());

    // Test getChildren
    auto children = dec->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    dec->accept(&visitor);
    std::string expected[] = { "A", "A--;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: ArithmeticNeg", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto neg = std::make_unique<ASTUnaryExpr>("-", std::move(a));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *neg;
    REQUIRE(nodePrintStream.str() == "-A;");

    // Test getters 
    REQUIRE(aVal == neg->getRight());

    // Test getChildren
    auto children = neg->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    neg->accept(&visitor);
    std::string expected[] = { "A", "-A;"};
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: UnaryNeg", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto notExpr = std::make_unique<ASTUnaryExpr>("not", std::move(a));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *notExpr;
    REQUIRE(nodePrintStream.str() == "not A;");

    // Test getters 
    REQUIRE(aVal == notExpr->getRight());

    // Test getChildren
    auto children = notExpr->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    notExpr->accept(&visitor);
    std::string expected[] = { "A", "not A;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: Modulo", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();
    auto b = std::make_unique<ASTVariableExpr>("B");
    auto bVal = b.get();

    auto mod = std::make_unique<ASTBinaryExpr>("%", std::move(a), std::move(b));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *mod;
    REQUIRE(nodePrintStream.str() == "A % B;");

    // Test getters 
    REQUIRE(aVal == mod->getLeft());
    REQUIRE(bVal == mod->getRight());

    // Test getChildren
    auto children = mod->getChildren();
    REQUIRE(children.size() == 2);
    REQUIRE(contains(children, aVal));
    REQUIRE(contains(children, bVal));


    // Test accept
    RecordPostPrint visitor;
    mod->accept(&visitor);
    std::string expected[] = { "A", "B", "A % B;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: And", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();
    auto b = std::make_unique<ASTVariableExpr>("B");
    auto bVal = b.get();

    auto andExpr = std::make_unique<ASTBinaryExpr>("and", std::move(a), std::move(b));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *andExpr;
    REQUIRE(nodePrintStream.str() == "A and B;");

    // Test getters 
    REQUIRE(aVal == andExpr->getLeft());
    REQUIRE(bVal == andExpr->getRight());

    // Test getChildren
    auto children = andExpr->getChildren();
    REQUIRE(children.size() == 2);
    REQUIRE(contains(children, aVal));
    REQUIRE(contains(children, bVal));


    // Test accept
    RecordPostPrint visitor;
    andExpr->accept(&visitor);
    std::string expected[] = { "A", "B", "A and B;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: Or", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();
    auto b = std::make_unique<ASTVariableExpr>("B");
    auto bVal = b.get();

    auto orExpr = std::make_unique<ASTBinaryExpr>("or", std::move(a), std::move(b));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *orExpr;
    REQUIRE(nodePrintStream.str() == "A or B;");

    // Test getters 
    REQUIRE(aVal == orExpr->getLeft());
    REQUIRE(bVal == orExpr->getRight());

    // Test getChildren
    auto children = orExpr->getChildren();
    REQUIRE(children.size() == 2);
    REQUIRE(contains(children, aVal));
    REQUIRE(contains(children, bVal));


    // Test accept
    RecordPostPrint visitor;
    orExpr->accept(&visitor);
    std::string expected[] = { "A", "B", "A or B;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}



TEST_CASE("ASTNodeTest: Ternary", "[ASTNode]") {
    auto cond = std::make_unique<ASTVariableExpr>("A");
    auto condVal = cond.get();
    auto then = std::make_unique<ASTVariableExpr>("B");
    auto thenVal = then.get();
    auto else_ = std::make_unique<ASTVariableExpr>("C");
    auto elseVal = else_.get();

    auto tern = std::make_unique<ASTTernaryExpr>( std::move(cond), std::move(then), std::move(else_) );;

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *tern;
    REQUIRE(nodePrintStream.str() == "A ? B : C;");

    // Test getters 
    REQUIRE(condVal == tern->getCond());
    REQUIRE(thenVal == tern->getIf());
    REQUIRE(elseVal == tern->getElse());

    // Test getChildren
    auto children = tern->getChildren();
    REQUIRE(children.size() == 3);
    REQUIRE(contains(children, condVal));
    REQUIRE(contains(children, thenVal));
    REQUIRE(contains(children, elseVal));


    // Test accept
    RecordPostPrint visitor;
    tern->accept(&visitor);
    std::string expected[] = { "A", "B", "C", "A ? B : C;" };
    for (int i=0; i < 4; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}
