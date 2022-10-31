#include "ASTHelper.h"
#include "GeneralHelper.h"
#include "PrettyPrinter.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("SIPPrettyPrinter: Unary Expressions", "[SIPPrettyPrinter]") {
    std::stringstream stream;
    stream << R"(
      unary() {
        var x, y, z;
        x = true;
        y = not true;
        z = not x;
        x = [0, 1, 2, 3];
        y = #x;
        return x;
      }
    )";
    
    std::string expect = R"(unary()
{
  var x, y, z;
  x = true;
  y = not true;
  z = not x;
  x = [0, 1, 2, 3];
  y = #x;
  return x;
}
)";

    std::stringstream pp;
    auto ast = ASTHelper::build_ast(stream);
    PrettyPrinter::print(ast.get(), pp, ' ', 2);
    std::string ppString = GeneralHelper::removeTrailingWhitespace(pp.str());
    std::string expected = GeneralHelper::removeTrailingWhitespace(expect);
    REQUIRE(ppString == expected);
}

TEST_CASE("SIPPrettyPrinter: Ternary Expressions", "[SIPPrettyPrinter]") {
    std::stringstream stream;
    stream << R"(
    ternary() {
      var x, y;
      y = 1;
      x = y ? 1 : 0;
      return x;
    }
    )";

    std::string expect = R"(ternary()
{
  var x, y;
  y = 1;
  x = (y ? 1 : 0);
  return x;
}
)";

    std::stringstream pp;
    auto ast = ASTHelper::build_ast(stream);
    PrettyPrinter::print(ast.get(), pp, ' ', 2);
    std::string ppString = GeneralHelper::removeTrailingWhitespace(pp.str());
    std::string expected = GeneralHelper::removeTrailingWhitespace(expect);
    REQUIRE(ppString == expected);
}



TEST_CASE("SIPPrettyPrinter: Inc/Dec Statements", "[SIPPrettyPrinter]") {
    std::stringstream stream;
    stream << R"(
    incdec() {
      var x;
      x++;
      x--;
      return x;
    }
    )";

    std::string expect = R"(incdec()
{
  var x;
  x++;
  x--;
  return x;
}
)";

    std::stringstream pp;
    auto ast = ASTHelper::build_ast(stream);
    PrettyPrinter::print(ast.get(), pp, ' ', 2);
    std::string ppString = GeneralHelper::removeTrailingWhitespace(pp.str());
    std::string expected = GeneralHelper::removeTrailingWhitespace(expect);
    REQUIRE(ppString == expected);
}

TEST_CASE("SIPPrettyPrinter: Arrays", "[SIPPrettyPrinter]") {
    std::stringstream stream;
    stream << R"(
    mainarray() {
      var x;
      x = [0, 1, 2, 3];
      x = [];
      x = [5, 6, 7, 8, 9, 10];
      x = [10 of 5];
      x = [0 of 4];
      return x;
    }
    )";

    std::string expect = R"(mainarray()
{
  var x;
  x = [0, 1, 2, 3];
  x = [];
  x = [5, 6, 7, 8, 9, 10];
  x = [10 of 5];
  x = [0 of 4];
  return x;
}
)";

    std::stringstream pp;
    auto ast = ASTHelper::build_ast(stream);
    PrettyPrinter::print(ast.get(), pp, ' ', 2);
    std::string ppString = GeneralHelper::removeTrailingWhitespace(pp.str());
    std::string expected = GeneralHelper::removeTrailingWhitespace(expect);
    REQUIRE(ppString == expected);
}


TEST_CASE("SIPPrettyPrinter: Boolean Expressions", "[SIPPrettyPrinter]") {
    std::stringstream stream;
    stream << R"(
    boolean() {
      var x, y, z;
      x = true;
      y = false;
      z = x or y;
      x = y and z;
      y = not x and z;
      z = not not x;
      return x;
    }
    )";

    std::string expect = R"(boolean()
{
  var x, y, z;
  x = true;
  y = false;
  z = (x or y);
  x = (y and z);
  y = (not x and z);
  z = not not x;
  return x;
}
)";

    std::stringstream pp;
    auto ast = ASTHelper::build_ast(stream);
    PrettyPrinter::print(ast.get(), pp, ' ', 2);
    std::string ppString = GeneralHelper::removeTrailingWhitespace(pp.str());
    std::string expected = GeneralHelper::removeTrailingWhitespace(expect);
    REQUIRE(ppString == expected);
}


TEST_CASE("SIPPrettyPrinter: For Statements", "[SIPPrettyPrinter]") {
    std::stringstream stream;
    stream << R"(
    test() {
      var x, y, z;
      x = 1;
      y = 1;
      for (0 : 0 .. 4) {
        x = x + y;
      }
      for (0 : 0 .. 4 by 2) {
        y = x + y; 
      }
      z = [0, 1, 2, 3];
      for (elem : z) {
        x = x + elem; 
      }
      return x;
    }
    )";

    std::string expect = R"(test()
{
  var x, y, z;
  x = 1;
  y = 1;
  for (0 : 0 .. 4 by 1) 
    {
      x = (x + y);
    }
  for (0 : 0 .. 4 by 2) 
    {
      y = (x + y);
    }
  z = [0, 1, 2, 3];
  for (elem : z) 
    {
      x = (x + elem);
    }
  return x;
}
)";

    std::stringstream pp;
    auto ast = ASTHelper::build_ast(stream);
    PrettyPrinter::print(ast.get(), pp, ' ', 2);
    std::string ppString = GeneralHelper::removeTrailingWhitespace(pp.str());
    std::string expected = GeneralHelper::removeTrailingWhitespace(expect);
    REQUIRE(ppString == expected);
}
