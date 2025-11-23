#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
using namespace std;

class Patient {
public:
    string patientID;
    string location;
    string urgency;

    Patient(string id, string loc, string urg);

    void requestAmbulance();
    string getpatientId();
    string getlocation();
};

#endif
