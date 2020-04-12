#include "AssignCommand.h"
#include "ExpressionFactory.h"
#include "Utility.h"

AssignCommand::AssignCommand(DataBase &givenDataBase,
                             DataWriterClient &writer) {
    this->dataBase = &givenDataBase;
    this->dataWriter = &writer;
}

void AssignCommand::doCommand(vector<string>::iterator &it) {
    string varName = *it;
    string expr = *(it + 1);
    if (Utility::isCommand(varName) || Utility::isCommand(expr)) {
        // not a valid parameter !!
        __throw_invalid_argument("invalid argument");
    }
    double value;
    ExpressionFactory expressionFactory = ExpressionFactory(*dataBase);
    value = expressionFactory.makeExpression(expr)->calculate();
    if (this->dataBase->isVarExistBind(varName)) {
        // write to simulator, symbolTbl updated by simulator
        string val = to_string(value);
        string path = this->dataBase->getAddressBind(varName);
        string buffer = "set " + path + " " + val + "\r\n";
        this->dataWriter->write(buffer.c_str());
    } else {
        this->dataBase->updateSymbol(varName, value);
    }
    it += 2;
}
