#include "SymbolTable.h"

//Constructor
SymbolTable::SymbolTable(FlightValueMap *f, BindPathMap *b) {
    this->flightValueMap = f;
    this->bindPathMap = b;
}

/**
 * The function return the value of a given key
 */
double SymbolTable::getSymbolTable(string key) {
    // Check if the kay is in the symbol map
    if (this->symbolTableMap.count(key)) {
        // Check if the  key has a path and if the path sampled from the simulator
        if ((this->bindPathMap->isKeyInMap(key)) &&
            (this->flightValueMap->isKeyInMap(this->bindPathMap->getBindMap(key)))) {
            // set the key value from the flightValueMap
            double tempValue = this->flightValueMap->getValue(this->bindPathMap->getBindMap(key));
            this->symbolTableMap.find(key)->second = tempValue;
        }
        return this->symbolTableMap.find(key)->second;
        // Else throe Error
    } else {
        throw "Error - key not found ";
    }
}

/**
 * The function receive a string key and double value and set the value of the key in the map
 */
void SymbolTable::setSymbolTable(string key, double value) {
    // If bindvarmap table contains the kay-the key is bind to another var
    if (this->bindVarMap.count(key)) {
        // Update the key valu and the valu of the vat it binds to
        this->symbolTableMap.find(key)->second = value;
        this->symbolTableMap.find(
                this->bindVarMap.find(key)->second)->second = value;
        // Else if the var is in the map unpdate the var valu
    } else if (this->bindPathMap->isKeyInMap(key)) {
        this->symbolTableMap.find(key)->second = value;
    } else {
        throw "Error - key not found ";
    }
}

/**
 * The function receive string key and value and add the them to the symbol table
 */
void SymbolTable::addPairSymbol(string key, string value) {
    // Add the key and valu to the bind map
    this->bindPathMap->addBindToMap(key, value);
    // If the valu id in flightValueMap add the var to the map
    if (this->flightValueMap->isKeyInMap(value)) {
        this->symbolTableMap.insert(pair<string, double>(key, 0));
        // If the value is in the symbol table -the valu in another var
    } else if (this->symbolTableMap.count(value)) {
        // Get the value of the valu vay and update the key
        this->symbolTableMap.insert(pair<string, double>(key, this->symbolTableMap.find(value)->second));
        //Bind the vars
        this->bindVarMap.insert(pair<string, string>(key, value));
        this->bindVarMap.insert(pair<string, string>(value, key));
        // Else add the var to the map
    } else {
        this->bindPathMap->addBindToMap(key, value);
        this->symbolTableMap.insert(pair<string, double>(key, 0));
    }
}

/**
 * The function receive a string key and returns true if the key is in the map else false
 */
bool SymbolTable::isKeyInMap(string key) const {
    // Check if the receive key is the map
    if (this->symbolTableMap.count(key)) {
        return true;
    }
    return false;
}

/**
 * The function receive a string key and double value and add it to the map
 */
void SymbolTable::addSymbol(string key, double value) {
    this->symbolTableMap.insert(pair<string, double>(key, value));
}

/**
 * The function receive a string key and return the key path from the bind map
 */
string SymbolTable::getPath(string key) const {
    // check is the receive key has a path and return it
    if (this->bindPathMap->isKeyInMap(key)) {
        return this->bindPathMap->getBindMap(key);
        // check if the var is bind to another var and return his path
    } else if (this->bindVarMap.count(key)) {
        return this->bindPathMap->getBindMap(this->bindVarMap.find(key)->second);
    } else {
        throw "ERROR - path not found";
    }
}

/**
 * The function returns the symbol table
 */
map<string, double> SymbolTable::getSymbolTableMap() const {
    // If the map is not emxpty return the map
    if (!this->symbolTableMap.empty()) {
        return this->symbolTableMap;
    } else {
        map<string, double> temp;
        return temp;
    }
}