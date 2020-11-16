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
	Continent();
	Continent(int src, int dest, string name, int bunos);
	Continent(int src, string name, int bunos);
	void displayContinents();
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
	vector<Territory*> territoriesVec;
	vector<Continent*> continentsVec;
	list<int>* adjList;
	void DFS(int v, bool visitedArr[]);
	Map* map = nullptr;
	Territory* thisTerritory = nullptr;
	Continent* thisContinent = nullptr;
	bool isValidMapFile;
public:
	Map();
	~Map();
	Map(const Map& m); // copy constructor
	Map& operator = (const Map& t); // assignment operator
	void createMap(int vertices, bool isDirected);
	bool isTerritoryStartAtIndex0();
	void addEdge(Territory* t);
	void addEdge(Continent* c);
	void displayAdjacencyList();
	bool isConnectedGraph();
	bool isTerritoryBelongToAContinent();
	bool getIsValidMapFile();
	void validate();
	Map* getReverseGraph();
	void setIsValidMapFile(bool isValid);
};


class Territory {
	int source;
	int destination;
	string territoryName;
	Continent continent;
public:
	Territory();
	Territory(int src, int dest);
	Territory(int src, int dest, Continent c);
	Territory(int src, string name, Continent c);
	Territory(int src, int dest, string name, Continent c);
	void displayTerritories();
	Continent getTerritoryContinent();
	string getTerritoryName();
	friend class Map;
	friend ostream& operator<<(ostream& strm, const Territory t);
};