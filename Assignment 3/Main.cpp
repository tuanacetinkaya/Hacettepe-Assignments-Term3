#include <iostream>
#include "RegionalManager.h"

// remember toString method of the CargoStation empties the stacks and queues to be able to access all elements
// you have one shut, you better get a kill gal :)
using namespace std;

int main(int arc, char** argv) {

//    RegionalManager michaelScott("set3/dests.txt", "set3/packages.txt", "set3/trucks.txt", "set3/missions.txt", "result.txt");
    RegionalManager michaelScott(argv[1], argv[2], argv[3], argv[4], argv[5]);
    michaelScott.shipmentReport();
    return 0;
}

//to run the system:
//g++ -std=c++11 *.cpp -o Main
//.\Main dests.txt packages.txt trucks.txt missions.txt result.txt