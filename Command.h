#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include <string>
#include <vector>
#include "DataBase.h"

using namespace std;

/**
 * abstract class for commands
 */
class Command {

public:
    /**
     * preforms the command with the parameters given.
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it) = 0;
    virtual ~Command(){};
};

#endif //FLIGHTSIMULATOR_COMMAND_H