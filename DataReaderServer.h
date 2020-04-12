#ifndef FLIGHTSIMULATOR_DATAREADERSERVER_H
#define FLIGHTSIMULATOR_DATAREADERSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <iostream>
#include <unordered_map>
#include "DataBase.h"

using namespace std;

/**
 * opens server socket and reads data from simulator
 */
class DataReaderServer {
    int sockfd = 0;
    int cliSocket;
    unordered_map<string, double> simulatorData;
    DataBase *localData;
public:
    /**
     * constructor
     * @param dataBase
     */
    DataReaderServer(DataBase *&dataBase);

    /**
     * open socket on port given
     * @param port
     * @param readingTime
     */
    void createSocketServer(double port, double readingTime);

    /**
     * while server is open read data from simulator
     * and sent to parser to update data base
     */
    void read();

    /**
     * init "simulator data" map.
     */
    void initMap();

    /**
     * close the socket
     */
    void closeSocket();

};


#endif //FLIGHTSIMULATOR_DATAREADERSERVER_H
