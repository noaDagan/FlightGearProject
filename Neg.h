#ifndef FLIGHTSIMULATOR_NEG_H
#define FLIGHTSIMULATOR_NEG_H

#define NEG_ONE -1

#include "UnaryExpression.h"

/**
 * unary expression of negation
 */
class Neg : public UnaryExpression {
public:
    /**
     * constructor
     * @param expr
     */
    Neg(Expression *expr);

    /**
     * negate expression
     * @return -(expression)
     */
    virtual double calculate();
    virtual ~Neg(){};
};

#endif //FLIGHTSIMULATOR_NEG_H
