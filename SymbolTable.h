#include <map>
#include <string>
#include "BindPathMap.h"
#include "FlightValueMap.h"

#ifndef PROJECTNUM1_SYMBOLTABLE_H
#define PROJECTNUM1_SYMBOLTABLE_H

using namespace std;

class SymbolTable {
    //map holds the var name and value
    map<string, double> symbolTableMap;
    //map holds var name and the var it binds to
    map <string, string> bindVarMap;
    //contains a map of path and value sampled from the simulator
    FlightValueMap *flightValueMap;
    //contains a map with a var name and his path
    BindPathMap *bindPathMap;

public:
    //Constructor
    SymbolTable(FlightValueMap *flightValueMap, BindPathMap *bindPathMap);

    /**
     * The function return the value of a given key
     */
    double getSymbolTable(string key);

    /**
     * The function receive a string key and double value and set the value of the key in the map
     */
    void setSymbolTable(string key, double value);

    /**
     * The function receive string key and value and add the them to the symbol table
     */
    void addPairSymbol(string key, string value);

    /**
     * The function receive a string key and returns true if the key is in the map else false
     */
    bool isKeyInMap(string key) const;

    /**
     * The function receive a string key and double value and add it to the map
     */
    void addSymbol(string key, double value);

    /**
     * The function receive a string key and return the key path from the bind map
     */
    string getPath(string key) const;

    /**
     * The function returns the symbol table
     */
    map<string, double> getSymbolTableMap() const;

    ~SymbolTable() {
    }
};


#endif //PROJECTNUM1_SYMBOLTABLE_H