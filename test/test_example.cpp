#include <gtest/gtest.h>
#include "example.h"

TEST(SuiteName, NumeTest) {
    doSomething();
    EXPECT_EQ(10, 10);
}
