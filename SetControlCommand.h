#include "Command.h"
#include "SymbolTable.h"
#include "ValueControlForFlight.h"
#include <unistd.h>


#ifndef PROJECTNUM1_SETCONTROLCOMMAND_H
#define PROJECTNUM1_SETCONTROLCOMMAND_H


class SetControlCommand : public Command {
    //contains string of control command
    ValueControlForFlight *valueControlForFlight;
    SymbolTable *symbolTable;
public:
    //Constructor
    SetControlCommand(ValueControlForFlight *valueControlForFlight, SymbolTable *symbolTable);

    /**
     * The function create the string command and update the valueControlForFlight
     */
    virtual int doCommand(vector<string>::iterator &script);

    ~SetControlCommand() {
    }
};


#endif //PROJECTNUM1_SETCONTROLCOMMAND_H