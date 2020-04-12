#ifndef FLIGHTSIMULATOR_ASSIGNCOMMAND_H
#define FLIGHTSIMULATOR_ASSIGNCOMMAND_H

#include "Command.h"
#include "DataWriterClient.h"

/**
 * assign value to a variable
 */
class AssignCommand: public Command {
    DataBase *dataBase;
    DataWriterClient *dataWriter;
public:
    /**
     * constructor
     * @param givenDataBase
     * @param writer
     */
    AssignCommand(DataBase &givenDataBase, DataWriterClient &writer);

    /**
     * assign the value to the variable and update in the simulator or the DB map.
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);
    ~AssignCommand(){};
};


#endif //FLIGHTSIMULATOR_ASSIGNCOMMAND_H
