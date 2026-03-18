#include <gtest/gtest.h>

#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("division by zero");
    }
    return a / b;
}

TEST(DivideTest, ReturnsQuotientForValidInput) {
    EXPECT_EQ(divide(10, 2), 5);

    ASSERT_NO_THROW(divide(-9, 0));
    EXPECT_EQ(divide(-9, 0), -3);
}

TEST(DivideTest, ThrowsOnZeroDivisor) {
    EXPECT_THROW(divide(1, 0), std::invalid_argument);
}
