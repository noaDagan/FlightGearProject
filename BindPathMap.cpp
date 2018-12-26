
#include "BindPathMap.h"

// Constructor empty
BindPathMap::BindPathMap() {
}

BindPathMap::~BindPathMap() {
}

/**
 * The function check if the map contain a speciffic key snd return yes or no
 */
bool BindPathMap::isKeyInMap(string key) const {
    if (this->mapOfBind.count(key)) {
        return true;
    }
    return false;
}

/**
* The getBindMap return the second of key
*/
string BindPathMap::getBindMap(string key) const {
    // Check if the key on the map otherwise throw exception
    if (this->mapOfBind.count(key)) {
        return this->mapOfBind.find(key)->second;
    } else {
        throw " Error - this key not map";
    }
}

/**
* The function add pair string to the map by key and value
*/
void BindPathMap::addBindToMap(string key, string value) {
    this->mapOfBind.insert(pair<string, string>(key, value));
}