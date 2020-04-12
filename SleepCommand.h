#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H

#define TO_MICRO 1000

#include "CommandExpression.h"

/**
 * sleeps - pauses the program for a certain amount of time.
 */
class SleepCommand : public Command {
    DataBase *dataBase;
public:
    /**
     * constructor
     * @param givenDataBase
     */
    SleepCommand(DataBase &givenDataBase);

    /**
     * sleeps for X microseconds
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);

    virtual ~SleepCommand() {};
};


#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
