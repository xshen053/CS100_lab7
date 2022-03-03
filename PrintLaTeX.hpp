#ifndef __VisitorLatex_HPP__
#define __VisitorLatex_HPP__

#include "visitor.hpp"
#include "iterator.hpp"

#include <iostream>
#include <string>



class VisitorLatex: public Visitor{
    public:

	string PrintLaTex(Base* ptr){
	    string result = "";
	    result = result + "$";
	    Iterator it(ptr);
	    while(!= it.is_done()){
	        iter.current_node()->accept(this, iter.current_index);
	    
	    }
	    return result;
	}
        virtual void visit_op(Op* node){
	    result = result + "{" + node->stringify() + "}";
	}
        virtual void visit_rand(Rand* node){
	    result = result + "{" + node->stringify() + "}";
	}

        virtual void visit_add_begin(Add* node){
	    result = 
	}
        virtual void visit_add_middle(Add* node) = 0;
        virtual void visit_add_end(Add* node) = 0;
        virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(Pow* node) = 0;
        virtual void visit_pow_middle(Pow* node) = 0;
        virtual void visit_pow_end(Pow* node) = 0;



};





#endif
