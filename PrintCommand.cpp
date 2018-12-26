#include "PrintCommand.h"

//Constructor
PrintCommand::PrintCommand(SymbolTable *symbolTable) {
    this->symbolTable = symbolTable;
}

/**
 * The function print the message ot receive
 */
int PrintCommand::doCommand(vector<string>::iterator &script) {
    string printString = "";
    // If the message is a string get the string
    if ((*script)[0] == '\"') {
        while ((*script) != ";") {
            printString += (*script);
            script++;
        }
        int sizeString = printString.length();
        printString = printString.substr(1,sizeString - 2);
        // Else get the number and print it
    } else {
        printString = (*script);
    }
    cout << printString << endl;
    script++;
    return 0;
}