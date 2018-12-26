
#include "BoolExpression.h"

// Constructor
BoolExpression::BoolExpression(string stringCondition,SymbolTable* symbolTable) {
    this->symbolTable=symbolTable;
    this->createBoolExpression(stringCondition);

}

/**
 * The function accepts string and create bool expression
 */
void BoolExpression::createBoolExpression(string boolCondition) {
    CreateExpression *createExpression = new CreateExpression(this->symbolTable);
    // initialize the operator action
    this->action = "";
    string expression = "";
    int strLen = 0;
    // Save the first number in the leftArgument
    while ((boolCondition[strLen] != '<') && (boolCondition[strLen] != '>') &&
           (boolCondition[strLen] != '=') && (boolCondition[strLen] != '!')) {
        expression += boolCondition[strLen];
        strLen++;
    }
    this->leftArgument = createExpression->convertToExpression(expression);
    // Save the operator in the action
    while ((boolCondition[strLen] == '<') || (boolCondition[strLen] == '>') ||
           (boolCondition[strLen] == '=') || (boolCondition[strLen] == '!')) {
        action += boolCondition[strLen];
        strLen++;
    }
    expression = "";
    // Save the second number in the rightArgument
    while ((boolCondition[strLen] != '<') && (boolCondition[strLen] != '>') &&
           (boolCondition[strLen] != '=') && (boolCondition[strLen] != '!') &&
           (strLen < boolCondition.length())) {
        expression += boolCondition[strLen];
        strLen++;
    }
    this->rightArgument = createExpression->convertToExpression(expression);
    // free CreateExpression class
    delete createExpression;
}

/**
 * The function calculate the expression by a symbol table map and return bool
 */
bool BoolExpression::calculateBool(map<string, double> symbolMap) {
    // Check the operator and calculate accordingly
    // if not found operator throw exception
    if (this->action == "<") {
        return ((leftArgument->calculate(symbolMap)) <
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">") {
        return ((leftArgument->calculate(symbolMap)) >
                rightArgument->calculate(symbolMap));
    } else if (this->action == "<=") {
        return ((leftArgument->calculate(symbolMap)) <=
                rightArgument->calculate(symbolMap));
    } else if (this->action == ">=") {
        return ((leftArgument->calculate(symbolMap)) >=
                rightArgument->calculate(symbolMap));
    } else if (this->action == "==") {
        return ((leftArgument->calculate(symbolMap)) ==
                rightArgument->calculate(symbolMap));
    } else if (this->action == "!=") {
        return ((leftArgument->calculate(symbolMap)) !=
                rightArgument->calculate(symbolMap));
    } else {
        throw "ERROR - invalid argument";
    }
}

// Distructor
BoolExpression::~BoolExpression() {
}