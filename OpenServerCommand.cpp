#include "OpenServerCommand.h"
#include "Utility.h"
#include "ExpressionFactory.h"


void *openSocket(void *args);

struct myParams {
    double port;
    double readingTime;
    DataReaderServer *dataServer;
};

OpenServerCommand::OpenServerCommand(DataReaderServer &server, DataBase &data) {
    this->dataReaderServer = &server;
    this->dataBase = &data;
}

void OpenServerCommand::doCommand(vector<string>::iterator &it) {
    // should open thread that opens socket through "DataReaderServer:: openSocket"

    // first, read arguments for the socket, init struct Params
    ExpressionFactory factory(*this->dataBase);

    string port = *it++;
    string readingTime = *it++;
    if (Utility::isCommand(port) || Utility::isCommand(readingTime)) {
        // not a valid parameter !!
        __throw_invalid_argument("invalid argument");
    }

    struct myParams *params = new myParams();
    params->port = factory.makeExpression(port)->calculate();
    params->readingTime = factory.makeExpression(readingTime)->calculate();
    params->dataServer = this->dataReaderServer;

    pthread_t trid;
    pthread_create(&trid, nullptr, openSocket, (void *) params);
}



// thread's function
void *openSocket(void *args) {
    // needs to call DataReaderServer:: openSocket
    struct myParams *params;
    params = (struct myParams *) args;
    params->dataServer->createSocketServer(params->port, params->readingTime);
    params->dataServer->read();
    return nullptr;
}
