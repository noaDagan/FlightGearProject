#ifndef FLIGHTSIMULATOR_UNARYEXPRESSION_H
#define FLIGHTSIMULATOR_UNARYEXPRESSION_H

#include "Expression.h"

/**
 * abstract class for unary expressions
 */
class UnaryExpression : public Expression {
    Expression *expression;
public:
    /**
     * constructor of single expression in this unary expression
     * @param expression
     */
    UnaryExpression(Expression *expression);

    /**
     * return this expression (the member)
     * @return the member "expression"
     */
    Expression *getExpression();


};


#endif //FLIGHTSIMULATOR_UNARYEXPRESSION_H
