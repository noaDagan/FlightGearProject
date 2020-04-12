#include "Div.h"

using namespace std;

Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {

}

double Div::calculate() {
    double rightCalculate = this->getRight()->calculate();
    if (rightCalculate == 0) {
        __throw_invalid_argument("can't divide by zero");
    }
    return this->getLeft()->calculate() / rightCalculate;
}
