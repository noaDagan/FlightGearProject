#include "Neg.h"

Neg::Neg(Expression *negNum) {
    this->negativeNumber = negNum;
}

/**
* The calculate function calculate by assignment`map
* The function return the result of the negative expression
*/
double Neg::calculate(map<string, double> &assignment) {
    //Multiple -1 with the expression result
    return (-1)*this->negativeNumber->calculate(assignment);
}