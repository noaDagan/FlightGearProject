#include "Expression.h"
#include <stack>
#include <string>
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Var.h"
#include "Neg.h"
#include "SymbolTable.h"
#ifndef PROJECTNUM1_CREATEEXPRESSION_H
#define PROJECTNUM1_CREATEEXPRESSION_H

using namespace std;

class CreateExpression {
    SymbolTable* symbolTable;
    list<Expression*> expressionList;
public:
    // Constructor
    CreateExpression(SymbolTable* symbolTable);

    /**
     * The function convert string to expression
    * The function use in shunting yard algo
    * run over all the string and create new expression by the action
    */
    Expression *convertToExpression(string str);

    ~CreateExpression();

};


#endif //PROJECTNUM1_CREATEEXPRESSION_H
