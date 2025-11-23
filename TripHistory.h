#ifndef TRIPHISTORY_H
#define TRIPHISTORY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TripNode {
    string patientID;
    string ambulanceID;
    vector<string> route;
    TripNode* next;
};

class TripHistory {
    TripNode* head;

public:
    TripHistory();
    void addTrip(string patientID, string ambulanceID, vector<string> route);
    void displayHistory();
};

#endif
