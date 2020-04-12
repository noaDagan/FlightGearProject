#include "Neg.h"

Neg::Neg(Expression *expr) : UnaryExpression(expr) {

}

double Neg::calculate() {
    return NEG_ONE * this->getExpression()->calculate();
}
