#include "Command.h"
#include <unistd.h>

#ifndef PROJECTNUM1_SLEEPCOMMAND_H
#define PROJECTNUM1_SLEEPCOMMAND_H


class SleepCommand : public Command {
public:
    //Constructor
    SleepCommand();

    /**
     * The function make the program sleep for a given time
     */
    virtual int doCommand(vector<string>::iterator &script);

    ~SleepCommand() {
    }

};


#endif //PROJECTNUM1_SLEEPCOMMAND_H