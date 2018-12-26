#include "SleepCommand.h"

//Constructor
SleepCommand::SleepCommand() {

}

/**
 * The function make the program sleep for a given time
 */
int SleepCommand::doCommand(vector<string>::iterator &script) {
    //Convert the number to double and sleep
    sleep(atoi((*script).c_str()));
    script += 2;
    return 0;
}