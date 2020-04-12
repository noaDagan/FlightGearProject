#ifndef FLIGHTSIMULATOR_SIMULATORDATAPARSER_H
#define FLIGHTSIMULATOR_SIMULATORDATAPARSER_H

#include <string>
#include <cstring>
#include <unordered_map>
#include "DataBase.h"

using namespace std;

/**
 * parse data read from simulator and update data base accordingly
 */
class SimulatorDataParser {
    unordered_map<string, double> *simulatorData;
    DataBase *localData;

public:
    /**
     * constructor
     * @param simulatorData
     * @param dataBase
     */
    SimulatorDataParser(unordered_map<string, double> &simulatorData,
                        DataBase *&dataBase);

    /**
     * divide buffer by ",", enter the data to the simulator data map
     * @param buffer
     */
    void parse(char *buffer) const;

    /**
     * go over dataBase data, and update it according to simulatorData
     */
    void syncData() const;
};

#endif //FLIGHTSIMULATOR_SIMULATORDATAPARSER_H
