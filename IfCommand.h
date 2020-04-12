#ifndef FLIGHTSIMULATOR_IFCOMMAND_H
#define FLIGHTSIMULATOR_IFCOMMAND_H

#include "Command.h"
#include "ConditionCommand.h"

/**
 * IfCommand class is a type of ConditionCommand
 */
class IfCommand : public ConditionCommand {

public:
    /**
     * constructor
     * @param commands
     * @param db
     */
    IfCommand(unordered_map<string, Command *> &commands, DataBase &db);

    /**
     * preform commands if the condition is true
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);
    virtual ~IfCommand(){};

};


#endif //FLIGHTSIMULATOR_IFCOMMAND_H
