#include "gtest/gtest.h"

extern "C"
{
    #include "../inc/add.h"
}

TEST(SomeTestSuite, SomeTest)
{
    ASSERT_EQ(add(1,2), 3);
}