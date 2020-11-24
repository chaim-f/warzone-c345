#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class ConquestFileReader
{
private:
	string fileName;
	vector<Continent*> continentVec;
	vector<Territory*> territoryVec;
	vector<Territory*> territoryBordersVec;
public:
	ConquestFileReader();
	ConquestFileReader(string fileName);
	void setFileName(string name);
	
	// must be called in order
	// store continents first, store territories next, lastly store borders along with continents and territories
	void storeContinents();
	void storeTerritories();
	void storeTerritoriesWithBorders();
	
	string getFileName();
	vector<Continent*> getContinents();
	vector<Territory*> getTerritories();
	vector<Territory*> getTerritoriesWithBorders();
};


