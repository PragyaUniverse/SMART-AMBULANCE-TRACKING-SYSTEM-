#include "../include/Ambulance.h"
#include "../include/CityMap.h"
#include "../include/Patient.h"
#include "../include/RouteFinder.h"
#include "../include/TripHistory.h"
#include <iostream>
using namespace std;

int main() {
    CityMap city;
    city.addCity("A");
    city.addCity("B");
    city.addCity("C");
    city.addCity("D");

    city.addRoad("A", "B", 5);
    city.addRoad("B", "C", 10);
    city.addRoad("A", "C", 15);
    city.addRoad("C", "D", 20);

    cout << "City Map:" << endl;
    city.displayMap();
    cout << "-------------------------" << endl;

    Ambulance amb1("AMB1", "A");
    Ambulance amb2("AMB2", "B");

    Patient pat1("P1", "C", "High");
    Patient pat2("P2", "D", "Medium");

    pat1.requestAmbulance();
    pat2.requestAmbulance();
    cout << "-------------------------" << endl;

    RouteFinder rf(city);

    auto result1 = rf.dijkstra(amb1.getlocation(), pat1.getlocation());
    auto result2 = rf.dijkstra(amb2.getlocation(), pat2.getlocation());

    int dist1 = result1.first;
    int dist2 = result2.first;

    auto path1 = result1.second;
    auto path2 = result2.second;

    cout << "Route for AMB1 to P1: ";
    for(auto &loc : path1) cout << loc << " ";
    cout << "| Distance: " << dist1 << endl;

    cout << "Route for AMB2 to P2: ";
    for(auto &loc : path2) cout << loc << " ";
    cout << "| Distance: " << dist2 << endl;
    cout << "-------------------------" << endl;

    amb1.assignToPatient(pat1);
    amb2.assignToPatient(pat2);

    amb1.updateLocation(pat1.location);
    amb2.updateLocation(pat2.location);
    cout << "-------------------------" << endl;

    TripHistory history;
    history.addTrip(pat1.patientID, amb1.getambulanceId(), path1);
    history.addTrip(pat2.patientID, amb2.getambulanceId(), path2);

    history.displayHistory();

    return 0;
}
