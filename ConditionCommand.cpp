#include "ConditionCommand.h"
#include "ExpressionFactory.h"

bool ConditionCommand::parseCondition(string firstExpr, string op,
                                      string secExpr) {
    ExpressionFactory factory = ExpressionFactory(*dataBase);
    double firstValue = factory.makeExpression(firstExpr)->calculate();
    double secValue = factory.makeExpression(secExpr)->calculate();

    if (op == "!=") {
        return firstValue != secValue;
    } else if (op == "==") {
        return firstValue == secValue;
    } else if (op == "<=") {
        return firstValue <= secValue;
    } else if (op == ">=") {
        return firstValue >= secValue;
    } else if (op == "<") {
        return firstValue < secValue;
    } else if (op == ">") {
        return firstValue > secValue;
    } else {
        __throw_invalid_argument("invalid condition operator");
    }

}

void ConditionCommand::doAll(vector<string>::iterator &it) {
    while (*it != "}") {
        if (this->commMap->find(*it) == this->commMap->end()) {
            __throw_invalid_argument("invalid command");
        }
        Command *currComm = this->commMap->at(*it++);
        currComm->doCommand(it);
    }
}
