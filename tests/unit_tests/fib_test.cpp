#include "gtest/gtest.h"
//#include "fib_test.h"

extern "C"
{
    #include "../inc/fib.h"
}

TEST(FibTest, NonNegativeValues)
{
    EXPECT_EQ(Fib(0), 0);
    EXPECT_EQ(Fib(1), 1);
    EXPECT_EQ(Fib(5), 5);
    EXPECT_EQ(Fib(6), 8);
}