
#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Num.h"

#ifndef PROJECTNUM1_DIV_H
#define PROJECTNUM1_DIV_H

class Div : public Expression, public BinaryExpression {
public:
    //Constructors
    Div(Expression *leftArgument, Expression *rightArgument) : BinaryExpression(
            leftArgument, rightArgument) {
    }

    Div(double leftArgument, double rightArgument) : BinaryExpression(
            new Num(leftArgument), new Num(rightArgument)) {
    }

    Div(double leftArgument, Expression *rightArgument) : BinaryExpression(
            new Num(leftArgument), rightArgument) {
    }

    Div(Expression *leftArgument, double rightArgument) : BinaryExpression(
            leftArgument, new Num(rightArgument)) {
    }

    /**
    * The calculate function calculate by assignment`map
    * The function return the result of the expression div
    */
    virtual double calculate(map<string, double> &assignment);


};

#endif //PROJECTNUM1_DIV_H
