#include "../include/Patient.h"
#include<iostream>
using namespace std;

Patient::Patient(string id, string loc, string urg) {
    patientID = id;
    location  = loc;
    urgency   = urg;
}

void Patient::requestAmbulance() {
    cout << "Patient " << patientID 
         << " requested an ambulance at location " << location
         << " with urgency: " << urgency << endl;
}

string Patient::getpatientId(){
    return patientID;
}

string Patient::getlocation(){
    return location;
}
