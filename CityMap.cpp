#include "../include/CityMap.h"
#include<iostream>
using namespace std;

void CityMap::addCity(const string &city){
    if(adjList.find(city)==adjList.end()){
        adjList[city]=list<Edge>();
    }
}

void CityMap::addRoad(const string& from, const string &to, int distance){
    adjList[from].push_back({to, distance});
    adjList[to].push_back({from, distance});
}

void CityMap::displayMap(){
    for(auto &pair : adjList){
        cout << pair.first << " -> ";
        for(auto &edge : pair.second){
            cout << edge.destination << "(" << edge.distance << ") ";
        }
        cout << endl;
    }
}

const unordered_map<string,list<Edge>>& CityMap::getAdjList() const {
    return adjList;
}
