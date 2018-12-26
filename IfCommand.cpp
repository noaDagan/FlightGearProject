#include "IfCommand.h"

// Constructor
IfCommand::IfCommand(BoolExpression *boolExpres, list<ExpressionCommand *> list, SymbolTable* symbolTable) {
    this->expressionCommandList = list;
    this->boolExpression = boolExpres;
    this->symbolTable=symbolTable;
}


/**
 * The function execute all the command in the list if the bool expression if true
 */
int IfCommand::doCommand(vector<string>::iterator &script) {
    //if the bool expression is true
    if (this->boolExpression->calculateBool(
            this->symbolTable->getSymbolTableMap())) {
        list<ExpressionCommand *>::iterator itr;
        //Go ovet the list and execute the command
        for (itr = this->expressionCommandList.begin();
             itr != this->expressionCommandList.end(); itr++) {
            map<string, double> symbolMap = this->symbolTable->getSymbolTableMap();
            (*itr)->calculate(symbolMap);
        }
    }
}