/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
public:
	Logarithm(); //default

	Logarithm(Expression& E, double c1, double c2, int b);
	
	~Logarithm() override { //need to delete E because it is pointer
		delete E;
		E = nullptr;
		c1 = 0;
		c2 = 0;
		b = 0;
	}

	Logarithm(const Logarithm& L); //copy constructor

	Logarithm& operator=(Logarithm lhs); //assign

	Logarithm* clone() const override;

	double operator()(double x) const override;

	void set_base(int c) {
		if (c > 1) {
			b = c;
		}
	}

protected:
	double c1;
	double c2;
	int b;
	Expression* E; //use pointer because expression in and of itself is not an object

	std::string toString() const override;
	
	//void display(std::ostream& os) const override;
};
