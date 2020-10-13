#pragma once
#include "Continent.h"
using namespace std;

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