//
// Created by or on 12/22/18.
//

#include <iostream>
#include "ConnectCommand.h"
#include "Utility.h"
#include "ExpressionFactory.h"

void *openSocket2(void *args);

struct myParams {
    string ip;
    double port;
    DataWriterClient *dataWriterClient;
};

ConnectCommand::ConnectCommand(DataWriterClient &dataWriter, DataBase &data) {
    this->dataWriterClient = &dataWriter;
    this->dataBase = &data;
}

void ConnectCommand::doCommand(vector<string>::iterator &it) {
    // first, read arguments for the socket, init struct Params
    ExpressionFactory factory(*this->dataBase);

    string ip = *it++;
    string port = *it++;
    if (Utility::isCommand(ip) || Utility::isCommand(port)) {
        // not a valid parameter !!
        __throw_invalid_argument("invalid argument");
    }

    struct myParams *params = new myParams();
    params->ip = ip;
    params->port = factory.makeExpression(port)->calculate();
    params->dataWriterClient = this->dataWriterClient;

    pthread_t trid;
    pthread_create(&trid, nullptr, openSocket2, (void *) params);
}

// thread's function
void *openSocket2(void *args) {
    // needs to call DataWriterClient:: openSocket
    struct myParams *params;
    params = (struct myParams *) args;
    params->dataWriterClient->createSocketClient(params->ip, params->port);
    return nullptr;
}

