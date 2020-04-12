#include <unistd.h>
#include "SleepCommand.h"
#include "ExpressionFactory.h"
#include "Utility.h"

SleepCommand::SleepCommand(DataBase &givenDataBase) {
    this->dataBase = &givenDataBase;
}

void SleepCommand::doCommand(vector<string>::iterator &it) {
    string timeToSleep = *it++;
    if (Utility::isCommand(timeToSleep)) {
        // not a valid parameter !!
        __throw_invalid_argument("invalid argument");
    }
    ExpressionFactory factory(*this->dataBase);
    Expression *expression = factory.makeExpression(timeToSleep);
    usleep(static_cast<unsigned int>(expression->calculate() * TO_MICRO));
}
