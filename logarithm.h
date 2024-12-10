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
	}

	Logarithm(const Logarithm& L); //copy constructor

	Logarithm& operator=(Logarithm lhs); //assign

	Logarithm* clone() const override;

	double operator()(double x) const override;

	void set_base(int c) {
		b = c;
	}

protected:
	double c1;
	double c2;
	int b;
	Expression* E; //use pointer because expression in and of itself is not an object

	std::string toString() const override;
	
	//void display(std::ostream& os) const override;
};
