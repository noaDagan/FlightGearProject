#ifndef FLIGHTSIMULATOR_UTILITY_H
#define FLIGHTSIMULATOR_UTILITY_H

#include <string>

using namespace std;

/**
 * static methods for the project.
 * utility methods for the project
 */
class Utility {
public:
    /**
     * check if this string is an operator
     * @param str
     * @return true if operator, false otherwise
     */
    static bool isOperator(string &str);

    /**
     * check if this char is an operator
     * @param ch
     * @return true if operator, false otherwise
     */
    static bool isOperator(char &ch);

    /**
     * check if this char is part of a condition operator
     * @param ch
     * @return true if it is part of operator, false otherwise
     */
    static bool isPartOfCondOp(char &ch);

    /**
     * check if this char is a separator
     * @param ch
     * @return true if separator, false otherwise
     */
    static bool isSeparator(char &ch);

    /**
     * check if this char is part of a number
     * @param ch
     * @return true if it is, false otherwise
     */
    static bool isPartOfNum(char &ch);

    /**
     * check if this char is part of word
     * @param ch
     * @return true if it
     */
    static bool isPartOfWord(char &ch);

    /**
     * check if this char is parentheses
     * @param ch
     * @return true if it is, false otherwise
     */
    static bool isParentheses(char &ch);

    /**
     * check if this string is an command
     * @param str
     * @return true if it is, false otherwise
     */
    static bool isCommand(string &str);

    /**
     * array of all XML's addresses
     */
    static const string fields[23];

};


#endif //FLIGHTSIMULATOR_UTILITY_H
