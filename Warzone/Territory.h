#pragma once
#include <list>
#include <iostream>
#include "Continent.h"
using namespace std;

class Territory
{
	string territoryName;
	int territoryIndex;
	int territoryContinentIndex;
	list <int> territoryAdjacencies;
	Continent territoryContinent;
public:
	string adjacenciesString; // string format of territoryAdjacencies
	string getTerritoryName();
	list<int> getListAdjacencies();
	int getTerritoryIndex();
	int getTerritoryContinentIndex();
	void setListAdjacencies();
	void setStringAdjacencies(string s);

	Territory(int index, string name);
	Territory(int index, string name, Continent continent);
	Territory(int index, string name, Continent continent, list <int> adjacencies);

	friend std::ostream& operator<<(std::ostream&, const Territory);
};
