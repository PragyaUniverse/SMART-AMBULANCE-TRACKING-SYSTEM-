#include "../include/TripHistory.h"
#include<iostream>
using namespace std;

TripHistory::TripHistory() {
    head = nullptr;
}

void TripHistory::addTrip(string patientID, string ambulanceID, vector<string> route) {
    TripNode* newNode = new TripNode{patientID, ambulanceID, route, nullptr};

    if(head == nullptr) {
        head = newNode;
    } else {
        TripNode* temp = head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    cout << "Trip added: Ambulance " << ambulanceID << " -> Patient " << patientID << endl;
}

void TripHistory::displayHistory() {
    if(head == nullptr) {
        cout << "No trips yet." << endl;
        return;
    }

    TripNode* temp = head;
    int count = 1;
    while(temp != nullptr) {
        cout << "Trip " << count++ << ": Ambulance " << temp->ambulanceID
             << " -> Patient " << temp->patientID << " | Route: ";
        for(auto &loc : temp->route) cout << loc << " ";
        cout << endl;
        temp = temp->next;
    }
}
