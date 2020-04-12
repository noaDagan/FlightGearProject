#ifndef FLIGHTSIMULATOR_EXPRESSION_H
#define FLIGHTSIMULATOR_EXPRESSION_H

#include <string>
#include <map>
#include <queue>

using namespace std;

/**
 * interface of all expression
 */
class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression(){};
};


#endif //FLIGHTSIMULATOR_EXPRESSION_H
