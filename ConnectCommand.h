#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H


#include "Command.h"
#include "DataWriterClient.h"

/**
 * connects to a server
 */
class ConnectCommand : public Command {
    DataWriterClient *dataWriterClient;
    DataBase *dataBase;
    int threadID;
public:
    /**
     * constructor
     * @param dataWriter
     * @param data
     */
    ConnectCommand(DataWriterClient &dataWriter, DataBase &data);

    /**
     * opens a socket and connects to server
     * @param it
     */
    virtual void doCommand(vector<string>::iterator &it);
    virtual ~ConnectCommand(){};
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
