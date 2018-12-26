#include <string>
#include <vector>

#ifndef PROJECTNUM1_COMMAND_H
#define PROJECTNUM1_COMMAND_H

using namespace std;


class Command {
public:
    /**
     * The function execute the command
     * The function accept vector<string>::iterator
     */
    virtual int doCommand(vector<string>::iterator &script) = 0;

};


#endif //PROJECTNUM1_COMMAND_H
