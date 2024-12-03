/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include <vector>

#include "expression.h"

class Polynomial : public Expression {
public:
	Polynomial(const std::vector<double>& v); //create polynomial from vector
	Polynomial(double real) : Expression{} {
		coeff.push_back(real);
	}//convert real to polynomial

	Polynomial(const Polynomial& poly);
	//copy constructor

	Polynomial* clone() const override;

	double operator()(double x) const override;

	~Polynomial() override = default; //destructor

	Polynomial& operator=(Polynomial& rhs){//assignment operator
		std::swap(coeff, rhs.coeff);
		return *this;
	}
	Polynomial& operator+=(Polynomial rhs); //add-and-assign
	
	friend Polynomial operator+(Polynomial p, const Polynomial& q) {
		p += q;
		return p;
	} //p + q

	friend Polynomial operator+(Polynomial& p, double d) { //??why friend????
		return p + Polynomial(d);
	}//p + d

	double& operator[](int i);

protected:
	std::vector<double> coeff;
	std::string toString() const override;
};

/*
 * std::vector should be used to store polinomial's coefficients
 */