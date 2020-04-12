#ifndef FLIGHTSIMULATOR_NUMBER_H
#define FLIGHTSIMULATOR_NUMBER_H

#include "Expression.h"

/**
 * expression of number
 */
class Number : public Expression {
    double num;
public:
    /**
     * constructor
     * @param num
     */
    Number(double num);

    /**
     * return the number itself
     * @return
     */
    virtual double calculate();
    virtual ~Number(){};
};

#endif //FLIGHTSIMULATOR_NUMBER_H
