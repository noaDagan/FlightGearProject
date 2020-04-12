#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H

#include "BinaryExpression.h"

/**
 * binary expression for addition
 */
class Plus : public BinaryExpression{

public:
    /**
     * constructor
     * @param left
     * @param right
     */
    Plus(Expression *left, Expression *right);

    /**
     * calculate left and right expression and return addition of them
     * @return left + right
     */
    virtual double calculate();
    virtual ~Plus(){};
};


#endif //FLIGHTSIMULATOR_PLUS_H
