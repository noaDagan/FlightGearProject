#include "Utility.h"

bool Utility::isOperator(string &str) {
    return str == "*" || str == "/" || str == "-" || str == "+";
}


bool Utility::isOperator(char &ch) {
    return ch == '*' || ch == '/' || ch == '-' || ch == '+';
}

bool Utility::isSeparator(char &ch) {
    return ch == ' ' || ch == '\t' || ch == '\0';
}

bool Utility::isPartOfCondOp(char &ch) {
    return ch == '=' || ch == '!' || ch == '>' || ch == '<';
}

bool Utility::isPartOfNum(char &ch) {
    return isdigit(ch) || ch == '.';
}

bool Utility::isPartOfWord(char &ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_';
}

bool Utility::isParentheses(char &ch) {
    return ch == ')' || ch == '(';
}

bool Utility::isCommand(string &str) {
    return str == "print" || str == "sleep" || str == "if" || str == "while" ||
           str == "var" || str == "assign" || str == "openDataServer" ||
           str == "connect" || str == "enterC";
}

const string Utility::fields[23] = {
        "/instrumentation/airspeed-indicator/indicated-speed-kt",
        "/instrumentation/altimeter/indicated-altitude-ft",
        "/instrumentation/altimeter/pressure-alt-ft",
        "/instrumentation/attitude-indicator/indicated-pitch-deg",
        "/instrumentation/attitude-indicator/indicated-roll-deg",
        "/instrumentation/attitude-indicator/internal-pitch-deg",
        "/instrumentation/attitude-indicator/internal-roll-deg",
        "/instrumentation/encoder/indicated-altitude-ft",
        "/instrumentation/encoder/pressure-alt-ft",
        "/instrumentation/gps/indicated-altitude-ft",
        "/instrumentation/gps/indicated-ground-speed-kt",
        "/instrumentation/gps/indicated-vertical-speed",
        "/instrumentation/heading-indicator/indicated-heading-deg",
        "/instrumentation/magnetic-compass/indicated-heading-deg",
        "/instrumentation/slip-skid-ball/indicated-slip-skid",
        "/instrumentation/turn-indicator/indicated-turn-rate",
        "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
        "/controls/flight/aileron",
        "/controls/flight/elevator",
        "/controls/flight/rudder",
        "/controls/flight/flaps",
        "/controls/engines/engine/throttle",
        "/engines/engine/rpm"};
