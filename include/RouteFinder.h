#ifndef ROUTEFINDER_H
#define ROUTEFINDER_H

#include "CityMap.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class RouteFinder {
    const CityMap &cityMap;

public:
    RouteFinder(const CityMap &map);
    pair<int, vector<string>> dijkstra(const string &source, const string &destination);
};

#endif
