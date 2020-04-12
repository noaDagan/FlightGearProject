#include <iostream>
#include "SimulatorDataParser.h"
#include "Utility.h"

SimulatorDataParser::SimulatorDataParser(
        unordered_map<string, double> &simulatorData, DataBase *&dataBase) {
    this->simulatorData = &simulatorData;
    this->localData = dataBase;
}

void SimulatorDataParser::parse(char *buffer) const {
    char *token = strtok(buffer, ",");
    for (const auto &field : Utility::fields) {
        simulatorData->at(field) = stod(token);
        token = strtok(nullptr, ",");
    }
}

void SimulatorDataParser::syncData() const {
    // check for each value in simulatorData is it in BindTable, and update it's value
    auto it = this->localData->getIteratorBind();
    for (; it != this->localData->getEndIteratorBind(); ++it) {
        string path = it->second;
        if (this->simulatorData->count(path) != 0) {
            // var exist, update
            double val = this->simulatorData->at(path); // save value
            string varName = it->first;
            this->localData->updateSymbol(varName, val);
        }
    }
}
