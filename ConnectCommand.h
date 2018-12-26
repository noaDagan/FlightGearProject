#include "Command.h"
#include <iostream>
#include <ostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include <pthread.h>
#include "CheckForServerConnection.h"
#include "ValueControlForFlight.h"
#include "ExpressionCommand.h"
#include "CheckEndScript.h"


#ifndef PROJECTNUM1_CONNECTCLIENT_H
#define PROJECTNUM1_CONNECTCLIENT_H

using namespace std;

class ConnectCommand : public Command {
    // Members
    ValueControlForFlight *valueControlForFlight;
    CheckForServerConnection *checkForServerConnection;
    CheckEndScript *checkEndScript;
public:

    //Constructor
    ConnectCommand(CheckForServerConnection *isTrue,
                   ValueControlForFlight *valueControlForFlight,
                   CheckEndScript *checkEndScript);

    // Distructor
    ~ConnectCommand();

    /**
     *  The function execute the connect.
     *  The function save the parameters of the ParamsConnect struct
    */
    virtual int doCommand(vector<string>::iterator &script);
};


#endif //PROJECTNUM1_CONNECTCLIENT_H
