#ifndef _ADD_HPP_
#define _ADD_HPP_
#include "base.hpp"
#include <iostream>
using namespace std;

class Add:public Base{
	private:
		double r;
		double l;
		string rstr;
		string lstr;
	public:
		Add(Base* left, Base* right){
			l=left->evaluate();
			r=right->evaluate();
			rstr=left->stringify();
			lstr=right->stringify();
		}
		double evaluate(){return l + r;}
		string stringify(){return"(" + rstr + " + " + lstr + ")";}
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
				visitor->visit_add_begin(this);
			}
			else if (index == 1){
				visitor->visit_add_middle(this);
			}
			else {
				visitor->visit_add_end(this);
			}
		}
};



#endif //_ADD_HPP_
