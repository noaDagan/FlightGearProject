#include "Command.h"
#include "SymbolTable.h"
#ifndef PROJECTNUM1_VARCOMMAND_H
#define PROJECTNUM1_VARCOMMAND_H


class VarCommand : public Command {
    //Member
    SymbolTable* symbolTable;

public:
    //Constructur
    VarCommand(SymbolTable* symbolTable);
    /**
     * The function create a new vat andd add it to the symbol table
     */
    virtual int doCommand(vector<string>:: iterator &script);

    ~VarCommand() {
    }
};


#endif //PROJECTNUM1_VARCOMMAND_H