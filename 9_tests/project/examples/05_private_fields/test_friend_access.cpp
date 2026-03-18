#include <gtest/gtest.h>
#include "counter.h"

//   CounterTest_CanReadPrivateValue_Test
TEST(CounterTest,CanReadPrivateValue) {
    Counter c;
    c.increment();
    c.increment();

    EXPECT_EQ(c.value_, 2);
}
