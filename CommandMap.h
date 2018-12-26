#include "Command.h"
#include "map"

#ifndef PROJECTNUM1_COMMANDMAP_H
#define PROJECTNUM1_COMMANDMAP_H


class CommandMap {
    //Members
    map<string, Command *> commandMAp;
public:
    //Constructor
    CommandMap();

    // Distructor
    ~CommandMap();

    /**
    * The function add command to the list of commands.
    */
    void addCommand(string key, Command *command);

    /**
    * The getCommand function return check if the list contain a key and return his command
    */
    Command *getCommand(string key);

    /**
    * The function check if the map contain a key or not
    */
    bool isKeyInMap(string key);

    /**
     * The function returns the map
     */
    map<string, Command *> getCommandMap();
};


#endif //PROJECTNUM1_COMMANDMAP_H
