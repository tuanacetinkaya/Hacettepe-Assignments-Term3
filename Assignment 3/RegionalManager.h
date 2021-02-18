#ifndef ASSIGNMENT3_REGIONALMANAGER_H
#define ASSIGNMENT3_REGIONALMANAGER_H

#include "CargoStation.h"
#include "DoublyLinkedList.h"

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class RegionalManager {
public:
    RegionalManager() = default;
    RegionalManager(string dest, string package, string truck, string mission, string result){
        destFile.open(dest);
        packageFile.open(package);
        truckFile.open(truck);
        missionFile.open(mission);
        resultFile.open(result);
    }
    ~RegionalManager(){
        destFile.close();
        packageFile.close();
        truckFile.close();
        missionFile.close();
        resultFile.close();
    }

    //deals everything ana reports back to the resultFile to not get fired
    void shipmentReport();


private:
    vector<CargoStation> stations;
    DoublyLinkedList transportation;

    ifstream destFile;
    ifstream packageFile;
    ifstream truckFile;
    ifstream missionFile;

    ofstream resultFile;

    //-----  this section belongs to helper methods for initialising everything  ------//
    //reads destinations, packages, trucks and sets everything in place
    void prepareDestinations();
    void preparePackages();
    void prepareTrucks();
    //--------------------------------- up until here ---------------------------------//

    //-------------  this section belongs to helper methods for performing missions  -------------//
    void doMissions();

    //all tasks regarding starting station
    void starting(string stationName, int loadAmount);

    //all tasks regarding midway station
    void midway(string stationName, int loadAmount, vector<int> drops);

    //all tasks regarding target station
    void target(string stationName);
    //------------------------------------- up until here -----------------------------------------//



};


#endif //ASSIGNMENT3_REGIONALMANAGER_H
