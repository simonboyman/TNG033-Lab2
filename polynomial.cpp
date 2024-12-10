/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <cmath>
#include <format>
#include <iomanip>

// ADD implementation of the member functions for class Polynomial
Polynomial::Polynomial(const std::vector<double>& v) {
	for (double e : v) {
		this->coeff.push_back(e); 
	}
}

Polynomial* Polynomial::clone() const {
	return new Polynomial(*this);
}

double Polynomial::operator()(double x) const {
	double sum = 0;
	for (int i = 0; i < std::ssize(this->coeff); i++) {
		sum += this->coeff[i] * pow(x, i);
	}
	return sum;
}

Polynomial::Polynomial(const Polynomial& poly) {
	for (double e : poly.coeff) {
		this->coeff.push_back(e); 
	}
}

Polynomial& Polynomial::operator+=(Polynomial rhs) {
	for (int i = 0; i < std::ssize(rhs.coeff); i++) {
		if (i >= this->coeff.size()) {
			this->coeff.push_back(rhs.coeff[i]);
		}
		else {
			this->coeff[i] += rhs.coeff[i];
		}
	}
	return *this;
}

std::string Polynomial::toString() const {
	std::string temp = std::format("{:.2f}", coeff[0]);
	for (int i = 1; i < std::ssize(coeff); i++) {
		if (coeff[i] < 0) {
			temp += std::format(" - {:.2f} * X^{}", std::abs(coeff[i]), i);
		}
		else {
			temp += std::format(" + {:.2f} * X^{}", std::abs(coeff[i]), i);
		}
	}
	return temp;
}