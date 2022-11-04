#include "TipInt.h"
#include "TipRef.h"
#include "TipArr.h"

#include <catch2/catch_test_macros.hpp>

#include <sstream>
#include <iostream>

TEST_CASE("TipArr: Test getters" "[TipArr]") {
    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArr(intType);
    auto elems = tipArr.getElements();

    REQUIRE(elems.size() == 1);
    REQUIRE(dynamic_cast<const TipInt>(elems));
}

TEST_CASE("TipArr: Test equality" "[TipArr]") {
    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArrA(intType);
    auto elemsA = tipArrA.getElements();

    SECTION("Equal when fields are of same type and length") {
        std::shared_ptr<TipInt> Type = std::make_shared<TipInt>();
        TipArr tipArrB(Type);
        auto elemsB = tipArrB.getElements();

        REQUIRE(tipArrA == tipArrB);
        REQUIRE(elemsA.size() == elemsB.size());
    }

    SECTION("Not equal when arguments differ by type") {
        std::shared_ptr<TipType> Type = std::make_shared<TipInt>();
        TipArr tipArrB(Type);
        auto elemsB = tipArrB.getElements();

        REQUIRE(tipArrA != tipArrB);
    }

    SECTION("Not equal when argument types differ") {
        TipInt tipInt;

        REQUIRE(tipArrA != tipInt);
    }
}

TEST_CASE("TipArr: Test output stream" "[TipArr]") {
    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArr(intType);
    auto elems = tipArr.getElements();

    auto expectedValue = "arr::int";
    std::stringstream stream;
    stream << tipArr;
    std::string actualValue = stream.str();

    REQUIRE(expectedValue == actualValue);
}
