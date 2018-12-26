#include "OpenServerCommand.h"

//Constructor
OpenServerCommand::OpenServerCommand(FlightValueMap* f, CheckForServerConnection* isTrue, CheckEndScript* endScript ) {
    this->flightValueMap = f;
    this->checkForServerConnection = isTrue;
    this->checkEndScript = endScript;
}

/**
 * Struct to open the server
 */
struct ParamsSocket {
    //Poty and time to sleep
    int port;
    int time;
    //Map to sample the value received
    FlightValueMap* flightMaps;
    CheckForServerConnection* connectBool;
    CheckEndScript* endScript;
};

/**
 * The function connect the server and read the values from the socket
 */
void* openSocket(void* args) {
    //Convert the args to the struct ParamsSocket
    struct ParamsSocket* params = (struct ParamsSocket*)args;
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    // First call to socket() function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = params->port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    // Now bind the host address using bind() call
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);
    cout<<"Server ... "<<endl;
    params->connectBool->setBoolForConnect(true);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // While we didnt reached the end of the script
    while (!params->endScript->getBoolForExit()) {
        //Read the values from the simulator and update the map
        bzero(buffer,256);
        n = read(newsockfd, buffer, 255);
        string updateMap = buffer;
        params->flightMaps->updateMap(updateMap);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        sleep(params->time);
    }
    close(sockfd);
    close(newsockfd);
    return params;
}

/**
 * The function open a server that listen to port 5400
 */
int OpenServerCommand::doCommand(vector<string>:: iterator &script) {
    //Get the port and time
    int port1,time1;
    port1 = stoi(*script);
    script++;
    time1 = stoi(*script);
    // Create a nw strusct and update his parameters
    struct ParamsSocket* params=new ParamsSocket;
    params->port=port1;
    params->time=time1;
    params->flightMaps = flightValueMap;
    params->connectBool= checkForServerConnection;
    params->endScript = checkEndScript;
    // Open a thread to connect the server
    pthread_t pthread;
    pthread_create(&pthread,nullptr,openSocket,params);
    pthread_detach(pthread);
    script++;
    return 0;
}



