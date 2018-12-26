#ifndef PROJECTNUM1_CHECKENDSCRIPT_H
#define PROJECTNUM1_CHECKENDSCRIPT_H

class CheckEndScript {
    // Member endScript save a bool to close the thread
    bool endScript;
public:
    // Constructor
    CheckEndScript();

    // Distructor
    ~CheckEndScript();


    /**
     * The function get the end script
     */
    bool getBoolForExit() const;

    /**
     *
     * The function set the end script by the bool
     */
    void setBoolForExit(bool changeEndScript);

};


#endif //PROJECTNUM1_CHECKENDSCRIPT_H
