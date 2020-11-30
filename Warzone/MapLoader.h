#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class MapLoader
{
	string fileName;
	vector<Continent*> continentVec;
	vector<Territory*> territoryVec;
	vector<Territory*> territoryBordersVec;
public:
	MapLoader();
	~MapLoader();
	// [x] 2.2.3 All classes implement a correct copy constructor, assignment operator, and stream insertion operator
	MapLoader(const MapLoader& m); // copy constructor
	MapLoader& operator = (const MapLoader& t); // assignment operator
	MapLoader(string fileName);
	void setFileName(string name);
	void storeContinents();
	void storeTerritories();
	void storeTerritoriesWithBorders();
	string getFileName();
	vector<Continent*> getContinents();
	vector<Territory*> getTerritories();
	vector<Territory*> getTerritoriesWithBorders();
	Continent getTerritoryContinentObject(int index);
};

/// <summary>
/// [x] 2.3.1 The adapter and adaptee classes are implemented in the pre-existing MapLoader.cpp/MapLoader.h file duo
/// </summary>
class ConquestFileReader // [x] 2.3.2 There is an adaptee class named ConquesFileReader that implements the reading of Conquest map files.
{
private:
	string fileName;
	vector<string> fileContents;
	vector<Continent*> continentVec;
	vector<Territory*> territoryVec;
	vector<Territory*> territoryBordersVec;
public:
	ConquestFileReader();
	ConquestFileReader(string fileName);
	void setFileName(string name);

	ConquestFileReader& operator=(const ConquestFileReader& c); // assignment operator
	ConquestFileReader(const ConquestFileReader& c);

	// must be called in order
	// store continents first, store territories next, lastly store borders along with continents and territories
	void storeFileContents();
	void storeContinents();
	void storeTerritories();
	void storeTerritoriesWithBorders();
	void storeAllContents();
	void setFileContents(vector<string> strVec);

	string getFileName();
	vector<Continent*> getContinents();
	vector<Territory*> getTerritories();
	vector<Territory*> getTerritoriesWithBorders();
	vector<string> getFileContents();
	bool getIsValidConquestMapFile();
};

class ConquestFileReaderAdapter :
	public MapLoader // [x] 2.3.4 The ConquestFileReaderAdapter is a subclass of the original Domination file reader class.
{
private:
	// [x] 2.3.3 There is an adapter class names ConquestFileReaderAdapter that contains a member of type ConquestFileReader
	ConquestFileReader* conquestFileReader;
public:
	ConquestFileReaderAdapter();
	ConquestFileReaderAdapter(ConquestFileReader* cfr);
	void storeContinents();
	void storeTerritories();
	void storeTerritoriesWithBorders();
	void storeAllContents();
	vector<Continent*> getContinents();
	vector<Territory*> getTerritories();
	vector<Territory*> getTerritoriesWithBorders();
	string getFileName();
};