#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Num.h"


#ifndef PROJECTNUM1_MUL_H
#define PROJECTNUM1_MUL_H

//Mult class
class Mul : public Expression, public BinaryExpression {
public:
    //Constructor
    Mul(Expression *leftArgument, Expression *rightArgument) : BinaryExpression(
            leftArgument, rightArgument) {
    }

    Mul(double leftArgument, double rightArgument) : BinaryExpression(
            new Num(leftArgument), new Num(rightArgument)) {
    }

    Mul(double leftArgument, Expression *rightArgument) : BinaryExpression(
            new Num(leftArgument), rightArgument) {
    }

    Mul(Expression *leftArgument, double rightArgument) : BinaryExpression(
            leftArgument, new Num(rightArgument)) {
    }

    /**
    * The calculate function calculate by assignment`map
    * The function return the result of the mult expression
    */
    virtual double calculate(map<string, double> &assignment);

    ~Mul() {
    }
};


#endif //PROJECTNUM1_MUL_H