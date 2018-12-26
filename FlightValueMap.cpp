#include "FlightValueMap.h"

//Constructor
FlightValueMap::FlightValueMap() {
    this->initalize();
}

/**
* The function initialize the map with all the valu on the xml
*/
void FlightValueMap::initalize() {
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/instrumentation/altimeter/pressure-alt-ft",
                                 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/encoder/indicated-altitude-ft", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/instrumentation/encoder/pressure-alt-ft",
                                 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("instrumentation/gps/indicated-altitude-ft",
                                 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/gps/indicated-vertical-speed", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
            0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/aileron", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/elevator", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/rudder", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/flaps", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/engines/engine/throttle", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/engines/engine/rpm", 0));

}

/**
 * The function receive a string of values and update the map
 */
void FlightValueMap::updateMap(string values) {
    //Split the string to values
    char *charLine = const_cast<char *>(values.c_str());
    char *splitValues = strtok(charLine, ",");
    map<string, double>::iterator mapIter;
    //Update the map
    for (mapIter = this->mapOfFlightValue.begin();
         mapIter != this->mapOfFlightValue.end(); mapIter++) {
        (*mapIter).second = atof(splitValues);
        cout<<(*mapIter).first;
        cout<<" : ";
        cout<<(*mapIter).second<<endl;
        splitValues = strtok(NULL, ",");
    }
}

/**
 * The function returns the value of a given key
 */
double FlightValueMap::getValue(string key) {
    if (this->mapOfFlightValue.count(key)) {
        return this->mapOfFlightValue.find(key)->second;
    } else {
        throw "ERROR - no matchin value in map";
    }
}

/**
 * The function returns true if the key in the map else false
 */
bool FlightValueMap::isKeyInMap(string key) const {
    if (this->mapOfFlightValue.count(key)) {
        return true;
    }
    return false;
}