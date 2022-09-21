#include "ParserHelper.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ExceptionContainsWhat.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("TIP Parser: boolean", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      boolean() {
        var x, y, z;
        x = true;
        y = false;
        z = x or y;
        z = x and y;
        y = not y;
        z = x and y;
        z = not (not z);
        y = (not x) and (not z);
        z = (x or z) and y;
        return z;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("TIP Parser: modulo", "[TIP Parser]") {
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


TEST_CASE("TIP Parser: negation", "[TIP Parser]") {
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


TEST_CASE("TIP Parser: relational operator extension", "[TIP Parser]") {
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


TEST_CASE("TIP Parser: ternary operator", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      ternary() {
        var x, y, z;
        x = 5;
        y = 4;
        z = 4;
        (x == y) ? x = 3 : x = 4;
        (x == y) ? x = 5 : x = 6;
        (z != y) ? z = 17 : z = 33;
        return z;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("TIP Parser: inc/dec statements", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      incdec() {
        var x, y, z;
        x = 5;
        x++;
        x++;
        x++;
        x--;
        x--;
        x--;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("TIP Parser: arrays", "[TIP Parser]") {
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
        t = #z;
        s = #[1, 1, 1, 1, 1];
        return s;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}


TEST_CASE("TIP Parser: for loops", "[TIP Parser]") {
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


TEST_CASE("TIP Parser: arr len precedence test", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(main() { return #[1 of 2];})";
    std::string expected = "(expr # [(expr 1) of (expr 2)])";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() {return #[1, 2];})";
    expected = "(expr # [((expr 1), (expr 2))])";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected != std::string::npos);
}


TEST_CASE("TIP Parser: unary negation precedence test", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(main() { return -1 * 2;})";
    std::string expected = "(expr (not expr 1) * (expr 2))";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() var p; &p = 1; return -&p;})";
    expected = "(expr not (& (expr 1)))";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected != std::string::npos);
}


TEST_CASE("TIP Parser: relational operator precedence test", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(main() { return -1 * 2;})";
    std::string expected = "(expr (not expr 1) * (expr 2))";
    std::string tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected) != std::string::npos); 
    stream.str("");
    stream << R"(main() var p; &p = 1; return -&p;})";
    expected = "(expr not (& (expr 1)))";
    tree = ParserHelper::parsetree(stream);
    REQUIRE(tree.find(expected != std::string::npos);
}

