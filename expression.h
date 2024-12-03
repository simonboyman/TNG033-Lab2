/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS
    friend std::ostream& operator<<(std::ostream& os, const Expression& aExpr); //type conversion
    
    bool isRoot(double x) const; //??

    virtual Expression* clone() const = 0; //should return pointer

    virtual double operator()(double x) const = 0; //operator()(double x) is f(x). is pure virtual, meaning is abstract.

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    virtual void display(std::ostream& os) const = 0;

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;
    // Your code cannot manipulate this variable


};
