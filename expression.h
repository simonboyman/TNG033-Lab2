/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <iomanip>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS
    
    bool isRoot(double x) const; //const means this will not change anything, this is just check. promises not to change any values

    virtual Expression* clone() const = 0; //should return pointer

    virtual double operator()(double x) const = 0; //evaluate
    //operator()(double x) is f(x). is pure virtual, meaning is abstract. this means derived class NEEDS to implement operator.

    operator std::string() const {
        return toString();
    }

    friend std::ostream& operator<<(std::ostream& os, const Expression& aExpr) { //write out to output stream
        os << aExpr.operator std::string();
        return os;
    }

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

    virtual std::string toString() const = 0;

    Expression& operator=(const Expression&) const = delete; //this code prevents direct assignment

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions;
    // Your code cannot manipulate this variable


};
