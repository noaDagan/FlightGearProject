#include "ValueControlForFlight.h"

//Constructor
ValueControlForFlight::ValueControlForFlight() {
    this->controlString = "";
}

/**
* The function return the control string
*/
string ValueControlForFlight::getControlString() {
    return this->controlString;
}

/**
* The function set the control string
*/
void ValueControlForFlight::setControlString(string s) {
    this->controlString = s;
}

/**
 * he function return true if the string is empty else false
 * */
bool ValueControlForFlight::checkIfStringEmpty() {
    return this->controlString == "";
}