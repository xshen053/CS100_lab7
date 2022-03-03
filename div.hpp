#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

class Div: public Base {
    public:
        Div(Base* left, Base* right): Base() {
            l = left->evaluate();
            r = right->evaluate();
            lstr = left->stringify();
            rstr = right->stringify();
        }
        virtual double evaluate() { return l / r;}
        virtual std::string stringify() { return "(" + lstr + " / " + rstr + ")";}
        virtual int number_of_children(){
                        return 2;
                }
                virtual Base* get_child(int i){
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
                                visitor->visit_div_begin(this);
                        }
                        else if (index == 1){
                                visitor->visit_div_middle(this);
                        }
                        else {
                                visitor->visit_div_end(this);
                        }
                }
    private:
        double l, r;
        std::string lstr, rstr;

};


#endif
