#ifndef FLIGHTSIMULATOR_DATAWRITERCLIENT_H
#define FLIGHTSIMULATOR_DATAWRITERCLIENT_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>

using namespace std;

class DataWriterClient {
    int sockfd = 0;
public:
    bool isConnected = false;

    /**
     * open client socket, connect to ip given
     * @param ip
     * @param port
     */
    void createSocketClient(string ip, double port);

    /**
     * using the socket opened, write message to simulator
     * @param buffer
     */
    void write(const char *buffer) const;

    /**
     * close the socket
     */
    void closeSocket();
};


#endif //FLIGHTSIMULATOR_DATAWRITERCLIENT_H
