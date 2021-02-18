
#ifndef ASSIGNMENT3_TRUCK_H
#define ASSIGNMENT3_TRUCK_H

#include <string>
#include <utility>
#include "Package.h"

using namespace std;

class Truck : public Package {
public:
    Truck() = default;

    Truck(string name, string power) {
        this->name = std::move(name);
        this->power = std::move(power);
    }

    string power;
};


#endif //ASSIGNMENT3_TRUCK_H
