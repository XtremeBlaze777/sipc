#include "ASTHelper.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("ASTPrinterTest: all unary expressions (excluding arr)", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = -x;
        y = not true;
      }
    )";

    std::vector<std::string> expected {
      "-x",
      "not true"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
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
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
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
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
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
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
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
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
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
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
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
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: extra equality comparisons", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var w, x, y, z;
        w = 5;
        x = 4;
        y = 5;
        if (w >= x) {
            z = 1;
        }
        if (w < y) {
            z = 2;
        }
        if (w <= y) {
            z = 3;
        }
        z = w <= x;
        z = w < x;
        z = w >= x;
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}

TEST_CASE("ASTPrinterTest: modulo extension", "[ASTNodePrint]") {
 std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = 5;
        y = 4;
        z = x % y;
        z = y % x;
        x = y % z;
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
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
      }
    )";

    std::vector<std::string> expected {
      "for",
      "lol"
    };

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1;  // skip the return
    for (auto s : f->getStmts()) {
      auto a = dynamic_cast<ASTAssignStmt*>(s);
      stream = std::stringstream();
      stream << *a->getRHS();
      auto actual = stream.str();
      REQUIRE(actual == expected.at(i++));
      if (i == numStmts) break;
    } 
}