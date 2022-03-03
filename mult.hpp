#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

class Mult: public Base {
    public:
        Mult(Base* left, Base* right): Base() {
	    l = left->evaluate();
	    r = right->evaluate();
            lstr = left->stringify();
	    rstr = right->stringify();
	}
        virtual double evaluate() { return l * r;}
	virtual std::string stringify() { return "(" + lstr + " * " + rstr + ")";}
        virtual int number_of_children(){
                        return 2;
                }
                Base* get_child(int i){
                        if (i == 0){
                                return left;
                        }
                        if (i == 1){
                                return right;
                        }
                        return nullptr;
                }
		virtual void accept (Visitor* visitor, int index){
                        if (index == 0){
                                visitor->visit_mult_begin(this);
                        }
                        else if (index == 1){
                                visitor->visit_mult_middle(this);
                        }
                        else {
                                visitor->visit_mult_end(this);
                        }
                }
    private:
        double l, r;
        std::string lstr, rstr;	

};

#endif
