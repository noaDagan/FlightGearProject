#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include "Expression.h"

#ifndef PROJECTNUM1_BINARYEXPRESSION_H
#define PROJECTNUM1_BINARYEXPRESSION_H

class BinaryExpression {
    //Members
public:
    Expression *leftArgument;
    Expression *rightArgument;

    /**
     * The BinaryExpression distructor by two expression and operator.
     * delete leftArgument and rightArgument
     */
public:
    virtual ~BinaryExpression() {
        delete leftArgument;
        delete rightArgument;
    }

    /**
        * The BinaryExpression constructor build by two expressio.
        *
        * leftArgument the left side argument
        * rightArgument the right side argument
        */
    BinaryExpression(Expression *leftArgument, Expression *rightArgument) {
        this->leftArgument = leftArgument;
        this->rightArgument = rightArgument;
    }
};

#endif //PROJECTNUM1_BINARYEXPRESSION_H
