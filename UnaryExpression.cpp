
#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *expression) {
    this->expression = expression;
}

Expression *UnaryExpression::getExpression() {
    return this->expression;
}
