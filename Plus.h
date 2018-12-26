#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Num.h"

#ifndef PROJECTNUM1_PLUS_H
#define PROJECTNUM1_PLUS_H

using namespace std;

class Plus : public Expression, public BinaryExpression {
public:
    //Constructors
    Plus(Expression *leftArgument, Expression *rightArgument)
            : BinaryExpression(leftArgument, rightArgument) {
    }

    Plus(double leftArgument, double rightArgument) : BinaryExpression(
            new Num(leftArgument), new Num(rightArgument)) {
    }

    Plus(double leftArgument, Expression *rightArgument) : BinaryExpression(
            new Num(leftArgument), rightArgument) {
    }

    Plus(Expression *leftArgument, double rightArgument) : BinaryExpression(
            leftArgument, new Num(rightArgument)) {
    }

    /**
    * The calculate function calculate by`map
    * The function return the result of the plus expression
    */
    virtual double calculate(map<string, double> &assignment);

    ~Plus() {
    }

};


#endif //PROJECTNUM1_PLUS_H