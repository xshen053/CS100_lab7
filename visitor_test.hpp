#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__


#include "base.hpp"
#include "visitor.hpp"
#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "PrintLaTeX.hpp"
#include "mult.hpp"
#include "div.hpp"

using namespace std;

TEST(Visitortest, addprint){
    Base* left = new Op(7);
    Base* right = new Op(8);
    Base* test = new Add(left, right);
    VisitorLatex* t = new VisitorLatex();
    EXPECT_EQ(t->PrintLaTex(test), "${({7}+{8})}$");
}

TEST(Visitortest, powtest){
    Base* left = new Op(5);
    Base* right = new Op(2);
    Base* p = new Pow(left, right);
    VisitorLatex* t = new VisitorLatex();
    EXPECT_EQ(t->PrintLaTex(p), "${({5}^{2})}$");
}

TEST(Visitortest, divtest){
    Base* left = new Op(5);
    Base* right = new Op(2);
    Base* p = new Pow(left, right);
    Base* c = new Mult(right, left);
    Base* d = new Div(c, p);
    VisitorLatex* t = new VisitorLatex();
    EXPECT_EQ(t->PrintLaTex(d), "${\\frac{({2}\\cdot{5})}{({5}^{2})}}$");
}


#endif
