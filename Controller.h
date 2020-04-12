#ifndef FLIGHTSIMULATOR_RUNSIMULATOR_H
#define FLIGHTSIMULATOR_RUNSIMULATOR_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Command.h"
#include "DataBase.h"
#include "DataReaderServer.h"
#include "DataWriterClient.h"

using namespace std;

/**
 * controlling the simulator
 */
class Controller {
    unordered_map<string, Command *> commandMap;
    DataBase *dataBase;
    DataReaderServer *dataReader;
    DataWriterClient dataWriter;
public:
    /***
     * constructor
     */
    Controller();

    /**
     * run the program
     * @param fileName
     */
    void run(string fileName);

    /**
     * destructor
     */
    ~Controller();

private:

    /**
     * read lines in filename input, divide it to commands
     * @param fileName
     * @return vector of commands
     */
    vector<string> lexer(string fileName);

    /**
     * read all commands from given vector and excute them
     * @param lines
     */
    void parser(vector<string> lines);

    /**
     * split line given in string
     * @param basic_string
     * @return vector of splitted line
     */
    vector<string> splitLine(string basic_string);

    /**
     * basic split
     * @param line
     * @param result
     * @param i
     * @param temp
     */
    void regularSplit(const string &line, vector<string> &result,
                      unsigned int i,
                      char temp) const;

    /**
     * split line - for print command
     * @param line
     * @param result
     * @param i
     * @param temp
     */
    void printSplit(const string &line, vector<string> &result, unsigned int i,
                    char temp) const;

    /**
     * split line for condition commands
     * @param line
     * @param result
     * @param i
     * @param temp
     */
    void
    conditionSplit(const string &line, vector<string> &result, unsigned int i,
                   char temp) const;

    /**
     * split line for assignment command
     * @param line
     * @param result
     * @param i
     * @param temp
     */
    void
    assignmentSplit(const string &line, vector<string> &result, unsigned int i,
                    char temp) const;

    /**
     * check if a string (represent a command) is regular command
     * @param command
     * @return true if it is, false otherwise
     */
    bool isRegularCommand(const string &command) const;

    /**
     * check if a string (represent a command) is condition command
     * @param command
     * @return true if it is, false otherwise
     */
    bool isConditionCommand(const string &command) const;

    /**
     * check if a string (represent a command) is print command
     * @param command
     * @return true if it is, false otherwise
     */
    bool isPrintCommand(const string &command) const;

    /**
     * delete redundant parentheses in given vector
     * @param vector
     */
    void delRedundantParentheses(vector<string> &vector) const;
};

#endif //FLIGHTSIMULATOR_RUNSIMULATOR_H