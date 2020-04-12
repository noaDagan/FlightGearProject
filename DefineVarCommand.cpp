#include <map>
#include "DefineVarCommand.h"
#include "ExpressionFactory.h"
#include "AssignCommand.h"
#include "Utility.h"

DefineVarCommand::DefineVarCommand(DataBase &givenDataBase, DataWriterClient &writer) {
    this->dataBase = &givenDataBase;
    this->dataWriter = &writer;

}

void DefineVarCommand::doCommand(vector<string>::iterator &it) {
    string varName = *it;
    string checkSecStr = *(it + 1);

    if (Utility::isCommand(varName) || Utility::isCommand(checkSecStr)) {
        // not a valid parameter !!
        __throw_invalid_argument("invalid argument");
    }
    double value;
    if (checkSecStr == "bind") {
        // it: varName | bind | address
        value = 0;
        string address = *(it += 2);
        if (Utility::isCommand(address)) {
            // not a valid parameter !!
            __throw_invalid_argument("invalid argument");
        }
        this->dataBase->addToBind(varName, address);
        this->dataBase->addToSymbol(varName, value); // restart value to zero
        it++;
    } else {
        this->dataBase->addToSymbol(varName, 0); // add new var to symbTbl
        AssignCommand assignCommand = AssignCommand(*dataBase, *this->dataWriter);
        assignCommand.doCommand(it); // assign the value to the new var
    }
}
