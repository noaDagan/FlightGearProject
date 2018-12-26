#include "ConditionParser.h"
#include "IfCommand.h"
#include "LoopCommand.h"

// Constructor empty
ConditionParser::ConditionParser() {
}

// Constructor by CommandMap and SymbolTable
ConditionParser::ConditionParser(CommandMap* commandMap,
                                 SymbolTable *symbolMap) {
    this->symbolTable = symbolMap;
    this->commandMap = commandMap;

}
// Distructor
ConditionParser::~ConditionParser() {
}


/**
 * The function create execute to ConditionParser
 */
int ConditionParser::doCommand(vector<string>::iterator &script) {
    // save the first string if or while
    string ifOrWhile=(*script);
    string condition = "";
    Command *newCommand;
    // advance the iterator to the condition
    script++;
    // run over the condition
    while ((*script) != "{") {
        condition += (*script);
        script++;
    }
    // create boolExpression by a string condition
    this->boolExpression = new BoolExpression(condition,this->symbolTable);
    script++;
    this->createCommand(script);
    // create if or while according to the string and create execute
    if (ifOrWhile == "if") {
        newCommand = new IfCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
    } else if (ifOrWhile == "while") {
        newCommand = new LoopCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
    }
    newCommand->doCommand(script);
    // free boolExpression
//    delete (this->boolExpression);
    return 0;
}

/**
 * The function createCommand run over all the loop and create commands
 */
void ConditionParser::createCommand(vector<string>::iterator &script) {
    ExpressionCommand *expressionCommand;
    // run over all the line in the loop and create commands
    while ((*script) != "}") {
        // save symbolsMap value
        map<string, double> symbolsMap = this->symbolTable->getSymbolTableMap();
        // Check if the key in the symbolTable or commandMap and create command accordingly
        if (this->symbolTable->isKeyInMap(*script)) {
            Command *newCommand = this->commandMap->getCommand(
                    "controlsCommand");
            expressionCommand = new ExpressionCommand(newCommand,
                                                      script,this->symbolTable);
            this->expressionCommandList.push_back(expressionCommand);
        } else if (this->commandMap->isKeyInMap(*script)) {
            expressionCommand = new ExpressionCommand(
                    this->commandMap->getCommand(*script),
                    script,this->symbolTable);
            this->expressionCommandList.push_back(expressionCommand);
        }
        // advance the iterator until the end of the line
        while ((*script) != ";"){
            script++;
        }
        script++;
    }
}

