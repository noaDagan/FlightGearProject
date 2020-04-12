#include <iostream>
#include "Controller.h"

using namespace std;

/**
 * get script for controlling the flight simulator and runs it.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    if (argc != 2) {
        // no file name entered
        __throw_invalid_argument("no file name found!");
    }
    string filename = argv[1];

    Controller controller;
    controller.run(filename);

    return 0;
}