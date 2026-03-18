#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(AddTest, WorksForPositiveNumbers) {
    EXPECT_EQ(add(2, 3), 6);
}

TEST(AddTest, WorksForMixedSigns) {
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(AddTest, WorksForZeros) {
    EXPECT_EQ(add(0, 0), 0);
}
