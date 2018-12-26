#include <iostream>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
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
#include "Expression.h"
#include "CreateExpression.h"
#include "CreateCommand.h"


int main(int argc, char* argv[]) {
   CreateCommand* createCommand= new CreateCommand();
   // Read the name of the text file from the command line
   if (argc == 2) {
       createCommand->lexer(argv[1]);
   }
   delete createCommand;
   return 0;
}