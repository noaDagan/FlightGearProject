#include <map>
#include <string>
#include <iostream>
#include <string.h>

#ifndef PROJECTNUM1_FLIGHTVALUEMAP_H
#define PROJECTNUM1_FLIGHTVALUEMAP_H


using namespace std;

class FlightValueMap {

    map<string, double> mapOfFlightValue;


public:
    //Constructor
    FlightValueMap();

    /**
     * The function initialize the map with all the valu on the xml
     */
    void initalize();

    /**
     * The function receive a string of values and update the map
     */
    void updateMap(string values);

    /**
     * The function returns the value of a given key
     */
    double getValue(string key);

    /**
     * The function returns true if the key in the map else false
     */
    bool isKeyInMap(string key) const;

    ~FlightValueMap() {}

};


#endif //PROJECTNUM1_FLIGHTVALUEMAP_H