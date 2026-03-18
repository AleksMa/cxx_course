#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("division by zero");
    }
    return a / b;
}

TEST_CASE("divide returns quotient for valid arguments") {
    REQUIRE(divide(10, 2) == 5);
    CHECK(divide(-9, 3) == -3);
    CHECK(divide(0, 5) == 0);
}

TEST_CASE("divide throws on zero divisor") {
    REQUIRE_THROWS_AS(divide(1, 0), std::invalid_argument);
}
