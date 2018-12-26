#include "CreateExpression.h"

CreateExpression::CreateExpression(SymbolTable* table) {
    this->symbolTable = table;

}

/**
 * The function convert string to expression
 * The function use in shunting yard algo
 * run over all the string and create new expression by the action
 */
Expression *CreateExpression::convertToExpression(string str) {
    string oprtatorList = "";
    stack<Expression *> expressions;
    stack<string> operators;
    int stringLength = 0;
    int resultLength = 0;
   //The function run over all the string and push the numbers to string
   //The function push the operators to stack
   // check if the expresion with () and push to the string
    while (stringLength < str.length()) {
        if (str[stringLength] == '(') {
            operators.push("(");
            // check if have () and push together to the string
        } else if (str[stringLength] == ')') {
            string temp;
            oprtatorList +=",";
            while (operators.top() != "(") {
                temp = operators.top();
                oprtatorList += temp;
                operators.pop();
            }
            operators.pop();
            // check if it operators and push to the string
        } else if (str[stringLength] != '+' && str[stringLength] != '-' &&
                   str[stringLength] != '*' && str[stringLength] != '/') {

            oprtatorList += str[stringLength];
        } else {
             // check if its negative number in the first
            string operatorPush = "";
            if ((stringLength == 0) && (str[stringLength] == '-')) {
                operatorPush = "^";
            } else { // check if its operator or negative number
                char previousChar = str[stringLength - 1];
                char currentChar = str[stringLength];
                if ((currentChar == '-') &&
                    ((previousChar == '*') || (previousChar == '+') ||
                     (previousChar == '/') || (previousChar == '-'))) {
                    operatorPush = "^";
                } else {
                    operatorPush = string(1, str[stringLength]);
                    oprtatorList +=",";
                }
            }
            operators.push(operatorPush);
        }
        stringLength++;
    } // push it all together to the string
    while (!operators.empty()) {
        oprtatorList += operators.top();
        operators.pop();
    } // run all over the string
    while (resultLength < oprtatorList.length()) {
        Expression *newExpression;
        Expression *rightExpression;
        Expression *leftExpression;
        if (oprtatorList[resultLength] != ' ') {
            // if + create plus expression
            if (oprtatorList[resultLength] == '+') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Plus(leftExpression, rightExpression);
                // if * create mult expression
            } else if (oprtatorList[resultLength] == '*') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Mul(leftExpression, rightExpression);
                // if / create div expression
            } else if (oprtatorList[resultLength] == '/') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                resultLength++;
                newExpression = new Div(leftExpression, rightExpression);
                // if - create minus expression
            } else if (oprtatorList[resultLength] == '-') {
                rightExpression = expressions.top();
                expressions.pop();
                leftExpression = expressions.top();
                expressions.pop();
                newExpression = new Minus(leftExpression, rightExpression);
                resultLength++;
                // if ^ create neg expression
            } else if (oprtatorList[resultLength] == '^') {
                newExpression = new Neg(expressions.top());
                resultLength++;
            } else if (isdigit(oprtatorList[resultLength])) {
                string num = "";
                while (((oprtatorList[resultLength]) != ',') && (isdigit(oprtatorList[resultLength]))) {
                    string s = string(1, oprtatorList[resultLength]);
                    num = num + s;
                    resultLength++;
                }
                double d = atof(num.c_str());
                newExpression = new Num(d);
            } else if (oprtatorList[resultLength] != ' ') {
                string tempVar = "";
                while (((oprtatorList[resultLength] != ',') || (isdigit(oprtatorList[resultLength])) ||
                       (isalpha(oprtatorList[resultLength])))&&(resultLength < oprtatorList.length())) {
                    string s = string(1, oprtatorList[resultLength]);
                    tempVar = tempVar + s;
                    resultLength++;
                }
                newExpression = new Var(tempVar, this->symbolTable);
            }
            expressions.push(newExpression);
            this->expressionList.push_back(newExpression);
            Expression *e = expressions.top();
            // end of number make resultLength++;
            if(oprtatorList[resultLength] == ',') {
                resultLength++;
            }
        } else {
            resultLength++;
        }
    }
    // return the result
    return expressions.top();
}

CreateExpression::~CreateExpression() {
    list<Expression*>::iterator itr;
    for (itr=this->expressionList.begin();itr!=this->expressionList.end();itr++){
        delete (*itr);
    }
}