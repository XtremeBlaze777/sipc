#include "ParserHelper.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ExceptionContainsWhat.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("SIP Parser: boolean", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      boolean() {
        var x, y, z;
        x = true;
        y = false;
        z = true;
        return z;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: modulo", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      modulo() {
        var x, y;
        x = 42;
        y = x % 7;
        x = 35 % 5;
        x = 37 % 5;
        x = x % y;
        y = y % x;
        y = (y % x) % 1;
        y = (y % x) % 33;
        y = 33 % (x % y);
        return y;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("SIP Parser: negation", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      negation() {
        var x, y, z;
        x = 42;
        y = -x;
        y = -(-x);
        x = -(y - (-y));
        z = -(-(-x) - (-y));

        return y;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("SIP Parser: relational operator extension", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      cmp() {
        var x, y, z;
        x = 5;
        y = 4;
        z = 4;
        if (y >= z) {
            x = 6;
        }
        if (x < (y+z)) {
            y = 7;
        }
        if (x < y) {
            z = 6;
        }
        if ((x+y) <= z) {
            x = 420;
        }
        return x;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("SIP Parser: ternary operator", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      ternary() {
        var w, x, y, z;
        x = true;
        y = false;
        z = 4;
        w = x ? z : y;
        x = 5;
        y = 4;
        z = 4;
        w = (y == z) ? x : y;
        w = (y == z) ? (x >= 4) : (y < 6);
        return w;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("SIP Parser: inc/dec statements", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      incdec() {
        var x;
        x = 5;
        x++;
        x++;
        x++;
        x--;
        x--;
        x--;
        return x;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("SIP Parser: arrays", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      arrtest() {
        var x, y, z;
        var r, s, t;
        x = [1, 2, 3, 4, 5];
        y = [10 of 5];
        z = [];
        r = x[0];
        s = y[4];
        t = s - r;
        t = #x;
        return s;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("SIP Parser: for loops", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(
      arrtest() {
        var x, y, z;
        x = [1, 2, 3, 4, 5];
        y = 0;
        for (e : x) {
            y = e;
        }
        for (0 : 0 .. 4) {
            y = e;
        }
        for (0 : 0 .. 4 by 2) {
            y = e;
        }
        for (1 : 0 .. 4 by 3) {
            y = e;
        }
        y = 0;
        for (y : 0 .. 4) {
            x[y] = y;
        }
        return y;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: arr len precedence test", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(main() {var p; p = [1 of 2]; return #p;})";
    std::string expected = "(expr # p)";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() {var p; p = [1, 2]; return #p;})";
    expected = "(expr # p)";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos);
}


TEST_CASE("SIP Parser: modulo precedence test", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(main() { return not -5 % 3;})";
    std::string expected = "(expr (expr not (expr - 5)) % (expr 3))";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() { return 5 - 3 % 3;})";
    expected = "(expr (expr 5) - (expr (expr 3) % (expr 3)))";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos);
}

TEST_CASE("SIP Parser: unary negation precedence test", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(main() { return -1 * 2;})";
    std::string expected = "(expr (expr - 1) * (expr 2))";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() { var p; &p = 1; return -&p;})";
    expected = "(expr - (expr & (expr p)))";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos);
}


TEST_CASE("SIP Parser: relational operator precedence test", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(main() { return 2 * 2 >= 3;})";
    std::string expected = "(expr (expr (expr 2) * (expr 2)) >= (expr 3))";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() { return 3 + 2 <= 3;})";
    expected = "(expr (expr (expr 3) + (expr 2)) <= (expr 3))";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos);
    stream.str("");
    stream << R"(main() { return 3 + 2 < 3;})";
    expected = "(expr (expr (expr 3) + (expr 2)) < (expr 3))";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos);
}

TEST_CASE("SIP Parser: ternary operator precedence test", "[SIP Parser]") {
    std::stringstream stream;
    stream << R"(main() {return a ? b : c ? d : e;})";
    std::string expected = "(expr (expr a) ? (expr b) : (expr (expr c) ? (expr d) : (expr e)))";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
}
