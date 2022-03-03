#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpStringEight) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8");
}

TEST(OpTest, OpEvaluateNegaive) {
    Op* test = new Op(-8);
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateDecimal) {
    Op* test = new Op(0.1);
    EXPECT_EQ(test->evaluate(), 0.1);
}

TEST(OpTest, OpStringDecimal) {
    Op* test = new Op(0.1);
    EXPECT_EQ(test->stringify(), "0.1");
}


#endif //__OP_TEST_HPP__
