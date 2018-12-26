#include "Expression.h"
#include "CreateExpression.h"
#include <map>

#ifndef PROJECTNUM1_BOOLEXPRESSION_H
#define PROJECTNUM1_BOOLEXPRESSION_H

class BoolExpression {
    // Members
    Expression *leftArgument;
    Expression *rightArgument;
    string action;
    SymbolTable* symbolTable;
public:
    // Constructor
    BoolExpression(string stringCondition,SymbolTable* symbolTable);

    // Distructor
    ~BoolExpression();

    /**
      * The function accepts string and create bool expression
     */
    void createBoolExpression(string boolCondition);

    /**
     * The function calculate the expression by a symbol table map and return bool
     */
    bool calculateBool(map<string, double> symbolMap);

};


#endif //PROJECTNUM1_BOOLEXPRESSION_H
