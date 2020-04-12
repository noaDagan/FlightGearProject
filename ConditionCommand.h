#ifndef FLIGHTSIMULATOR_CONDITIONCOMMAND_H
#define FLIGHTSIMULATOR_CONDITIONCOMMAND_H

#include "Command.h"

/**
 * abstract class for Condition Command,
 * preforms a command depending the condition.
 */
class ConditionCommand : public Command {
    unordered_map<string, Command *> *commMap;
    DataBase *dataBase;

public:
    /**
     * constructor
     * @param commands map
     * @param db the dataBase
     */
    ConditionCommand(unordered_map<string, Command *> &commands, DataBase &db) {
        this->commMap = &commands;
        this->dataBase = &db;
    };
protected:
    /**
     * goes over all the commands that are in the loop once
     * and preforms each command
     * @param it
     */
    void doAll(vector<string>::iterator &it);

    /**
     * parse the condition and check if true or false
     * @param firstExpr
     * @param op
     * @param secExpr
     * @return true if the condition is true. else - false
     */
    bool parseCondition(string firstExpr, string op, string secExpr);
    virtual ~ConditionCommand(){};
};


#endif //FLIGHTSIMULATOR_CONDITIONCOMMAND_H
