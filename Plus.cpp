
#include "Plus.h"

/**
* The calculate function calculate by empty`map
* The function return the result of the plus expression
*/
double Plus::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    return leftValue + rightValue;
}
