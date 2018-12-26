#include "Command.h"
#include "map"
#include "ExpressionCommand.h"
#include <list>
#include "BoolExpression.h"
#include "SymbolTable.h"


#ifndef PROJECTNUM1_LOOPCOMMAND_H
#define PROJECTNUM1_LOOPCOMMAND_H


class LoopCommand : public Command {
    //Boolean condition
    BoolExpression *boolExpression;
    //List of commandExpression to execute
    list<ExpressionCommand *> expressionCommandList;
    SymbolTable *symbolTable;

public:
    //Constructor
    LoopCommand(BoolExpression *boolExpression, list<ExpressionCommand *> expressionCommandList,
                SymbolTable *symbolTable);

    /**
     * The function execute all the command in the list while the bool expression if true
     */
    virtual int doCommand(vector<string>::iterator &script);

    ~LoopCommand(){
    }
};


#endif //PROJECTNUM1_LOOPCOMMAND_H