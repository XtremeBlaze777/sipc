#include "TypeConstraintCollectVisitor.h"
#include "ASTHelper.h"
#include "SymbolTable.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <sstream>
#include <set>

static void diff(std::stringstream &program, std::vector<std::string> constraints) {
    auto ast = ASTHelper::build_ast(program);
    auto symbols = SymbolTable::build(ast.get());

    TypeConstraintCollectVisitor visitor(symbols.get());
    ast->accept(&visitor);

    auto collected = visitor.getCollectedConstraints();

    // Copy the vectors to sets to allow for a single equality test
    std::set<std::string> expectedSet;
    copy(constraints.begin(), constraints.end(), 
            inserter(expectedSet, expectedSet.end()));    

    std::set<std::string> collectedSet;
    for(int i = 0; i < collected.size(); i++) {
        std::stringstream stream;
        stream << collected.at(i);
        collectedSet.insert(stream.str());
    }

    std::set<std::string> result;
    std::set_difference(collectedSet.begin(), collectedSet.end(), expectedSet.begin(), expectedSet.end(),
            std::inserter(result, result.end()));
    std::cout << "Program has that expected doesn't:" << std::endl;
    for ( auto &s : result ) {
        std::cout << s << std::endl;
    }
    std::set<std::string> result2;
    std::set_difference(expectedSet.begin(), expectedSet.end(), collectedSet.begin(), collectedSet.end(), 
            std::inserter(result2, result2.end()));
    std::cout << "\nExpected has that prog doesn't:" << std::endl;
    for ( auto &s : result2 ) {
        std::cout << s << std::endl;
    }
}

static void runtest(std::stringstream &program, std::vector<std::string> constraints) {
    auto ast = ASTHelper::build_ast(program);
    auto symbols = SymbolTable::build(ast.get());

    TypeConstraintCollectVisitor visitor(symbols.get());
    ast->accept(&visitor);
    auto collected = visitor.getCollectedConstraints();

    // Copy the vectors to sets to allow for a single equality test
    std::set<std::string> expectedSet;
    copy(constraints.begin(), constraints.end(), 
         inserter(expectedSet, expectedSet.end()));    

    std::set<std::string> collectedSet;
    for(int i = 0; i < collected.size(); i++) {
        std::stringstream stream;
        stream << collected.at(i);
        collectedSet.insert(stream.str());
    }
   
    REQUIRE(expectedSet == collectedSet);
}

TEST_CASE("TypeConstraintVisitor: Boolean", "[TypeConstraintVisitor]") {
  std::stringstream program;
  program << R"(
    main() {
      var t,f,check;
      t = true;
      f = false;
      check = (t==f);
      return 0;
    }
  )";

  std::vector<std::string> expected {
      "\u27E6(t==f)@6:15\u27E7 = bool",
      "\u27E60@7:13\u27E7 = int",
      "\u27E6check@3:14\u27E7 = \u27E6(t==f)@6:15\u27E7",
      "\u27E6f@3:12\u27E7 = \u27E6false@5:10\u27E7",
      "\u27E6false@5:10\u27E7 = bool",
      "\u27E6main@2:4\u27E7 = () -> \u27E60@7:13\u27E7",
      "\u27E6t@3:10\u27E7 = \u27E6f@3:12\u27E7",
      "\u27E6t@3:10\u27E7 = \u27E6true@4:10\u27E7",
      "\u27E6true@4:10\u27E7 = bool"
  };
  runtest(program, expected);
}

TEST_CASE("TypeConstraintVisitor: Ternary", "[TypeConstructorVisitor]") {
  std::stringstream program;
  program << R"(
    main() {
      var x,y,z;
      x = true?0:1;
      y = false?0:1;
      z = x==y;
      return 0;
    }
  )";


  std::vector<std::string> expected {
      "\u27E6(x==y)@6:10\u27E7 = bool",
      "\u27E60@4:15\u27E7 = int",
      "\u27E60@4:15\u27E7 = \u27E61@4:17\u27E7",
      "\u27E60@5:16\u27E7 = int",
      "\u27E60@5:16\u27E7 = \u27E61@5:18\u27E7",
      "\u27E60@7:13\u27E7 = int",
      "\u27E61@4:17\u27E7 = int",
      "\u27E61@5:18\u27E7 = int",
      "\u27E6false@5:10\u27E7 = bool",
      "\u27E6main@2:4\u27E7 = () -> \u27E60@7:13\u27E7",
      "\u27E6true@4:10\u27E7 = bool",
      "\u27E6x@3:10\u27E7 = \u27E6true ? 0 : 1@4:10\u27E7",
      "\u27E6x@3:10\u27E7 = \u27E6y@3:12\u27E7",
      "\u27E6y@3:12\u27E7 = \u27E6false ? 0 : 1@5:10\u27E7",
      "\u27E6z@3:14\u27E7 = \u27E6(x==y)@6:10\u27E7"
  };
  runtest(program, expected);
}

TEST_CASE("TypeConstraintVisitor: Arrays", "[TypeConstraintVisitor") {
  std::stringstream program;
  program << R"(
    main() {
      var x,y;
      x = [1,2];
      y = [x[1] of #x];
      return 0;
    }
  )";

  std::vector<std::string> expected {
      "\u27E6#x@5:19\u27E7 = int",
      "\u27E60@6:13\u27E7 = int",
      "\u27E61@4:11\u27E7 = int",
      "\u27E61@4:11\u27E7 = \u27E61@4:11\u27E7",
      "\u27E61@4:11\u27E7 = \u27E62@4:13\u27E7",
      "\u27E61@5:13\u27E7 = int",
      "\u27E62@4:13\u27E7 = int",
      "\u27E6[1, 2]@4:10\u27E7 = arr::\u27E61@4:11\u27E7",
      "\u27E6[x[1] of #x]@5:10\u27E7 = arr::\u27E6#x@5:19\u27E7",
      "\u27E6main@2:4\u27E7 = () -> \u27E60@6:13\u27E7",
      "\u27E6x@3:10\u27E7 = arr::\u03b1<x>",
      "\u27E6x@3:10\u27E7 = arr::\u27E6x[1]@5:11\u27E7",
      "\u27E6x@3:10\u27E7 = \u27E6[1, 2]@4:10\u27E7",
      "\u27E6x[1]@5:11\u27E7 = int",
      "\u27E6y@3:12\u27E7 = \u27E6[x[1] of #x]@5:10\u27E7"
  };
  runtest(program, expected);
}

TEST_CASE("TypeConstraintVisitor: Binary_UnaryExpr", "[TypeConstraintVisitor]") {
  std::stringstream program;
  program << R"(
    main() {
      var a,o,n, m;
      a = (5 < 2) and (-2 <= 7);
      o = (0 >= 0) or (a);
      n = not (o);
      m = -6 % 4;
      m++;
      m--;
      return 0;
    }
  )";

  std::vector<std::string> expected = {
    "\u27E6((0>=0) or a)@5:10\u27E7 = bool",
    "\u27E6((5<2) and (-2<=7))@4:10\u27E7 = bool",
    "\u27E6(-2<=7)@4:23\u27E7 = bool",
    "\u27E6(-6%4)@7:10\u27E7 = int",
    "\u27E6(0>=0)@5:11\u27E7 = bool",
    "\u27E6(5<2)@4:11\u27E7 = bool",
    "\u27E6-2@4:23\u27E7 = int",
    "\u27E6-6@7:10\u27E7 = int",
    "\u27E60@10:13\u27E7 = int",
    "\u27E60@5:11\u27E7 = int",
    "\u27E60@5:16\u27E7 = int",
    "\u27E62@4:15\u27E7 = int",
    "\u27E64@7:15\u27E7 = int",
    "\u27E65@4:11\u27E7 = int",
    "\u27E67@4:29\u27E7 = int",
    "\u27E6a@3:10\u27E7 = bool",
    "\u27E6a@3:10\u27E7 = \u27E6((5<2) and (-2<=7))@4:10\u27E7",
    "\u27E6m++@8:6\u27E7 = int",
    "\u27E6m--@9:6\u27E7 = int",
    "\u27E6m@3:17\u27E7 = int",
    "\u27E6m@3:17\u27E7 = \u27E6(-6%4)@7:10\u27E7",
    "\u27E6main@2:4\u27E7 = () -> \u27E60@10:13\u27E7",
    "\u27E6n@3:14\u27E7 = \u27E6not o@6:10\u27E7",
    "\u27E6not o@6:10\u27E7 = bool",

    "\u27E6o@3:12\u27E7 = bool",
    "\u27E6o@3:12\u27E7 = \u27E6((0>=0) or a)@5:10\u27E7" 
  };
  runtest(program, expected);
}

TEST_CASE("TypeConstraintVisitor: ForLoops", "[TypeConstraintVisitor]") {
  std::stringstream program;
  program << R"(
    main() {
      var i,j,k;
      for (i : [5]) output i;
      for (j : 0 .. 5 by 2) output j;
      for (k : 0 .. 5) output k;
      return 0;
    }
  )";

  std::vector<std::string> expected = {
      "\u27E60@5:15\u27E7 = int",
      "\u27E60@6:15\u27E7 = int",
      "\u27E60@7:13\u27E7 = int",
      "\u27E62@5:25\u27E7 = int",
      "\u27E65@4:16\u27E7 = int",
      "\u27E65@4:16\u27E7 = \u27E65@4:16\u27E7",
      "\u27E65@5:20\u27E7 = int",
      "\u27E65@6:20\u27E7 = int",
      "\u27E6[5]@4:15\u27E7 = arr::\u27E65@4:16\u27E7",
      "\u27E6[5]@4:15\u27E7 = arr::\u27E6[5]@4:15\u27E7",
      "\u27E6i@3:10\u27E7 = int",
      "\u27E6i@3:10\u27E7 = \u03b1<i>",
      "\u27E6j@3:12\u27E7 = int",
      "\u27E6k@3:14\u27E7 = int",
      "\u27E6main@2:4\u27E7 = () -> \u27E60@7:13\u27E7"
  };
  runtest(program, expected);
}