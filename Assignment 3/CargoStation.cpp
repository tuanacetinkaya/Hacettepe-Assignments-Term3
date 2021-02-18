
#include "CargoStation.h"

#include <utility>

void CargoStation::addTruck(string tName, string tPower) {
    Truck t(std::move(tName), std::move(tPower));
    garage.enqueue(t);
}

void CargoStation::addTruck(const Truck& t) {
    garage.enqueue(t);
}

void CargoStation::removeTruck() {
    garage.dequeue();
}

void CargoStation::getTruck(Truck &truck) const {
    garage.getFront(truck);
}

void CargoStation::addPackage(string pName) {
    Package p(std::move(pName));
    storage.push(p);
}

void CargoStation::addPackage(const Package& p) {
    storage.push(p);
}

void CargoStation::removePackage() {
    storage.pop();
}

void CargoStation::getPackage(Package &package) const {
    storage.getTop(package);
}

string CargoStation::toString() {
    string out = cityName + "\n";
    out += "Packages:\n";
    Package top;
    while (!storage.isEmpty()) {
        storage.getTop(top);
        out += top.name + "\n";
        storage.pop();
    }
    out += "Trucks:\n";
    Truck front;
    while (!garage.isEmpty()) {
        garage.getFront(front);
        out += front.name + "\n";
        garage.dequeue();
    }
    return out;
}



