#include <string>
#include "string.h"
#include <unordered_map>
#include <vector>
#include "list"
#include <stdexcept>
#include "Expression.h"

#ifndef PROJECTNUM1_NUM_H
#define PROJECTNUM1_NUM_H

using namespace std;

class Num : public Expression
{
//Members
private:
    double num;

public:

    //Constructor
    Num(double n){
        this->num=n;
    }

    /**
     * The function return the value of the number by empty map.
     * The function calculate the expression using in this assignment
     */
    virtual double calculate(map<string, double> &assignment) ;


    ~Num() {
    }


};


#endif //PROJECTNUM1_NUM_H