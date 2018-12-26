#include "ConnectCommand.h"

// Constructor
ConnectCommand::ConnectCommand(CheckForServerConnection *isFalse,
                               ValueControlForFlight *valueControl,
                               CheckEndScript *endScript) {
    this->checkForServerConnection = isFalse;
    this->valueControlForFlight = valueControl;
    this->checkEndScript = endScript;
}

// struct params of connect client
struct ParamsConnect {
    int port;
    string ipAddress;
    CheckForServerConnection *connectBool;
    ValueControlForFlight *controlFlight;
    CheckEndScript *endScript;
};

ConnectCommand::~ConnectCommand() {

}

/**
 * The function connect as client to simulator
 *
 */
void *connectClient(void *args) {
    int sockfd, portno, n;
    const struct ParamsConnect *params = (struct ParamsConnect *) args;
    const char *hostName = (params->ipAddress.c_str());
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    // accept the port from struct
    portno = params->port;

    // check if the server connect and wait if not connect
    while (!params->connectBool->getBoolForConnect()) {
        sleep(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(hostName);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    // Now connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) {
        perror("ERROR connecting");
        exit(1);
    }
    cout << "Connect ... " << endl;
    // check if end read the script
    while (!params->endScript->getBoolForExit()) {
        // Check if the input string not empty
        if (!params->controlFlight->checkIfStringEmpty()) {
            bzero(buffer, 256);
            strcpy(buffer, params->controlFlight->getControlString().c_str());
            // write and read to socket
            ssize_t writeBuffer = write(sockfd, buffer, strlen(buffer));
            if (writeBuffer < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            printf("connect buffer write  :  %s" ,buffer);
            bzero(buffer, 256);
            n = read(sockfd, buffer, 255);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            printf("connect buffer read  :  %s" ,buffer);

            // initialize thr string
            params->controlFlight->setControlString("");
        }
    }
    close(sockfd);
}

/**
 *  The function execute the connect.
 *  The function save the parameters of the ParamsConnect struct
 */
int ConnectCommand::doCommand(vector<string>::iterator &script) {
    struct ParamsConnect *pConnect = new ParamsConnect;
    int p;
    string ip;
    ip = (*script);
    script++;
    p = stoi(*script);
    pConnect->port = p;
    pConnect->ipAddress = ip;
    pConnect->connectBool = this->checkForServerConnection;
    pConnect->controlFlight = this->valueControlForFlight;
    pConnect->endScript = this->checkEndScript;
    pthread_t pthread;
    pthread_create(&pthread, nullptr, connectClient, pConnect);
    pthread_detach(pthread);
    script++;
    return 0;
}