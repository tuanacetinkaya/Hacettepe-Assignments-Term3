#include <sstream>
#include "RegionalManager.h"

void RegionalManager::shipmentReport() {
    //create and place the possible destinations
    prepareDestinations();
    //initialize the garage and storages in those destinations wrt given files
    preparePackages();
    prepareTrucks();

    //now with everything in place, let's start the missions
    doMissions();

    for (auto &station : stations) {
        resultFile << station.toString();
        resultFile << "-------------\n";
    }

}

void RegionalManager::prepareDestinations() {
    string line;
    while (getline(destFile, line)) {
        //creating the stations and pushing them into our list
        CargoStation cs(line);
        stations.push_back(cs);
    }
}

void RegionalManager::preparePackages() {
    string line;
    string pName, destName;
    while (getline(packageFile, line)) {
        //creating the packages and pushing them into our list
        stringstream linestream(line);
        // Read the integers using the operator >>
        linestream >> pName >> destName;
        for (auto &station : stations) {
            if (destName == station.cityName) {
                Package aPackage(pName);
                station.storage.push(aPackage);
                break; //since each package will be in only one storage, we break the cycle once we find the place
            }
        }

    }
}

void RegionalManager::prepareTrucks() {
    string line;
    string truck, home, power;
    while (getline(truckFile, line)) {
        //creating the packages and pushing them into our list
        stringstream lineStream(line);
        // Read the integers using the operator >>
        lineStream >> truck >> home >> power;
        for (auto &station : stations) {
            if (home == station.cityName) {
                Truck aTruck(truck, power);
                station.garage.enqueue(aTruck);
                break; //since each package will be in only one storage, we break the cycle once we find the place
            }
        }

    }
}

void RegionalManager::doMissions() {
    string line;
    string srt, mid, trg, midDrops; // for start, midway and target stations
    int srtAmt, midAmt; // Amt for package amounts to take from those stations. Drops is pretty self-explanatory
    //the loop to make each mission
    while (getline(missionFile, line)) {
        //creating the packages and pushing them into our list
        stringstream lineStream(line);
        string data;
        vector<string> splitted;

        // Read the integers by dash delimiter
        while (getline(lineStream, data, '-')) {
            splitted.push_back(data);
        }

        //now the string is split by dashes
        srt = splitted[0];
        mid = splitted[1];
        trg = splitted[2];
        srtAmt = stoi(splitted[3]);
        midAmt = stoi(splitted[4]);
        midDrops = splitted[5];

        //now arranging the list to have all the midway drops in an integer array
        vector<int> midDropList;
        string dropout;
        stringstream dropStream(midDrops);
        while (getline(dropStream, dropout, ',')) {
            midDropList.push_back(stoi(dropout));
        }
        //doing the actual missions
        starting(srt, srtAmt);
        midway(mid, midAmt, midDropList);
        target(trg);

    }
}

void RegionalManager::starting(string stationName, int loadAmount) {
    //add the truck, check if that station has any trucks, if not abort mission
    for (auto &station : stations) {
        if (stationName == station.cityName) {
            Truck truck;
            station.getTruck(truck);
            transportation.add(truck);
            station.removeTruck();

            //if we find a truck in our starting place we move on
            if (!transportation.isEmpty()) {
                for (int i = 0; i < loadAmount; i++) {
                    Package p;
                    station.getPackage(p);
                    transportation.add(p);
                    station.removePackage();
                }
            }
            break; // we break the cycle once we find the place
        }
    }
}

void RegionalManager::midway(string stationName, int loadAmount, vector<int> drops) {
    if (!transportation.isEmpty()) {
        for (auto &station : stations) {
            //find the midway station
            if (station.cityName == stationName) {
                //load the packages to transportation
                for (int i = 0; i < loadAmount; i++) {
                    Package p;
                    station.getPackage(p);
                    transportation.add(p);
                    station.removePackage();
                }

                for (auto &drop : drops) {
                    Package d;
                    transportation.find(drop, d);
                    //means there's no package
                    if (!d.name.empty() && transportation.size() > 1 && drop >= 0) {
                        station.addPackage(d);
                    }
                }

                //now remove those packages so they need to be in descending order in order to keep the indexes fixed
                sort(drops.begin(), drops.end(), greater<int>());
                for (auto &remove: drops) {
                    if (remove >= 0) {
                        transportation.remove(remove + 1); // remove method takes the actual index
                    }
                }
            }
        }
    }
}

void RegionalManager::target(string stationName) {
    for(auto & station: stations){
        if(station.cityName == stationName){
            //drop the truck to the garage
            string truckHere = transportation.getHead();
            Truck truck(truckHere, "0.0"); //it has travelled so much that it's now powerless lol
            station.addTruck(truck);
            transportation.remove(0);//remove the head

            while (!transportation.isEmpty()){
                string ps = transportation.getHead();
                station.addPackage(ps);
                transportation.remove(0);
            }
        }
    }
}
