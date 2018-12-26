#include "Expression.h"
#include "SymbolTable.h"
#ifndef PROJECTNUM1_VAR_H
#define PROJECTNUM1_VAR_H

class Var : public Expression {

    string var;
    SymbolTable* symbolTable;
public:
    //Constructor
    Var(string var, SymbolTable* table);

    /**
     * The function calculate the expression with a given symbol map
     */
    double calculate(map<string, double> &assignment);

    ~Var() {
    }
};


#endif //PROJECTNUM1_VAR_H