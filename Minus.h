#include "Expression.h"
#include "BinaryExpression.h"
#include "Num.h"


#ifndef PROJECTNUM1_MINUS_H
#define PROJECTNUM1_MINUS_H


class Minus : public Expression, public BinaryExpression {
public:
    //Constuctors
    Minus(Expression *leftArgument, Expression *rightArgument)
            : BinaryExpression(leftArgument, rightArgument) {
    }

    Minus(double leftArgument, double rightArgument) : BinaryExpression(
            new Num(leftArgument), new Num(rightArgument)) {
    }

    Minus(double leftArgument, Expression *rightArgument) : BinaryExpression(
            new Num(leftArgument), rightArgument) {
    }

    Minus(Expression *leftArgument, double rightArgument) : BinaryExpression(
            leftArgument, new Num(rightArgument)) {
    }

    /**
    * The calculate function calculate by assignment`map
    * The function return the result of the minus expression
    */
    virtual double calculate(map<string, double> &assignment);

    ~Minus() {
    }
};


#endif //PROJECTNUM1_MINUS_H