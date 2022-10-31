#include "ASTHelper.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("ASTPrinterTest: all unary expressions (excluding arr)", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y;
        x = -x;
        y = not true;
        y = [0, 1, 2, 3];
        x = #y;
        return x;
      }
    )";

    std::vector<std::string> expected {
      "x",
      "not true",
      "[0, 1, 2, 3]",
      "#y"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: new equality operators", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x;
        x = 5 >= 4;
        x = 4 < 5;
        x = 5 <= 5;
        return x;
      }
    )";

    std::vector<std::string> expected {
      "(5>=4)",
      "(4<5)",
      "(5<=5)"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: for iterative loops", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x;
        for (0 : 5 .. 1) {
            x = 5;
        }
        for (0 : 5 .. 1 by 2) {
            x = 4;
        }
        return x;
      }
    )";

    std::vector<std::string> expected {
      "for (0 : 5 .. 1) { x = 5; }",
      "for (0 : 5 .. 1 by 2) { x = 4; }",
      "return x;"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      stream = std::stringstream();
      stream << *s;
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: for each loops", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = [0, 1, 2, 3, 4];
        for (elem : x) {
            y = elem;
        }
        x = [10 of 5];
        for (elem : x) {
            z = elem;
        }
        return x;
      }
    )";

    std::vector<std::string> expected {
      "x = [0, 1, 2, 3, 4];",
      "for (elem : x) { y = elem; }",
      "x = [10 of 5];",
      "for (elem : x) { z = elem; }",
      "return x;"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      stream = std::stringstream();
      stream << *s;
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: inc/dec statements", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x;
        x = 1;
        x++;
        x--;
        return x;
      }
    )";

    std::vector<std::string> expected {
      "x = 1;",
      "x++",
      "x--",
      "return x;"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      stream = std::stringstream();
      stream << *s;
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: ternary expressions", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = 1;
        y = 0;
        z = x ? 3 : 2;
        z = y ? 5 : 4;
        return x;
        }
    )";

    std::vector<std::string> expected {
      "1",
      "0",
      "x ? 3 : 2",
      "y ? 5 : 4"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: main arrays", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x;
        x = [0, 1, 2, 3];
        x = [4, 5, 6, 7, 8];
        return x;
      }
    )";

    std::vector<std::string> expected {
      "[0, 1, 2, 3]",
      "[4, 5, 6, 7, 8]"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: alternative arrays", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x;
        x = [10 of 0];
        x = [10 of 1];
        x = [10 of 2];
        return x;
      }
    )";

    std::vector<std::string> expected {
      "[10 of 0]",
      "[10 of 1]",
      "[10 of 2]"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: modulo", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = 5;
        y = 4;
        z = x % y;
        z = y % x;
        x = y % z;
        return x;
      }
    )";

    std::vector<std::string> expected {
      "5",
      "4",
      "(x%y)",
      "(y%x)",
      "(y%z)"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: booleans", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = true;
        y = false;
        z = x or y;
        z = x and y;
        z = not (x or y);
        z = not not x;
        return z;
      }
    )";

    std::vector<std::string> expected {
      "true",
      "false",
      "(x or y)",
      "(x and y)",
      "not (x or y)",
      "not not x"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    // HELPER FUNCTION 
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}
