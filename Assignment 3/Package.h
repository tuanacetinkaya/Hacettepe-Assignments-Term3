
#ifndef ASSIGNMENT3_PACKAGE_H
#define ASSIGNMENT3_PACKAGE_H

#include <string>

using namespace std;

class Package {
public:
    Package() = default;
    Package(string name){this->name = name;}

    string name;

    string toString() {return name; }
};


#endif //ASSIGNMENT3_PACKAGE_H
