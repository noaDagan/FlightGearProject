#include <fstream>
#include <algorithm>
#include "Controller.h"
#include "Utility.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "DefineVarCommand.h"
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "AssignCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "EnterC.h"

Controller::Controller() {
    this->dataBase = new DataBase();
    this->dataReader = new DataReaderServer(this->dataBase);
    // create map of commands
    commandMap["openDataServer"] = new OpenServerCommand(*this->dataReader,
                                                         *this->dataBase);
    commandMap["connect"] = new ConnectCommand(this->dataWriter,
                                               *this->dataBase);
    commandMap["var"] = new DefineVarCommand(*this->dataBase, this->dataWriter);
    commandMap["assign"] = new AssignCommand(*this->dataBase, this->dataWriter);
    commandMap["sleep"] = new SleepCommand(*this->dataBase);
    commandMap["print"] = new PrintCommand(*this->dataBase);
    commandMap["while"] = new WhileCommand(this->commandMap, *this->dataBase);
    commandMap["if"] = new IfCommand(this->commandMap, *this->dataBase);
    commandMap["enterC"] = new EnterC();
}

void Controller::run(string fileName) {
    vector<string> commands = lexer(fileName);
    parser(commands);
}

// returns vector of lines of the file
vector<string> Controller::lexer(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.good()) {
        __throw_invalid_argument("ERROR opening file");
    }
    string line;
    vector<string> result;
    while (getline(inputFile, line)) {
        // while there are lines to read, split and add to the vector
        vector<string> afterSplit = splitLine(line);
        // concat the vector to result's vector
        result.insert(result.end(), afterSplit.begin(), afterSplit.end());
    }
    inputFile.close();
    return result;
}

void Controller::parser(vector<string> lines) {
    auto it = lines.begin();
    while (it != lines.end()) {
        // while there are still commands - read and execute
        if (!Utility::isCommand(*it)) {
            __throw_invalid_argument("invalid argument");
        }
        string commandName = *it++;
        Command *currComm = this->commandMap.at(commandName);
        currComm->doCommand(it);
        if (commandName == "connect") {
            // wait to connection before continue
            while (!this->dataWriter.isConnected) {
                usleep(100);
            }
        }
    }
}

Controller::~Controller() {
    for (auto &it : commandMap) {
        delete (it.second);
    }
    this->dataReader->closeSocket();
    this->dataWriter.closeSocket();
    delete this->dataBase;
    delete this->dataReader;

}

vector<string> Controller::splitLine(string line) {
    vector<string> result;
    string command;

    // read until first " " -> the command
    unsigned int i = 0;
    char temp = line[i];
    while (!Utility::isSeparator(temp)) {
        command += temp;
        temp = line[++i];
    }
    result.push_back(command);
    if (isConditionCommand(command)) {
        conditionSplit(line, result, i, temp);
    } else if (isRegularCommand(command)) {
        regularSplit(line, result, i, temp);
    } else if (command == "}" || command == "{") {
        // already pushed
    } else if (isPrintCommand(command)) {
        printSplit(line, result, i, temp);
    } else if (command == "enterC") {
        return result;
    } else {
        // "command" is var name for assignment
        result.insert(result.begin(), "assign");
        assignmentSplit(line, result, i, temp);
    }
    return result;
}

void Controller::regularSplit(const string &line, vector<string> &result,
                              unsigned int i,
                              char temp) const {
    // now read the rest of the line -> the parameters of the command
    string param;
    bool prevIsSeparator = false;
    for (unsigned int j = i + 1; j < line.length(); ++j) {
        temp = line[j];
        if (Utility::isPartOfNum(temp)) {
            if (prevIsSeparator) {
                // if last character was separator,
                // check if last input to param was operator or digit
                unsigned long last = param.size();
                if (last > 0 && !Utility::isOperator(param[last - 1])) {
                    // last input was digit -> new param
                    result.push_back(param);
                    param = "";
                }
                prevIsSeparator = false;
            }
            param += temp;
            continue;
        }

        if (Utility::isOperator(temp) || Utility::isParentheses(temp)) {
            param += temp;
            if (prevIsSeparator) {
                prevIsSeparator = false;
            }
            continue;
        }

        if (Utility::isSeparator(temp)) {
            prevIsSeparator = true;
            continue;
        }

        if (temp == ',' || temp == '"') {
            result.push_back(param);
            param = "";
            if (prevIsSeparator) {
                prevIsSeparator = false;
            }
            continue;
        }

        if (temp == '=') {
            result.push_back(param);
            param = "";
            if (prevIsSeparator) {
                prevIsSeparator = false;
            }
            continue;
        }

        // not a number or operator or separator -> is a word
        if (Utility::isPartOfWord(temp)) {
            param += temp;
        }

        // if temp == '"' - not in any if, continue to next char
    }
    if (!param.empty()) {
        result.push_back(param);
    }
}

void
Controller::conditionSplit(const string &line, vector<string> &result,
                           unsigned int i,
                           char temp) const {
    string condition;
    bool prevIsOp = false;
    for (unsigned int j = i + 1; j < line.length(); ++j) {
        temp = line[j];
        if (temp == '{') {
            result.push_back(condition);
            condition = temp;
            continue;
        }
        if (Utility::isPartOfCondOp(temp)) {
            if (prevIsOp) {
                condition += temp;
            } else {
                result.push_back(condition);
                condition = temp;
            }
            prevIsOp = true;
        } else if (!Utility::isSeparator(temp)) {
            // number or digit
            if (prevIsOp) {
                result.push_back(condition);
                condition = temp;
                prevIsOp = false;
            } else {
                condition += temp;
            }
        }
    }
    result.push_back(condition);
    delRedundantParentheses(result);
}

void
Controller::assignmentSplit(const string &line, vector<string> &result,
                            unsigned int i,
                            char temp) const {
    string value;
    for (unsigned int j = i + 1; j < line.length(); ++j) {
        temp = line[j];
        if (!Utility::isSeparator(temp) && temp != '=') {
            value += temp;
        }
    }
    result.push_back(value);
}

void Controller::printSplit(const string &line, vector<string> &result,
                            unsigned int i,
                            char temp) const {
    string param;
    for (unsigned int j = i + 1; j < line.length(); ++j) {
        temp = line[j];
        param += temp;
    }
    if (!param.empty()) {
        result.push_back(param);
    }
}

bool Controller::isConditionCommand(const string &command) const {
    return command == "while" || command == "if";
}

bool Controller::isRegularCommand(const string &command) const {
    return command == "var" || command == "openDataServer" ||
           command == "connect" || command == "sleep";
}

bool Controller::isPrintCommand(const string &command) const {
    return command == "print";
}

void Controller::delRedundantParentheses(vector<string> &vector) const {
    string firstExpr = vector.at(1);
    long leftParentheses = count(firstExpr.begin(), firstExpr.end(), '(');
    long rightParentheses = count(firstExpr.begin(), firstExpr.end(), ')');
    if (leftParentheses > rightParentheses) {
        // format: (condition), make: condition
        firstExpr.erase(0, 1); // delete first '('
        string secExpr = vector.at(3);
        secExpr.erase(secExpr.size() - 1, 1); // delete last ')'
        vector[1] = firstExpr;
        vector[3] = secExpr;
    }
}

