#ifndef __MATH_TEST_HPP__
#define __MATH_TEST_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "PrintLaTeX.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "Math.hpp"

using namespace std;

TEST(VisitMathtest, add){
    Base* left = new Op(7);
    Base* right = new Op(8);
    Base* test = new Add(left, right);
    VisitMathML* math = new VisitMathML();
    EXPECT_EQ(math->PrintMathML(test), "<math>\n  <apply>\n    <plus/>\n    <cn>7</cn>\n    <cn>8</cn>\n  </apply>\n</math>\n");
}

#endif
