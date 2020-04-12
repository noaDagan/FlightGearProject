#include "DataBase.h"
#include <iostream>

void DataBase::addToBind(string varName, string address) {
    bindTable.insert(pair<string, string>(varName, address));
}

void DataBase::addToSymbol(string varName, double value) {
    symbolTable.insert(pair<string, double>(varName, value));
}

void DataBase::updateBind(string &varName, string &address) {
    if (!isVarExistBind(varName)) {
        __throw_invalid_argument(
                "can't update bind for this var - wasn't initialized");
    }
    bindTable[varName] = address;
}

void DataBase::updateSymbol(string &varName, double value) {
    if (!isVarExistSymbol(varName)) {
        __throw_invalid_argument(
                "can't update symbol for this var - wasn't initialized");
    }
    symbolTable[varName] = value;
}

string DataBase::getAddressBind(string varName) {
    if (!isVarExistBind(varName)) {
        __throw_invalid_argument(
                "can't get address for this var - wasn't initialized");
    }
    return bindTable.find(varName)->second;
}

double DataBase::getValueSymbol(string varName) {
    if (!isVarExistSymbol(varName)) {
        __throw_invalid_argument(
                "can't get value for this var - wasn't initialized");
    }
    return symbolTable.find(varName)->second;
}

bool DataBase::isVarExistBind(string varName) {
    // if varName exists in map (count==1) --> return true
    return bindTable.count(varName) != 0;
}

bool DataBase::isVarExistSymbol(string varName) {
    // if varName exists in map (count==1) --> return true
    return symbolTable.count(varName) != 0;
}

unordered_map<string, double>::iterator DataBase::getIteratorSymb() {
    unordered_map<string, double>::iterator it;
    it = symbolTable.begin();
    return it;
}

unordered_map<string, double>::iterator DataBase::getEndIteratorSymb() {
    auto it = symbolTable.end();
    return it;
}

unordered_map<string, double> &DataBase::getSymbolTbl() {
    return symbolTable;
}

unordered_map<string, string> &DataBase::getBindTbl() {
    return bindTable;
}

unordered_map<string, string>::iterator DataBase::getIteratorBind() {
    unordered_map<string, string>::iterator it;
    it = bindTable.begin();
    return it;
}

unordered_map<string, string>::iterator DataBase::getEndIteratorBind() {
    auto it = bindTable.end();
    return it;
}
