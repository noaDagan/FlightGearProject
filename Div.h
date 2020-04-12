#ifndef FLIGHTSIMULATOR_DIV_H
#define FLIGHTSIMULATOR_DIV_H

#include <iostream>
#include "BinaryExpression.h"

/**
 * binary expression for division
 */
class Div : public BinaryExpression {

public:
    /**
     * constructor
     * @param left
     * @param right
     */
    Div(Expression *left, Expression *right);

    /**
     * calculate left and right expression and return division between them
     * @return left / right
     */
    virtual double calculate();
    virtual ~Div(){};
};


#endif //FLIGHTSIMULATOR_DIV_H
