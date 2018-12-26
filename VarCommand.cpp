#include "VarCommand.h"

/**
 * Constructor
 */
VarCommand::VarCommand(SymbolTable *symbolTable) {
    this->symbolTable = symbolTable;
}

/**
* The function create a new var and add it to the symbol table
*/
int VarCommand::doCommand(vector<string>::iterator &script) {
    //Count the steps the iterator moved
    int countSteps = 0;
    string varName = (*script);
    //Skip the var name and =
    script += 2;
    countSteps += 2;
    //If need to bind the vay
    if ((*script) == "bind") {
        script++;
        countSteps++;
        //Save the bind path
        string temp = (*script);
        temp = temp.substr(1, (temp.length()) - 2);
        //Add the vat to the symbol table
        this->symbolTable->addPairSymbol(varName, temp);
    } else {
        //Get the value and add to symbole table
        double value = this->symbolTable->getSymbolTable((*script));
        this->symbolTable->addSymbol(varName, value);
    }
    script++;
    countSteps++;
    return countSteps;
}