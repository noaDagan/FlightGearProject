//
// Created by or on 12/22/18.
//

#include <strings.h>
#include <cstring>
#include <iostream>
#include "DataWriterClient.h"

void DataWriterClient::createSocketClient(string ip, double port) {
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) {
        perror("ERROR connecting");
        exit(1);
    } else {
        isConnected = true;
    }
}

void DataWriterClient::write(const char *buffer) const {
    /* Send message to the server */
    ssize_t msg = ::write(sockfd, buffer, strlen(buffer));
    if (msg < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

void DataWriterClient::closeSocket() {
    close(sockfd);
}
