//
// Created by or on 12/20/18.
//

#ifndef FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
#define FLIGHTSIMULATOR_OPENSERVERCOMMAND_H

#include "Command.h"
#include "DataReaderServer.h"
#include <pthread.h>

/**
 * opens a server
 */
class OpenServerCommand : public Command {
    DataReaderServer *dataReaderServer;
    DataBase *dataBase;
public:
    /**
     * constructor
     * @param server can open a socket
     * @param data
     */
    OpenServerCommand(DataReaderServer &server, DataBase &data);

/**
 * opens a socket and creates a server than users can connect to it
 * @param it
 */
    virtual void doCommand(vector<string>::iterator &it);

    virtual ~OpenServerCommand() {};
};

#endif //FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
