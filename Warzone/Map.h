#pragma once

#include <list>
#include <iostream>
#include <vector>
#include "Territory.h"
using namespace std;

class Map
{
	int numVertices;
	vector<Territory> territoriesVec;
	vector<Continent> continentsVec;
	list<int>* adjList;
	void DFS(int v, bool visitedArr[]);
public:
	Map(int vertices)
	{
		this->numVertices = vertices;
		adjList = new list<int>[vertices];
	}
	~Map() {
		delete[] adjList;
	}
	void addEdge(Territory t, bool isDirected);
	void addEdge(Continent c);
	void displayAdjacencyList();
	bool isConnectedGraph();
	bool isTerritoryBelongToAContinent();
	void validate();
	Map* getTranspose();
};