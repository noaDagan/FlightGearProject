#include "Command.h"
#include "SymbolTable.h"
#include <map>
#include <iostream>
#include <string>
#include <string.h>

#ifndef PROJECTNUM1_PRINTCOMMAND_H
#define PROJECTNUM1_PRINTCOMMAND_H


class PrintCommand : public Command {

    //Member
    SymbolTable *symbolTable;
public:

    //Constructor
    PrintCommand(SymbolTable *symbolTable);

    /**
     * The function print the message ot receive
     */
    virtual int doCommand(vector<string>::iterator &script);

    ~PrintCommand() {
    }

};


#endif //PROJECTNUM1_PRINTCOMMAND_H