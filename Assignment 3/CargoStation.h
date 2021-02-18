#ifndef ASSIGNMENT3_CARGOSTATION_H
#define ASSIGNMENT3_CARGOSTATION_H

#include <string>
#include "Truck.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

class CargoStation {
public:
    CargoStation() = default;
    CargoStation(string name){cityName = name;}

    string cityName;
    Queue<Truck> garage;
    Stack<Package> storage;


    void addTruck(string tName, string tPower);
    void addTruck(const Truck& t);
    void removeTruck();
    void getTruck(Truck &truck) const;

    void addPackage(string pName);
    void addPackage(const Package& p);
    void removePackage();
    void getPackage(Package &package) const;

    string toString();
};


#endif //ASSIGNMENT3_CARGOSTATION_H
