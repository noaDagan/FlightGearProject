#include "Minus.h"


/**
* The calculate function calculate by assignment`map
* The function return the result of the minus expression
*/
double Minus::calculate(map<string, double> &assignment) {
    double leftValue = 0;
    double rightValue = 0;
    //Calculate the right and left argument
    leftValue = this->leftArgument->calculate(assignment);
    rightValue = this->rightArgument->calculate(assignment);
    //Subtract the results
    return leftValue-rightValue;
}