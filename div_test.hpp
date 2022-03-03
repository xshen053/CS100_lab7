#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(5);
    Div* test = new Div(op1, op2);
    EXPECT_EQ(test->evaluate(), 0.8);
}

TEST(DivTest, DivEvaluateWithMult) {
    Op* op1 = new Op(4);
    Op* op2 = new Op(5);
    Mult* mult1 = new Mult(op1, op2);
    Div* test = new Div(mult1, op2);
    EXPECT_EQ(test->evaluate(), 4);
}

TEST(DivTest, numChildren_typicalConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;

	x = new Op(4); y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->number_of_children(), 2);

}

TEST(DivTest, numChildren_BlankConstructor){
	Base *test = nullptr, *x = nullptr, *y = nullptr;

	test = new Div();
	EXPECT_EQ(test->number_of_children(), 0);
}

TEST(DivTest, getChild_twoChildren){
	Base *test = nullptr, *x = nullptr, *y = nullptr;
	
	x = new Op(4);
	y = new Op(8);
	test = new Div(x, y);
	EXPECT_EQ(test->get_child(0), x); 
	EXPECT_EQ(test->get_child(1), y); 

	// Anything other than 0 or 1 should return nullptr
	EXPECT_EQ(test->get_child(5), nullptr);
	EXPECT_EQ(test->get_child(-1), nullptr);

	
}

#endif
