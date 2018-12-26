#include "SetControlCommand.h"

//Constructor
SetControlCommand::SetControlCommand(
        ValueControlForFlight *v,
        SymbolTable *s) {
    this->symbolTable = s;
    this->valueControlForFlight = v;
}

/**
 * The function create the string command and update the valueControlForFlight
 */
int SetControlCommand::doCommand(vector<string>::iterator &script) {
    //Save the var name
    string varName = (*script);
    script++;
    //Get the value of the var and update the symbol map
    double valueForVar = atof((*script).c_str());
    string valuePath = to_string(valueForVar);
    this->symbolTable->setSymbolTable(varName, valueForVar);
    //Get the path and create the string command
    string path = this->symbolTable->getPath(varName);
    path = path.substr(1,path.length()-1);
    string stringControl = "set /" + path + " " + valuePath + "\r\n";
    //While the previus command didnt execute wait
    while (!this->valueControlForFlight->checkIfStringEmpty()){
        sleep(1);
    }
    //Set the string of the command
    this->valueControlForFlight->setControlString(stringControl);
    return 0;
}