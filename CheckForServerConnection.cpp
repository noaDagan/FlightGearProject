
#include "CheckForServerConnection.h"

// Constructor
CheckForServerConnection::CheckForServerConnection() {
    this->isConnect = false;
}

// Distructor
CheckForServerConnection::~CheckForServerConnection() {
}

/**
 * The function return isConnect value
 */
bool CheckForServerConnection::getBoolForConnect() const {
    return this->isConnect;
}

/**
 * The function setBoolForConnect by a bool parameter
 */
void CheckForServerConnection::setBoolForConnect(bool changeIsConnect) {
    this->isConnect = changeIsConnect;
}