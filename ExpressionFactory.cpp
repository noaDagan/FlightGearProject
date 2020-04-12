#include "ExpressionFactory.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Utility.h"
#include "Neg.h"
#include <stack>
#include <queue>
#include <map>

using namespace std;

ExpressionFactory::ExpressionFactory(DataBase &dataBase) {
    precedenceMapCreator(this->opPrecedence);
    this->dataBase = &dataBase;
}

Expression *ExpressionFactory::makeExpression(string &expr) {
    getValues(expr);
    queue<string> postfixExpr = getPostfixExpr(expr);
    stack<Expression *> expressions;
    bool first = true;
    bool firstIsNeg = false;
    while (!postfixExpr.empty()) {
        string curr = postfixExpr.front();
        postfixExpr.pop();
        bool isNeg = false;
        if (curr == "n") {
            isNeg = true;
            if (first) {
                first = false;
                firstIsNeg = true;
                continue;
            }
            if (firstIsNeg) {
                firstIsNeg = false;
                continue;
            }
        }
        first = false;
        if (!Utility::isOperator(curr) && !isNeg) {
            // curr is number
            Expression *num = new Number(stod(curr));
            expressions.push(num);
            toDelete.push_back(num);
        } else {
            // curr is operator
            if (expressions.size() < 2) {
                if (!isNeg) {
                    // not an unary operator, needs at least two numbers
                    __throw_invalid_argument("invalid expression");
                }
            }
            if (isNeg) {
                // pop the expresssion, neagate it and push back.
                Expression *unaryExpr = expressions.top();
                expressions.pop();
                Expression *temp = new Neg(unaryExpr);
                expressions.push(temp);
                toDelete.push_back(temp);
                continue;
            }
            // if not neg but operator - binary operator.
            Expression *right = expressions.top();
            expressions.pop();
            Expression *left = expressions.top();
            expressions.pop();

            if (curr == "+") {
                Expression *temp = new Plus(left, right);
                expressions.push(temp);
                toDelete.push_back(temp);
            } else if (curr == "-") {
                Expression *temp = new Minus(left, right);
                expressions.push(temp);
                toDelete.push_back(temp);
            } else if (curr == "*") {
                Expression *temp = new Mult(left, right);
                expressions.push(temp);
                toDelete.push_back(temp);
            } else if (curr == "/") {
                Expression *temp = new Div(left, right);
                expressions.push(temp);
                toDelete.push_back(temp);
            }
        }
    }
    return expressions.top();
}

queue<string> ExpressionFactory::getPostfixExpr(string &expr) {
    stack<string> opStack;
    queue<string> result;
    bool isFirst = true;
    bool isSecOp = false;
    string::iterator it;
    for (it = expr.begin(); it != expr.end(); ++it) {
        string currNum;
        while (it != expr.end() && Utility::isPartOfNum(*it)) {
            // read all characters of number, including '.' for double
            currNum += *it;
            ++it;
        }
        if (!currNum.empty()) {
            isFirst = false; // first is number, it is no longer first.
            isSecOp = false;
            result.push(currNum);
            // flag false
        }
        if (it == expr.end()) {
            // finished reading
            break;
        }
        char currOp = *it;
        if (isFirst || isSecOp) {
            if (currOp == '-') {
                currOp = 'n';
            }
            isFirst = false;
            isSecOp = false;
        }
        switch (currOp) {
            case '(': {
                isSecOp = true;
                string temp;
                temp += currOp;
                opStack.push(temp);
                break;
            }
            case ')': {
                string str = opStack.top();
                while (!opStack.empty() && str != "(") {
                    result.push(str);
                    opStack.pop();
                    if (!opStack.empty()) {
                        str = opStack.top();
                    }
                }
                opStack.pop(); // pop "("
                break;
            }
            default: {
                // currOp == operator
                isSecOp = true;
                string o1;
                o1 += currOp;
                string o2;
                while (!opStack.empty()) {
                    /* while opStack contains operators with higher precedence,
                    pop to queue*/
                    o2 = opStack.top();
                    if (opPrecedence.find(o1)->second >
                        opPrecedence.find(o2)->second) {
                        break;
                    }
                    result.push(o2);
                    opStack.pop();
                }
                opStack.push(o1);
            }
        }
    }
    while (!opStack.empty()) {
        // push to queue remaining operators
        result.push(opStack.top());
        opStack.pop();
    }
    return result;
}

void ExpressionFactory::precedenceMapCreator(map<string, int> &opPrecedence) {
    opPrecedence["("] = 0;
    opPrecedence["+"] = 1;
    opPrecedence["-"] = 1;
    opPrecedence["*"] = 2;
    opPrecedence["/"] = 2;
    opPrecedence["n"] = 3; // negative expression
}

void ExpressionFactory::getValues(string &expr) {
    auto begin = dataBase->getIteratorSymb();
    auto end = dataBase->getEndIteratorSymb();
    for (; begin != end; ++begin) {
        string varName = begin->first;
        unsigned long found = expr.find(varName);
        if (found != string::npos) {
            unsigned long length = varName.length();
            expr.replace(found, length, to_string(begin->second));
        }
    }
}

ExpressionFactory::~ExpressionFactory() {
    for (list<Expression *>::iterator it = this->toDelete.begin();
         it != this->toDelete.end(); ++it) {
        delete *it;
    }
}
