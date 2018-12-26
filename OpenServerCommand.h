#include "Command.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "FlightValueMap.h"
#include "CheckEndScript.h"
#include "CheckForServerConnection.h"
#include <pthread.h>


#ifndef PROJECTNUM1_OPENSERVERCOMMAND_H
#define PROJECTNUM1_OPENSERVERCOMMAND_H
using namespace std;

class OpenServerCommand : public Command {
    // Members
    FlightValueMap *flightValueMap;
    //Check if  reached the end of the script
    CheckEndScript *checkEndScript;
    CheckForServerConnection *checkForServerConnection;

public:

    //Constructor
    OpenServerCommand(FlightValueMap *f,
                      CheckForServerConnection *checkForServerConnection1,
                      CheckEndScript *checkEndScript);

    /**
     * The function open a server that listen to port 5400
     */
    virtual int doCommand(vector<string>::iterator &script);

    ~OpenServerCommand() {
    }

};


#endif //PROJECTNUM1_OPENSERVERCOMMAND_H