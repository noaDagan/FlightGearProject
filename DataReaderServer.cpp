#include <cstdio>
#include "DataReaderServer.h"
#include "SimulatorDataParser.h"
#include "Utility.h"

DataReaderServer::DataReaderServer(DataBase *&dataBase) {
    this->localData = dataBase;
    initMap();
}

void DataReaderServer::createSocketServer(double port, double readingTime) {
    int clilen;
    double portno;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    this->cliSocket = accept(sockfd, (struct sockaddr *) &cli_addr,
                             (socklen_t * ) & clilen);

    if (cliSocket < 0) {
        perror("ERROR on accept");
        exit(1);
    }
}

void DataReaderServer::read() {
    char buffer[1024];
    bzero(buffer, 1024);
    ssize_t readRes;
    SimulatorDataParser dataParser(this->simulatorData, this->localData);
    while (true) {
        readRes = ::read(cliSocket, buffer, 1023);

        if (readRes < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        dataParser.parse(buffer);
        dataParser.syncData();
    }
}

void DataReaderServer::initMap() {
    for (const auto &field : Utility::fields) {
        this->simulatorData.insert(pair<string, double>(field, 0));
    }
}

void DataReaderServer::closeSocket() {
    close(sockfd);
}
