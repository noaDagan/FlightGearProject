#include "WhileCommand.h"
#include "Utility.h"

WhileCommand::WhileCommand(unordered_map<string, Command *> &commands,
                           DataBase &db) : ConditionCommand(commands, db) {

}

void WhileCommand::doCommand(vector<string>::iterator &it) {
    string firstExpr = *it++;
    string conditionOp = *it++;
    string secExpr = *it++;
    if (Utility::isCommand(firstExpr) || Utility::isCommand(conditionOp) ||
        Utility::isCommand(secExpr)) {
        // not a valid parameter !!
        __throw_invalid_argument("invalid argument");
    }
    // it = {
    int countParenth = 1;
    ++it; // it = first command
    while (parseCondition(firstExpr, conditionOp, secExpr)) {
        auto temp = it;
        doAll(temp);
    }

    // while loop ended
    while (countParenth != 0) {
        if (*it == "{") {
            countParenth++;
        }
        if (*it == "}") {
            countParenth--;
        }
        ++it;
    }
    /*while (*it != "}") {
        ++it;
    }*/
}
