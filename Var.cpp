#include "Var.h"

//Constructor
Var::Var(string stringVar, SymbolTable* table) {
    this->var = stringVar;
    this->symbolTable = table;
}

/**
* The function calculate the expression with a given symbol map
*/
double Var::calculate(map<string, double> &assignment) {
    // check if the map contain the var and return thr result
    if (this->symbolTable->isKeyInMap(this->var)) {
        return (this->symbolTable->getSymbolTable(this->var));
    } else {
        // otherwise,  throw exception
        throw "ERROR - no matching variavle";
    }
}