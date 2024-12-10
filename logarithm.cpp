/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include <cmath>
#include "polynomial.h"
#include <format>
#include <iomanip>

// ADD implementation of the member functions for class Logarithm
Logarithm::Logarithm() : c1{0}, c2{1}, b{2}, E{new Polynomial{{0,1}}} {}

Logarithm::Logarithm(Expression& E_arg, double c1_arg, double c2_arg, int b_arg) {
	E = E_arg.clone();
	c1 = c1_arg;
	c2 = c2_arg;
	b = b_arg;
}

Logarithm::Logarithm(const Logarithm& L) {
	c1 = L.c1;
	c2 = L.c2;
	b = L.b;
	E = (*L.E).clone(); //varför clone här?
}

Logarithm* Logarithm::clone() const {
	return new Logarithm(*this);
}

double Logarithm::operator()(double x) const {
	return (c1 + c2 * (log(E->operator()(x)) / log(b)));
}

Logarithm& Logarithm::operator=(Logarithm lhs) {
	c1 = lhs.c1;
	c2 = lhs.c2;
	b = lhs.b;
	delete E;
	E = (*lhs.E).clone();
	return *this;
}

std::string Logarithm::toString() const {
	std::string temp = std::format("{:.2f}", c1);
	std::string E_string = E->operator std::string(); //toString is protected so do operator std::string() instead
	if (c2 < 0) {
		temp += std::format(" - {:.2f} * Log_{}( {} )", std::abs(c2), b, E_string);
	}
	else {
		temp += std::format(" + {:.2f} * Log_{}( {} )", std::abs(c2), b, E_string);
	}
	return temp;
}