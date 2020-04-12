#include "IfCommand.h"
#include "Utility.h"

IfCommand::IfCommand(unordered_map<string, Command *> &commands, DataBase &db)
        : ConditionCommand(commands, db) {
}

void IfCommand::doCommand(vector<string>::iterator &it) {
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
    ++it;
    if (parseCondition(firstExpr, conditionOp, secExpr)) {
        doAll(it);
        // it = }
        ++it;
    } else {
        // skip the 'if block'
        while (countParenth != 0) {
            if (*it == "{") {
                countParenth++;
            }

            if (*it == "}") {
                countParenth--;
            }
            ++it;
        }
    }
}
