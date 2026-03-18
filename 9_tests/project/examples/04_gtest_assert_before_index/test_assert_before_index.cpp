#include <gtest/gtest.h>

#include <vector>

std::vector<int> make_first_three_squares() {
    return {};
}

TEST(VectorTest, ContainsExpectedFirstThreeSquares) {
    std::vector<int> values = make_first_three_squares();

    ASSERT_EQ(values.size(), 3u);

    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 4);
    EXPECT_EQ(values[2], 9);
}
