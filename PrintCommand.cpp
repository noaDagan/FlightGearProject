#include <iostream>
#include "PrintCommand.h"
#include "Utility.h"
#include "ExpressionFactory.h"

PrintCommand::PrintCommand(DataBase &givenDataBase) {
    this->dataBase = &givenDataBase;
}

void PrintCommand::doCommand(vector<string>::iterator &it) {
    string toPrint = *it++;
    if (toPrint[0] == '"') {
        // delete " and then print
        toPrint.erase(0, 1);
        toPrint.erase(toPrint.length() - 1, 1);
    } else {
        // calculate expression(or var) and then print
        ExpressionFactory factory(*this->dataBase);
        toPrint = to_string(factory.makeExpression(toPrint)->calculate());
    }
    cout << toPrint << endl;
}
