#ifndef FLIGHTSIMULATOR_DATABASE_H
#define FLIGHTSIMULATOR_DATABASE_H

#include <string>
#include <unordered_map>

using namespace std;

/**
 * dataBase of all vars, include bind table for vars bind to simulator
 */
class DataBase {
    unordered_map<string, string> bindTable;
    unordered_map<string, double> symbolTable;
public:
    /**
     * add to bind map
     * @param varName
     * @param address
     */
    void addToBind(string varName, string address);

    /**
     * add to symbol table
     * @param varName
     * @param value
     */
    void addToSymbol(string varName, double value);

    /**
     * update bind table value
     * @param varName
     * @param address
     */
    void updateBind(string &varName, string &address);

    /**
     * update symbol table value
     * @param varName
     * @param value
     */
    void updateSymbol(string &varName, double value);

    /**
     * return address of bind by var name
     * @param varName
     * @return
     */
    string getAddressBind(string varName);

    /**
     * get value of var from symbol table
     * @param varName
     * @return value of var
     */
    double getValueSymbol(string varName);

    /**
     * check if var exist in bind table
     * @param varName
     * @return true if exist, false otherwise
     */
    bool isVarExistBind(string varName);

    /**
     * check if var exist in symbol table
     * @param varName
     * @return true if exist, false otherwise
     */
    bool isVarExistSymbol(string varName);

    /**
     *
     * @return iterator to symbol table begin
     */
    unordered_map<string, double>::iterator getIteratorSymb();

    /**
     *
     * @return iterator to symbol table end
     */
    unordered_map<string, double>::iterator getEndIteratorSymb();

    /**
     *
     * @return iterator to bind table begin
     */
    unordered_map<string, string>::iterator getIteratorBind();

    /**
     *
     * @return iterator to bind table end
     */
    unordered_map<string, string>::iterator getEndIteratorBind();

    /**
     *
     * @return symbol table
     */
    unordered_map<string, double> &getSymbolTbl();

    /**
     *
     * @return bind table
     */
    unordered_map<string, string> &getBindTbl();
};

#endif //FLIGHTSIMULATOR_DATABASE_H