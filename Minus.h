#ifndef FLIGHTSIMULATOR_MINUS_H
#define FLIGHTSIMULATOR_MINUS_H

#include "BinaryExpression.h"

/**
 * binary expression for subtraction
 */
class Minus : public BinaryExpression {

public:
    /**
     * constructor
     * @param left
     * @param right
     */
    Minus(Expression *left, Expression *right);

    /**
     * calculate left and right expression and return subtraction between them
     * @return left - right
     */
    virtual double calculate();
};

#endif //FLIGHTSIMULATOR_MINUS_H