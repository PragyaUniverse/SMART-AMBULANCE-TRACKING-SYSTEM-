#ifndef AMBULANCE_H
#define AMBULANCE_H

#include <string>
#include <iostream>
using namespace std;

class Patient;   // forward declaration

class Ambulance {
    string ambulanceID;
    string location;
    bool available;

public:
    Ambulance(string id, string loc);

    void assignToPatient(Patient &p);
    void updateLocation(const string &newLoc);
    string getambulanceId();
    string getlocation();
    bool isAvailable();
};

#endif
