#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class ConquestFileReader
{
private:
	string fileName;
	bool isValidConquestMapFile;
	vector<string> fileContents;
	vector<Continent*> continentVec;
	vector<Territory*> territoryVec;
	vector<Territory*> territoryBordersVec;
public:
	ConquestFileReader();
	ConquestFileReader(string fileName);
	void setFileName(string name);
	
	// must be called in order
	// store continents first, store territories next, lastly store borders along with continents and territories
	void storeFileContents();
	void storeContinents();
	void storeTerritories();
	void storeTerritoriesWithBorders();
	void check_if_this_is_a_conquest_map();
	void setIsValidConquestMapFile(bool validity);
	void setFileContents(vector<string> strVec);
	
	string getFileName();
	vector<Continent*> getContinents();
	vector<Territory*> getTerritories();
	vector<Territory*> getTerritoriesWithBorders();
	vector<string> getFileContents();
	bool getIsValidConquestMapFile();
};


