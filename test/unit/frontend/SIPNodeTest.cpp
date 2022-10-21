#include "ParserHelper.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ExceptionContainsWhat.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("ASTNodeTest: ASTForEach", "[ASTNode]") {
    auto elem = std::make_unique<ASTVariableExpr>("A");
    auto elemValue = elem.get();
    auto arrBody = std::make_unique<ASTVariableExpr>("B");
    auto arrValue = arrBody.get();
    auto out = std::make_unique<ASTVariableExpr>("C");
    auto condBody = std::make_unique<ASTVariableExpr>(std::move(out));
    auto condValue = cond.get();

    auto for_each = std::make_unique<ASTForEachStmt>(std::move(elem), std::move(arrBody),
                                            std::move(condBody));

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
    std::string expected[] = { "A", "B", "C", ,"output C;","for (A : B) output C;" };
    for (int i=0; i < 5; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: ASTFor", "[ASTNode]") {
    auto start = std::make_unique<ASTVariableExpr>("A");
    auto end = std::make_unique<ASTVariableExpr>("B");
    auto begin = std::make_unique<ASTVariableExpr>("C");
    auto out = std::make_unique<ASTVariableExpr>("D");
    auto stmt = std::make_unique<ASTOuputStmt>(std::move(Var2));
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
    REQUIRE(stmtValue == ForRange->getBody());

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
    std::string exprs[] = ["A", "B", "C"]
    for (auto e : exprs) {
        auto foo = std::make_unique<ASTVariableExpr>(e);
        elements.push_back( foo; );
        vals.push_back(foo.get());
    }

    arr = std::make_unique<ASTMainArray>( std::move(elements) );

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *arr;
    REQUIRE(nodePrintStream.str() == "[A, B, C];");

    auto children = arr->getChildren();
    REQUIRE(children.size() == 3);

    auto gotten = arr->getElements;

    for (int i = 0; i < children.size(); i++) {
        auto foo = vals.get(i);

        // Test getters
        REQUIRE(foo == gotten.get(i));

        // Test getChildren
        REQUIRE(contains(children, foo));
    }

    // Test accept
    RecordPostPrint visitor;
    arr->accept(&visitor);
    std::string expected[] = { "A", "B", "C", "[A, B, C];" };
    for (int i=0; i < 4; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: AlternateArray_ArrLen", "[ASTNode]") {
    auto start = std::make_unique<ASTVariableExpr>("A");
    auto startValue = start.get();
    auto end = std::make_unique<ASTVariableExpr>("B");
    auto endValue = end.get();
    std::string name = arr;

    auto arr = std::make_unique<ASTAlternateArray>( name, std::move(start), std::move(end) );
    auto len = std::make_unique<UnaryExpr>("#", std::move(arr));
    auto lenValue = arr.get();

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *arr;
    REQUIRE(nodePrintStream.str() == "[A of B];");
    std::stringstream nodePrintStream2;
    nodePrintStream2 << *len;
    REQUIRE(nodePrintStream2.str() == "#arr;");

    // Test getters 
    REQUIRE(startValue == arr->getStart());
    REQUIRE(endValue == arr->getEnd());
    REQUIRE(lenValue == len->getRight());

    // Test getChildren
    auto children = arr->getChildren();
    REQUIRE(children.size() == 2);
    REQUIRE(contains(children, startValue));
    REQUIRE(contains(children, endValue));

    auto children2 = arr->getChildren();
    REQUIRE(children2.size() == 1);
    REQUIRE(contains(children2, lenValue));


    // Test accept
    RecordPostPrint visitor;
    arr->accept(&visitor);
    std::string expected[] = { "A", "B", "[A of B];", "#arr;" };
    for (int i=0; i < 4; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
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

TEST_CASE("ASTNodeTest: IncStmt", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto inc = std::make_unique<ASTIncDecStmt>(std::move(a), "--");

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *inc;
    REQUIRE(nodePrintStream.str() == "A--;");

    // Test getters 
    REQUIRE(aVal == inc->getExpr());

    // Test getChildren
    auto children = inc->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    inc->accept(&visitor);
    std::string expected[] = { "A", "A--;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: ArithmeticNeg", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto inc = std::make_unique<ASTUnaryExp>("-", std::move(a));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *inc;
    REQUIRE(nodePrintStream.str() == "-A;");

    // Test getters 
    REQUIRE(aVal == inc->getExpr());

    // Test getChildren
    auto children = inc->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    inc->accept(&visitor);
    std::string expected[] = { "A", "-A;"};
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: UnaryNeg", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();

    auto inc = std::make_unique<ASTUnaryExp>("not", std::move(a));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *inc;
    REQUIRE(nodePrintStream.str() == "not A;");

    // Test getters 
    REQUIRE(aVal == inc->getExpr());

    // Test getChildren
    auto children = inc->getChildren();
    REQUIRE(children.size() == 1);
    REQUIRE(contains(children, aVal));


    // Test accept
    RecordPostPrint visitor;
    inc->accept(&visitor);
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

    auto mod = std::make_unique<ASTBinaryExp>("%", std::move(a), std::move(b));

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
    inc->accept(&visitor);
    std::string expected[] = { "A", "B", "A % B;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: Modulo", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();
    auto b = std::make_unique<ASTVariableExpr>("B");
    auto bVal = b.get();

    auto mod = std::make_unique<ASTBinaryExp>("and", std::move(a), std::move(b));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *mod;
    REQUIRE(nodePrintStream.str() == "A and B;");

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
    inc->accept(&visitor);
    std::string expected[] = { "A", "B", "A and B;" };
    for (int i=0; i < 2; i++) {
        REQUIRE(visitor.postPrintStrings[i] == expected[i]);
    }
}

TEST_CASE("ASTNodeTest: Modulo", "[ASTNode]") {
    auto a = std::make_unique<ASTVariableExpr>("A");
    auto aVal = a.get();
    auto b = std::make_unique<ASTVariableExpr>("B");
    auto bVal = b.get();

    auto mod = std::make_unique<ASTBinaryExp>("or", std::move(a), std::move(b));

    // Test Print Method
    std::stringstream nodePrintStream;
    nodePrintStream << *mod;
    REQUIRE(nodePrintStream.str() == "A or B;");

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
    inc->accept(&visitor);
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