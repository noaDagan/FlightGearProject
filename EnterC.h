//
// Created by or on 12/23/18.
//

#ifndef FLIGHTSIMULATOR_ENTERC_H
#define FLIGHTSIMULATOR_ENTERC_H


#include "Command.h"

/**
 * waits for an input from user to get permission to continue
 * with the running of the program
 */
class EnterC : public Command {
public:
    /**
     * notifys user to enter, pauses the program and waits for the input.
     * continues program after input.
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);
    virtual ~EnterC(){};
};


#endif //FLIGHTSIMULATOR_ENTERC_H
