
#ifndef PROJECTNUM1_CHECKFORSERVERCONNECTION_H
#define PROJECTNUM1_CHECKFORSERVERCONNECTION_H


class CheckForServerConnection {
    // Member save if connect or not
    bool isConnect;
public:
    // Constructor
    CheckForServerConnection();

    // Distructor
    ~CheckForServerConnection();

    /**
    * The function return isConnect value
    */
    bool getBoolForConnect() const;

    /**
    * The function make set to isConnect value
    */
    void setBoolForConnect(bool changeIsConnect);
};

#endif //PROJECTNUM1_CHECKFORSERVERCONNECTION_H
