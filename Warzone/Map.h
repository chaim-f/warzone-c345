#pragma once
#include <list>
#include <iostream>
#include <vector>
using namespace std;
class Territory;

class Continent
{
	string continentName;
	int continentBunos = 0;
	int source;
	int destination;
public:
	Continent() {
		source = -1; // if not set
		destination = -1;
	};
	Continent(int src, int dest, string name, int bunos);
	Continent(int src, string name, int bunos);
	int getSource();
	friend class Map;
	friend int getSource(Continent c);
	friend int getDestination(Continent d);
	friend ostream& operator<<(ostream& strm, const Continent c);
};

class Continent;

class Map
{
	int numVertices;
	bool isDirectedGraph;
	vector<Territory> territoriesVec;
	vector<Continent> continentsVec;
	list<int>* adjList;
	void DFS(int v, bool visitedArr[]);
	Map* map = nullptr;
public:
	Map();
	Map(const Map& m); // copy constructor
	~Map() {
		delete[] adjList;
	}
	Map& operator = (const Map& t); // assignment operator
	void createMap(int vertices, bool isDirected);
	bool isTerritoryStartAtIndex0();
	void addEdge(Territory t);
	void addEdge(Continent c);
	void displayAdjacencyList();
	bool isConnectedGraph();
	bool isTerritoryBelongToAContinent();
	void validate();
	Map* getReverseGraph();
};


class Territory {
	int source;
	int destination;
	string territoryName;
	Continent continent;
public:
	Territory() {
		source = 0;
		destination = 0;
	}
	Territory(int src, int dest);
	Territory(int src, int dest, Continent c);
	Territory(int src, string name, Continent c);
	Territory(int src, int dest, string name, Continent c);
	Continent getTerritoryContinent();
	string getTerritoryName();
	friend class Map;
	friend ostream& operator<<(ostream& strm, const Territory t);
};