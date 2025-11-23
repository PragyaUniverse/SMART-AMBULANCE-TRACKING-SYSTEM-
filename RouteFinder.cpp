#include "../include/RouteFinder.h"
#include "../include/CityMap.h"
#include <limits>
#include <queue>
#include <algorithm>

RouteFinder::RouteFinder(const CityMap &map)
    : cityMap(map) {}

pair<int, vector<string>> RouteFinder::dijkstra(const string &source, const string &destination)
{
    const auto &adj = cityMap.getAdjList();

    unordered_map<string, int> dist;
    unordered_map<string, string> parent;

    for (const auto &entry : adj) {
        dist[entry.first] = numeric_limits<int>::max();
    }

    dist[source] = 0;

    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
    > pq;

    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDist, city] = pq.top();
        pq.pop();

        if (currentDist > dist[city])
            continue;

        for (const Edge &edge : adj.at(city)) {
            int newDist = currentDist + edge.distance;
            if (newDist < dist[edge.destination]) {
                dist[edge.destination] = newDist;
                parent[edge.destination] = city;
                pq.push({newDist, edge.destination});
            }
        }
    }

    if (dist[destination] == numeric_limits<int>::max()) {
        return { -1, {} };
    }

    // ERROR FIXED HERE
    vector<string> path;
    string temp = destination;

    while (temp != source) {
        path.push_back(temp);
        temp = parent[temp];
    }

    path.push_back(source);
    reverse(path.begin(), path.end());

    return { dist[destination], path };
}
