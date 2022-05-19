#include "gtest/gtest.h"
#include "fib.h"

class fibTest : public testing::TestWithParam<int> {};

TEST_P(fibTest, WorksForVariousInputs)
{
    auto in = GetParam();
    auto expected = in;
    Fib(in);
    
}