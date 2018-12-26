#include "Expression.h"
#include "Command.h"
#include "CreateExpression.h"
#include <vector>
#include "SymbolTable.h"
#ifndef PROJECTNUM1_EXPRESSIONCOMMAND_H
#define PROJECTNUM1_EXPRESSIONCOMMAND_H


class ExpressionCommand : public Expression {
    Command *command;
    vector<string>::iterator script;
    SymbolTable* symbolTable;
public:
    // Constructor
    ExpressionCommand(Command *c, vector<string>::iterator &script, SymbolTable* table);

    ~ExpressionCommand() {}

    /**
    * The function calculate the expression by the value in the map
    */
    virtual double calculate(map<string, double> &assignment);
};


#endif //PROJECTNUM1_EXPRESSIONCOMMAND_H
