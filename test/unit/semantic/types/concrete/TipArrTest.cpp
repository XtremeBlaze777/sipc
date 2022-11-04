#include "TipArr.h"

#include <catch2/catch_test_macros.hpp>

#include <sstream>
#include <iostream>

TEST_CASE("TipArr: Test getters" "[TipArr]") {
    std::vector<std::shared_ptr<TipType>> params {
            std::make_shared<TipInt>(),
            std::make_shared<TipInt>()
    };
    auto ret = std::make_shared<TipRef>(std::make_shared<TipInt>());
    TipArr tipArr(params, ret);

    REQUIRE(2 == tipArr.getParams().size());
    REQUIRE(*ret == *tipArr.getReturnValue());
}

TEST_CASE("TipArr: Test equality" "[TipArr]") {
    std::vector<std::shared_ptr<TipType>> paramsA {
            std::make_shared<TipInt>(),
            std::make_shared<TipInt>()
    };
    auto retA = std::make_shared<TipInt>();
    TipArr tipArrA(paramsA, retA);

    SECTION("Equal when arguments and return value are of same type and length") {
        std::vector<std::shared_ptr<TipType>> paramsB {
                std::make_shared<TipInt>(),
                std::make_shared<TipInt>()
        };
        auto retB = std::make_shared<TipInt>();
        TipArr tipArrB(paramsB, retB);
        REQUIRE(tipArrA == tipArrB);
    }

    SECTION("Not equal when arguments differ by length") {
        std::vector<std::shared_ptr<TipType>> paramsB {std::make_shared<TipInt>()};
        auto retB = std::make_shared<TipInt>();
        TipArr tipArrB(paramsB, retB);
        REQUIRE(tipArrA != tipArrB);
    }

    SECTION("Not equal when arguments differ by type") {
        std::vector<std::shared_ptr<TipType>> paramsB {
            std::make_shared<TipInt>(),
            std::make_shared<TipRef>(std::make_shared<TipInt>())
        };
        auto retB = std::make_shared<TipInt>();
        TipArr tipArrB(paramsB, retB);
        REQUIRE(tipArrA != tipArrB);
    }

    SECTION("Not equal when return values differ by type") {
        std::vector<std::shared_ptr<TipType>> paramsB {
                std::make_shared<TipInt>(),
                std::make_shared<TipInt>()
        };
        auto retB = std::make_shared<TipRef>(std::make_shared<TipInt>());
        TipArr tipArrB(paramsB, retB);
        REQUIRE(tipArrA != tipArrB);
    }
}

TEST_CASE("TipArr: Test output stream" "[TipArr]") {
    std::vector<std::shared_ptr<TipType>> params {
            std::make_shared<TipInt>(),
            std::make_shared<TipInt>()
    };
    auto ret = std::make_shared<TipRef>(std::make_shared<TipInt>());
    TipArr tipArr(params, ret);

    auto expectedValue = "(int,int) -> \u2B61int";
    std::stringstream stream;
    stream << tipArr;
    std::string actualValue = stream.str();

    REQUIRE(expectedValue == actualValue);
}
