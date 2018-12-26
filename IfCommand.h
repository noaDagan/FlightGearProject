#include <vector>
#include "Command.h"
#include "ExpressionCommand.h"
#include <list>
#include "BoolExpression.h"
#include "SymbolTable.h"

#ifndef PROJECTNUM1_IFCOMMAND_H
#define PROJECTNUM1_IFCOMMAND_H


class IfCommand : public Command {
    //Boolean condition
    BoolExpression *boolExpression;
    //List of commandExpression to execute
    list<ExpressionCommand *> expressionCommandList;
    SymbolTable *symbolTable;
public:
    //Constructor
    IfCommand(BoolExpression *boolExpression, list<ExpressionCommand *> expressionCommandList,
              SymbolTable *symbolTable);

    /**
     * The function execute all the command in the list if the bool expression if true
     */
    virtual int doCommand(vector<string>::iterator &script);

    ~IfCommand() {
    }
};


#endif //PROJECTNUM1_IFCOMMAND_H