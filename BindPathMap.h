#include <string>
#include<map>

#ifndef PROJECTNUM1_BINDMAP_H
#define PROJECTNUM1_BINDMAP_H

using namespace std;

class BindPathMap {
    // Member
    map<string, string> mapOfBind;
public:
    // Constructor
    BindPathMap();

    // Distructor
    ~BindPathMap();

    /**
     * The function add pair string to the map by key and value
     */
    void addBindToMap(string key, string value);

    /**
     * The getBindMap return the second of key
     */
    string getBindMap(string key) const;

    /**
 * The function check if the map contain a speciffic key snd return yes or no
 */
    bool isKeyInMap(string key) const;

};


#endif //PROJECTNUM1_BINDMAP_H
