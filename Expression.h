

#include <map>
#include <string>

using namespace std;
#ifndef PROJECTNUM1_EXPRESSION_H
#define PROJECTNUM1_EXPRESSION_H

class Expression {

public:
    /**
    * The function Calculate the expression by assignment map
    * The function  return the result of the expression using
    */
    virtual double calculate(map<string, double> &assignment) = 0;

};

#endif //PROJECTNUM1_EXPRESSION_H
