#ifndef FLIGHTSIMULATOR_DEFINEVARCOMMAND_H
#define FLIGHTSIMULATOR_DEFINEVARCOMMAND_H


#include "Command.h"
#include "DataWriterClient.h"

/**
 * defines a new variable in the dataBase
 */
class DefineVarCommand : public Command {
    DataBase *dataBase;
    DataWriterClient *dataWriter;

public:
    /**
     * constructor
     * @param givenDataBase
     * @param writer
     */
    DefineVarCommand(DataBase &givenDataBase, DataWriterClient &writer);

    /**
     * define new variable:
     * if variable is a simulator variable - bind to right path
     * else - assign the value to the variable and write it in the DB.
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);
    virtual ~DefineVarCommand(){};
};


#endif //FLIGHTSIMULATOR_DEFINEVARCOMMAND_H
