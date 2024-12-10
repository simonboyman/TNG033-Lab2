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

	Polynomial* clone() const override; //clone

	double operator()(double x) const override; //evaluate

	~Polynomial() override = default; //destructor

	Polynomial& operator=(Polynomial rhs){//assignment operator
		if (this != &rhs) {
			coeff = rhs.coeff;
		}
		return *this;
	}

	Polynomial& operator+=(Polynomial rhs); //add-and-assign
	
	friend Polynomial operator+(Polynomial p, const Polynomial& q) { //you dont call from any *this, only use arguments
		Polynomial temp = p += q;
		return temp;
	} //p + q

	friend Polynomial operator+(Polynomial& p, double d) {
		return p + Polynomial(d);
	}//p + d

	const double& operator[](int i) const { //this returns a constant, meaning you can't modify it.
		return coeff[i];
	}

	double& operator[](int i){
		return coeff[i];
	}

protected:
	std::vector<double> coeff;

	std::string toString() const override;

	//void display(std::ostream& os) const override;
};

/*
 * std::vector should be used to store polinomial's coefficients
 */