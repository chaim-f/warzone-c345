#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class MapLoader
{
	string fileName;
	vector<Continent> continentVec;
	vector<Territory> territoryVec;
	vector<Territory> territoryBordersVec;
public:
	MapLoader();
	void setFileName(string name);
	void read();
	void storeContinents();
	void storeTerritories();
	void storeTerritoriesWithBorders();
	vector<Continent> getContinents();
	vector<Territory> getTerritories();
	vector<Territory> getTerritoriesWithBorders();
	Continent getTerritoryContinentObject(int index);
};