#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "Command.h"

/**
 * prints strings and variables
 */
class PrintCommand : public Command {
    DataBase *dataBase;
public:
    /**
     * constructor
     * @param givenDataBase
     */
    PrintCommand(DataBase &givenDataBase);

    /**
     * checks if the what we need to print is a string or a variable:
     * string - prints to screen
     * variable - gets his value and prints to screen.
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);

    virtual ~PrintCommand() {};
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
