#pragma once
#include <iostream>
#include <vector>
#include "Continent.h"
#include "Territory.h"
using namespace std;

class MapLoader
{
	string fileName;
	vector<Continent> continentVec;
	vector<Territory> territoryVec;
public:
	MapLoader();
	void setFileName(string name);
	void read();
	void storeContinents();
	void storeTerritories();
	vector<Continent> getContinents();
	vector<Territory> getTerritories();
	Continent getTerritoryContinentObject(int index);
};