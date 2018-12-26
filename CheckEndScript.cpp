#include "CheckEndScript.h"

// Constructor
CheckEndScript::CheckEndScript() {
    // initialize endScript to false
    this->endScript = false;
}

//Distructor
CheckEndScript::~CheckEndScript() {
}

/**
 * The function set the end script
 */
void CheckEndScript::setBoolForExit(bool changeEndScript) {
    this->endScript = changeEndScript;
}

/**
 * The function get the end script
 */
bool CheckEndScript::getBoolForExit() const {
    return this->endScript;
}

