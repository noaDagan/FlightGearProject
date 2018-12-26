#include <string.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include "Command.h"
#include <map>
#include "Expression.h"
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "VarCommand.h"
#include "SymbolTable.h"
#include "FlightValueMap.h"
#include "BindPathMap.h"
#include "Expression.h"
#include "CheckForServerConnection.h"
#include "ValueControlForFlight.h"
#include "SetControlCommand.h"
#include "ConditionParser.h"
#include "CommandMap.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "CheckEndScript.h"

#ifndef PROJECTNUM1_TEMPLEX_H
#define PROJECTNUM1_TEMPLEX_H


using namespace std;

class CreateCommand {
    // Members
    ValueControlForFlight *valueControlForFlight;
    CheckEndScript *checkEndScript;
    SymbolTable *symbolTable;
    FlightValueMap *flightValueMap;
    BindPathMap *bindMap;
    CheckForServerConnection *checkForServerConnection;
    CommandMap *commandMap;
    list<Expression*> expressionList;
public:
    //Constructor
    CreateCommand();
    ~CreateCommand();

    /**
    * The function receive a string name of the file
    * The function run over all the text and convert to array
     */
    void lexer(string file);

    /**
    * The function run over all the vector script and create command according to the the key.
    */
    void parser(vector<string> script);
};


#endif //PROJECTNUM1_TEMPLEX_H
