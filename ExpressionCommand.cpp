#include "ExpressionCommand.h"

// Constructor
ExpressionCommand::ExpressionCommand(Command *c,
                                     vector<string>::iterator &script, SymbolTable* table) {
    this->command = c;
    this->script = script;
    this->symbolTable = table;
}

/**
 * The function calculate the expression by the value in the map
 */
double ExpressionCommand::calculate(map<string, double> &assignment) {
    // save the step in the script and return in the end of the function
    int countSteps = 0;
    string expression;
    int resultExpression;
    vector<string> newVector;
    Expression *newExpression;
    vector<string>::iterator tempItr;
    tempItr = script;
    CreateExpression *createExpression = new CreateExpression(this->symbolTable);
    // check command type and create expression accordingly
    if (((*script) == "openDateServer") || ((*script) == "sleep")) {
        script++;
        countSteps++;
        // run over all the line and push the value to the vector
        while ((*this->script) != ";") {
            expression = (*script);
            newExpression = createExpression->convertToExpression(expression);
            resultExpression = (int) newExpression->calculate(assignment);
            newVector.push_back(to_string(resultExpression));
            script++;
            countSteps++;
        }
        vector<string>::iterator itr;
        itr=newVector.begin();
        // make execute to the specific command
        this->command->doCommand(itr);
    } else if ((*script) == "connect") {
        // run over all the connect script and push the value to the vector
        script++;
        countSteps++;
        string ip = (*script);
        newVector.push_back(ip);
        script++;
        countSteps++;
        expression = (*script);
        newExpression = createExpression->convertToExpression(expression);
        resultExpression = (int) newExpression->calculate(assignment);
        newVector.push_back(to_string(resultExpression));
        vector<string>::iterator itr;
        itr=newVector.begin();
        // make execute to the connect command value
        this->command->doCommand(itr);
    } else if ((*script) == "print") {
        script++;
        countSteps++;
        // if the first char is " send it to print command
        if ((*script)[0] == '\"') {
            this->command->doCommand(script);
        } else  {
            // run over all the print script and create expression
            while ((*this->script) != ";") {
                expression = (*script);
                newExpression = createExpression->convertToExpression(expression);
                resultExpression = (int) newExpression->calculate(assignment);
                newVector.push_back(to_string(resultExpression));
                script++;
                countSteps++;
            }
            vector<string>::iterator itr;
            itr=newVector.begin();
            this->command->doCommand(itr);
        }
    } else if ((*script)=="var"){
        // make execute to var
        script++;
        countSteps++;
        countSteps+=this->command->doCommand(script);
    } else {
        newVector.push_back(*this->script);
        string expressin = "";
        this->script += 2;
        countSteps += 2;
        // run over all the line
        while ((*this->script) != ";") {
            expressin += (*this->script);
            this->script++;
            countSteps++;
        }
        newExpression = createExpression->convertToExpression(expressin);
        double result = newExpression->calculate(assignment);
        newVector.push_back(to_string(result));
        vector<string>::iterator newVectorIt;
        newVectorIt = newVector.begin();
        this->command->doCommand(newVectorIt);
    }
    this->script=tempItr;
    delete (createExpression);
    // delete the steps in the script
    return countSteps;
}

