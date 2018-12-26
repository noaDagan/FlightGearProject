
#include "CommandMap.h"

// Constructor
CommandMap::CommandMap() {}

// Distructor
CommandMap::~CommandMap() {
}

/**
 * The function add command to the list of commands.
 */
void CommandMap::addCommand(string key, Command *command) {
    this->commandMAp.insert(pair<string, Command *>(key, command));
}

/**
 * The getCommand function return check if the list contain a key and return his command
 */
Command *CommandMap::getCommand(string key) {
    // If the map not contain a key throw exception
    if (this->commandMAp.count(key)) {
        return this->commandMAp.find(key)->second;
    } else {
        throw "ERROR: invalid key";
    }
}

/**
 * The function check if the map contain a key or not
 */
bool CommandMap::isKeyInMap(string key) {
    return this->commandMAp.count(key);
}


map<string, Command *>  CommandMap::getCommandMap() {
    return this->commandMAp;
}