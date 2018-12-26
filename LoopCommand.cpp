#include "LoopCommand.h"

//Constructor
LoopCommand::LoopCommand(BoolExpression *boolExpres,
                         list<ExpressionCommand *> list,
                         SymbolTable *symbolTable) {
    this->boolExpression = boolExpres;
    this->expressionCommandList = list;
    this->symbolTable = symbolTable;
}

/**
 * The function execute all the command in the list while the bool expression if true
 */
int LoopCommand::doCommand(vector<string>::iterator &script) {
    list<ExpressionCommand *> tempList;
    //While the bool expression is true
    while (this->boolExpression->calculateBool(
            this->symbolTable->getSymbolTableMap())) {
        //Save the list in a temp variable
        tempList =this->expressionCommandList;
        //Go ovet the list and execute the command
        list<ExpressionCommand *>::iterator itr;
        for (itr = tempList.begin();
             itr !=tempList.end(); itr++) {
            map<string, double> symbolMap = this->symbolTable->getSymbolTableMap();
            (*itr)->calculate(symbolMap);
        }

    }
}