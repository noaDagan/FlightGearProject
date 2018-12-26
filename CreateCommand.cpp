#include "CreateCommand.h"

// Constructor
CreateCommand::CreateCommand() {
    // Add commands to the command map
    this->checkEndScript = new CheckEndScript();
    this->valueControlForFlight = new ValueControlForFlight();
    this->checkForServerConnection = new CheckForServerConnection();
    this->flightValueMap = new FlightValueMap();
    this->bindMap = new BindPathMap();
    this->symbolTable = new SymbolTable(this->flightValueMap, this->bindMap);
    this->commandMap = new CommandMap();
    this->commandMap->addCommand("openDateServer",
                                 new OpenServerCommand(this->flightValueMap,
                                                       this->checkForServerConnection,
                                                       this->checkEndScript));
    this->commandMap->addCommand("connect", new ConnectCommand(
            this->checkForServerConnection,
            this->valueControlForFlight, this->checkEndScript));
    this->commandMap->addCommand("var", new VarCommand(this->symbolTable));
    this->commandMap->addCommand("controlsCommand", new SetControlCommand(
            this->valueControlForFlight, this->symbolTable));
    this->commandMap->addCommand("if", new ConditionParser(this->commandMap,
                                                           this->symbolTable));
    this->commandMap->addCommand("while", new ConditionParser(this->commandMap,
                                                              this->symbolTable));
    this->commandMap->addCommand("print", new PrintCommand(this->symbolTable));
    this->commandMap->addCommand("sleep", new SleepCommand());
}

/**
 * The function receive a string name of the file
 * The function run over all the text and convert to array
 */
void CreateCommand::lexer(string file) {
    string line;
    int lineLength;
    vector<string> script;
    ifstream inputFile(file);
    // Check if the file open and throw exception if not open
    if (inputFile.is_open()) {
        // run over all the lines in the string
        while (getline(inputFile, line)) {
            string addToVector = "";
            lineLength = 0;
            // run over the line until the end of string and push the string to vector
            while (line[lineLength] != '\0') {
                if ((line[lineLength] == ' ') || (line[lineLength] == '\t')) {
                    if (addToVector != "") {
                        script.push_back(addToVector);
                        addToVector = "";
                    }
                    lineLength++;
                } else {
                    addToVector += line[lineLength];
                    lineLength++;
                }
            }
            if (addToVector != "") {
                script.push_back(addToVector);
                addToVector = "";
            }
            // add ; in the end of all lines
            script.push_back(";");
        }
        // Call to parser with the vector
        parser(script);
    } else {
        throw "ERROR - unable to open file ";
    }
}

/**
 * The function run over all the vector script and create command according to the the key.
 */
void CreateCommand::parser(vector<string> script) {
    Expression *commandExpression;
    Command *newCommand;
    // create iterator and run over all thw vector
    vector<string>::iterator scriptIterator;
    for (scriptIterator = script.begin();
         scriptIterator != script.end(); scriptIterator++) {
        while (((*scriptIterator) != "openDateServer") &&
               (!this->checkForServerConnection)) {
            sleep(10);
        }
        map<string, double> symbolsMap = this->symbolTable->getSymbolTableMap();
        if (this->symbolTable->isKeyInMap(*scriptIterator)) {
            Command *newCommand = this->commandMap->getCommand(
                    "controlsCommand");
            commandExpression = new ExpressionCommand(newCommand,
                                                      scriptIterator,
                                                      this->symbolTable);
            this->expressionList.push_back(commandExpression);
            scriptIterator += commandExpression->calculate(symbolsMap);
        } else if (((*scriptIterator) == "if") ||
                   ((*scriptIterator) == "while")) {
            newCommand = this->commandMap->getCommand(*scriptIterator);
            newCommand->doCommand(scriptIterator);
        } else if (this->commandMap->isKeyInMap(*scriptIterator)) {
            commandExpression = new ExpressionCommand(
                    this->commandMap->getCommand(*scriptIterator),
                    scriptIterator, this->symbolTable);
            this->expressionList.push_back(commandExpression);
            scriptIterator += commandExpression->calculate(symbolsMap);
        }

    }
    this->checkEndScript->setBoolForExit(true);
}

CreateCommand::~CreateCommand() {
    map<string, Command *> tempMap = this->commandMap->getCommandMap();
    map<string, Command *>::iterator itr;
    list<Expression*>::iterator itr2;
    delete this->checkForServerConnection;
    delete this->valueControlForFlight;
    delete this->flightValueMap;
    delete this->bindMap;
    delete this->symbolTable;
    for (itr = tempMap.begin(); itr != tempMap.end(); itr++) {
        delete itr->second;
    }
    for (itr2 = this->expressionList.begin(); itr2 != this->expressionList.end(); itr2++) {
        delete (*itr2);
    }
    delete this->commandMap;
}



