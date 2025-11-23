#include "../include/Ambulance.h"
#include "../include/Patient.h"
#include<iostream>
using namespace std;

Ambulance::Ambulance(string id, string loc) {
    ambulanceID = id;
    location = loc;
    available = true;
}

void Ambulance::assignToPatient(Patient &p) {
    if (available) {
        cout << "Ambulance " << ambulanceID 
             << " assigned to Patient " << p.patientID << endl;
        available = false;
    } else {
        cout << "Ambulance " << ambulanceID 
             << " is currently busy." << endl;
    }
}

void Ambulance::updateLocation(const string &newLoc) {
    location = newLoc;
    available = true;
    cout << "Ambulance " << ambulanceID 
         << " location updated to " << location << endl;
}

string Ambulance::getambulanceId(){
    return ambulanceID;
}

string Ambulance::getlocation(){
    return location;
}
