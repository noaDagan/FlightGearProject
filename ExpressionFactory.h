#ifndef FLIGHTSIMULATOR_SHUNTINGYARD_H
#define FLIGHTSIMULATOR_SHUNTINGYARD_H

#include "Expression.h"
#include "DataBase.h"
#include <string>
#include <list>

using namespace std;

/**
 * expression factory - create expressions
 */
class ExpressionFactory {
    map<string, int> opPrecedence;
    DataBase *dataBase;
    list<Expression *> toDelete;

public:
    /**
     * constructor
     * @param dataBase
     */
    ExpressionFactory(DataBase &dataBase);

    /**
     * make expression from given string
     * using shunting yard algorithm
     * @param expr
     * @return Expression object represented by the string given
     */
    Expression *makeExpression(string &expr);

    ~ExpressionFactory();

private:
    /**
     * create map of operators precedences.
     * init opPrecedence map (member of this factory)
     * @param opPrecedence
     */
    void precedenceMapCreator(map<string, int> &opPrecedence);

    /**
     * gets string representing expression, convert it to postfix expression
     * @param expr
     * @return the new order of the strings in a queue
     */
    queue<string> getPostfixExpr(string &expr);

    /**
     * if there is var in the expression,
     * get it's value from dataBase and replace
     * @param expr
     */
    void getValues(string &expr);

};

#endif //FLIGHTSIMULATOR_SHUNTINGYARD_H