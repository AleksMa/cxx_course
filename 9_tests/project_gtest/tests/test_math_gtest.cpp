#include <catch2/catch_test_macros.hpp>
#include "math_utils.h"

TEST_CASE("sum works for regular vectors") {
    REQUIRE(sum({1, 2, 3}) == 6);
    REQUIRE(sum({10}) == 10);
}

TEST_CASE("sum works for empty vector") {
    REQUIRE(sum({}) == 0);
}

TEST_CASE("divide returns quotient") {
    REQUIRE(divide(10, 2) == 5);
}

TEST_CASE("divide throws on zero divisor") {
    REQUIRE_THROWS_AS(divide(10, 0), std::invalid_argument);
}
