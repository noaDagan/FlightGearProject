#ifndef FLIGHTSIMULATOR_MULT_H
#define FLIGHTSIMULATOR_MULT_H

#include "BinaryExpression.h"

/**
 * binary expression for multiplication
 */
class Mult : public BinaryExpression {

public:
    /**
     * constructor
     * @param left
     * @param right
     */
    Mult(Expression *left, Expression *right);

    /**
     * calculate left and right expression and
     * return multiplication between them
     * @return left * right
     */
    virtual double calculate();
    virtual ~Mult(){};
};


#endif //FLIGHTSIMULATOR_MULT_H
