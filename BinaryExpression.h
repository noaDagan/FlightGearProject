#ifndef FLIGHTSIMULATOR_BINARYEXPRESSION_H
#define FLIGHTSIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

/**
 * abstract class for binary expressions
 */
class BinaryExpression : public Expression {
    Expression *left;
    Expression *right;
public:
    /**
     * constructor with the two expression of this binary expression
     * @param left
     * @param right
     */
    BinaryExpression(Expression *left, Expression *right);

    /**
     *
     * @return right expression
     */
    Expression *getRight();

    /**
     *
     * @return left expression
     */
    Expression *getLeft();
    virtual ~BinaryExpression(){};
};

#endif //FLIGHTSIMULATOR_BINARYEXPRESSION_H