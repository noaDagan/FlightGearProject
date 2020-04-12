#ifndef FLIGHTSIMULATOR_WHILECOMMAND_H
#define FLIGHTSIMULATOR_WHILECOMMAND_H

#include "ConditionCommand.h"

/**
 * WhileCommand class is a type of ConditionCommand
 */
class WhileCommand : public ConditionCommand {

public:
    /**
     * constructor
     * @param commands
     * @param db
     */
    WhileCommand(unordered_map<string, Command *> &commands, DataBase &db);

    /**
     * preform commands while the condition is true
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);
};


#endif //FLIGHTSIMULATOR_WHILECOMMAND_H
