#ifndef FLIGHTSIMULATOR_COMMANDEXPRESSION_H
#define FLIGHTSIMULATOR_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

/**
 * object adapter between commands and expressions
 */
class CommandExpression : public Expression {
    Command *command;
public:
    CommandExpression(Command *c);
    ~CommandExpression(){};
};


#endif //FLIGHTSIMULATOR_COMMANDEXPRESSION_H
