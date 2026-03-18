#include <gtest/gtest.h>
#include "counter.h"

TEST(CounterTest, ChangesStateThroughPublicApi) {
    Counter c;

    EXPECT_EQ(c.value(), 0);

    c.increment();
    c.increment();
    EXPECT_EQ(c.value(), 2);

    c.decrement();
    EXPECT_EQ(c.value(), 1);
}
