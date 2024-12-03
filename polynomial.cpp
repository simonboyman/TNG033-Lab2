/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"

// ADD implementation of the member functions for class Polynomial
Polynomial::Polynomial(const std::vector<double>& v) {
	for (double e : v) {
		this->coeff.push_back(e); //why not v[e]
	}
}

Polynomial* Polynomial::clone() const {
	return new Polynomial(*this);
}

double Polynomial::operator()(double x) const {
	//??
}

Polynomial::Polynomial(const Polynomial& poly) {
	for (double e : poly.coeff) {
		this->coeff.push_back(poly.coeff[e]); //????why this->
	}
}

Polynomial& Polynomial::operator+=(Polynomial rhs) {
	//??
}

double& Polynomial::operator[](int i) {
	return coeff[i];
}



std::string toString() {

}