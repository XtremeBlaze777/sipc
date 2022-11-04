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

/* TEST_CASE("TipArr: Test equality" "[TipArr]") {
    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArr(intType);
    auto elems = tipArr.getElements();

    std::shared_ptr<TipInt> Type = std::make_shared<TipInt>();
    TipArr tipArr(intType);
    auto elems = tipArr.getElements();

    SECTION("Equal when fields are of same type and length") {
        std::vector<std::shared_ptr<TipType>> initsB {
                std::make_shared<TipInt>(),
                std::make_shared<TipRef>(std::make_shared<TipInt>())
        };
        std::vector<std::string> namesB {"foo", "bar"};
        TipArr tipArrB(initsB, namesB);

        REQUIRE(tipArrA == tipArrB);
    }

    SECTION("Not equal when arguments differ by length") {
        std::vector<std::shared_ptr<TipType>> initsB {
                std::make_shared<TipInt>(),
                std::make_shared<TipRef>(std::make_shared<TipInt>()),
                std::make_shared<TipRef>(std::make_shared<TipInt>())
        };
        std::vector<std::string> namesB {"foo", "bar"};
        TipArr tipArrB(initsB, namesB);

        REQUIRE(tipArrA != tipArrB);
    }

    SECTION("Not equal when arguments differ by type") {
        std::vector<std::shared_ptr<TipType>> initsB {
            std::make_shared<TipInt>(),
            std::make_shared<TipInt>(),
        };
        std::vector<std::string> namesB {"foo", "bar"};
        TipArr tipArrB(initsB, namesB);

        REQUIRE(tipArrA != tipArrB);
    }

    SECTION("Not equal when argument types differ") {
        TipInt tipInt;

        REQUIRE(tipArrA != tipInt);
    }
}

TEST_CASE("TipArr: Test output stream" "[TipArr]") {
    std::vector<std::shared_ptr<TipType>> inits {
            std::make_shared<TipInt>(),
            std::make_shared<TipRef>(std::make_shared<TipInt>())
    };
    std::vector<std::string> names {"foo", "bar"};
    TipArr tipArr(inits, names);

    auto expectedValue = "{foo:int,bar:\u2B61int}";
    std::stringstream stream;
    stream << tipArr;
    std::string actualValue = stream.str();

    REQUIRE(expectedValue == actualValue);
}*/
