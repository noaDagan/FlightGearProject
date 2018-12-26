#include "Mul.h"

/**
* The calculate function calculate by assignment`map
* The function return the result of the mult expression
*/
double Mul::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    //Calculate the right and left expression
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    return leftValue * rightValue;
}