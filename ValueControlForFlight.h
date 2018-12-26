#include <string>
#include <list>

#ifndef PROJECTNUM1_VALUCOMMANDFORFLIGHT_H
#define PROJECTNUM1_VALUCOMMANDFORFLIGHT_H
using namespace std;

class ValueControlForFlight {
    //Members
    string controlString;
public:
    //Constructor
    ValueControlForFlight();

    /**
     * The function return the control string
     */
    string getControlString();

    /**
     * The function set the control string
     */
    void setControlString(string s);

    /**
     * The function return true if the string is empty else false
     */
    bool checkIfStringEmpty();

    ~ValueControlForFlight() {
    }
};


#endif //PROJECTNUM1_VALUCOMMANDFORFLIGHT_H