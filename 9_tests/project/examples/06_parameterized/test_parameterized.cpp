#include <gtest/gtest.h>

int abs_value(int x) {
    return x;
}

struct AbsCase {
    int input;
    int expected;
};

class AbsValueTest : public ::testing::TestWithParam<AbsCase> {};

TEST_P(AbsValueTest, ReturnsExpectedAbsoluteValue) {
    const AbsCase param = GetParam();
    EXPECT_EQ(abs_value(param.input), param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    BasicCases,
    AbsValueTest,
    ::testing::ValuesIn(
        std::vector<AbsCase> {
            AbsCase{5, 5},
            AbsCase{-5, 5},
            AbsCase{0, 0},
            AbsCase{-123, 123},
        }
    )
);
