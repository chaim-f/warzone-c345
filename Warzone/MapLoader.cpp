#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>      
#include <iostream>
#include <vector>


//Internal/private function implemented at the end of the file
vector<string> split(string str, char delimiter);

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}

MapLoader::MapLoader(const MapLoader& m)
{
	fileName = "maps/canada.map";
}

MapLoader& MapLoader::operator=(const MapLoader& t)
{
	fileName = "maps/canada.map";
	return *this;
}

MapLoader::MapLoader(string fileName)
{
	this->fileName = fileName;
}

void MapLoader::setFileName(string name)
{
	this->fileName = name;
}

void displayTerritoriesInner(vector<Territory*> vec) {
	vector<Territory*>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); ++iter) {
		(*iter)->displayTerritories();
	}
}

void MapLoader::storeContinents() {
	fstream mapFile;
	vector<string> vec;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		cout << "*** Extracting continents from " << this->fileName << endl;
		int continentsStart = 0;
		int continentsEnd = 0;
		mapFile.open(this->fileName, ios::in);
		if (mapFile.is_open()) {
			string token;
			while (getline(mapFile, token, '\n')) {
				if (token.find(";") == 0) { // ignore comments starting with ';'
					continue;
				}
				vec.push_back(token); // store each line delimited by next line
			}
			// find continents starting point
			vector<string>::iterator continentsIt = find(vec.begin(), vec.end(), "[continents]");
			if (continentsIt != vec.end()) {
				continentsStart = static_cast<int>(distance(vec.begin(), continentsIt));
			}
			// find countries starting point
			vector<string>::iterator territoriesIt = find(vec.begin(), vec.end(), "[countries]");
			if (territoriesIt != vec.end()) {
				continentsEnd = static_cast<int>(distance(vec.begin(), territoriesIt));
			}
			mapFile.close();
			// using the starting point for continent and countries
			// store continent objects
			int j = 0;
			for (int i = continentsStart + 1; i < continentsEnd - 1; ++i) {
				j++;
				string str = vec[i];
				continentVec.push_back(new Continent(j, str.substr(0, str.find(" ")), stoi(str.substr(str.find(" ") + 1))));
			}
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
}

void MapLoader::storeTerritories() {
	fstream mapFile;
	vector<string> vec;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		cout << "*** Extracting countries/territories from " << this->fileName << endl;
		int territoriesStart = 0;
		int territoriesEnd = 0;
		mapFile.open(this->fileName, ios::in);
		if (mapFile.is_open()) {
			string token;
			while (getline(mapFile, token, '\n')) {
				if (token.find(";") == 0) { // ignore comments starting with ';'
					continue;
				}
				vec.push_back(token); // store each line delimited by next line
			}
			// find countries/territories starting point
			vector<string>::iterator territoriesIt = find(vec.begin(), vec.end(), "[countries]");
			if (territoriesIt != vec.end()) {
				territoriesStart = static_cast<int>(distance(vec.begin(), territoriesIt));
			}
			// find borders starting point
			vector<string>::iterator bordersIt = find(vec.begin(), vec.end(), "[borders]");
			if (bordersIt != vec.end()) {
				territoriesEnd = static_cast<int>(distance(vec.begin(), bordersIt));
			}
			mapFile.close();
			// using the starting point for countries and borders
			// store territory objects
			int j = 0;
			for (int i = territoriesStart + 1; i < territoriesEnd - 1; ++i) {
				j++;
				vector<string> str = split(vec[i], ' ');
				territoryVec.push_back(new Territory(stoi(str[0]), str[1], getTerritoryContinentObject(stoi(str[2]))));
			}
			// call displayTerritoriesInner(territoryVec); for detailed info
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
}

void MapLoader::storeTerritoriesWithBorders() {
	fstream mapFile;
	vector<string> vec;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		ofstream out;
		out.open(this->fileName, ios::app);
		string str = "[end]";
		out << str << "\n";
		out.close();
		cout << "*** Extracting countries/territories with borders from " << this->fileName << endl;
		int bordersStart = 0;
		int bordersEnd = 0;
		mapFile.open(this->fileName, ios::in);
		if (mapFile.is_open()) {
			string token;
			while (getline(mapFile, token, '\n')) {
				if (token.find(";") == 0) { // ignore comments starting with ';'
					continue;
				}
				vec.push_back(token); // store each line delimited by next line
			}
			// find borders starting point
			vector<string>::iterator bordersIt = find(vec.begin(), vec.end(), "[borders]");
			if (bordersIt != vec.end()) {
				bordersStart = static_cast<int>(distance(vec.begin(), bordersIt));
			}
			// find end of file
			vector<string>::iterator endOfFileIt = find(vec.begin(), vec.end(), str);
			if (endOfFileIt != vec.end()) {
				bordersEnd = static_cast<int>(distance(vec.begin(), endOfFileIt));
			}
			mapFile.close();
			// using the starting point for countries and borders
			// store territory objects

			int j = 0;
			for (int i = bordersStart + 1; i < bordersEnd; ++i) {
				j++;
				vector<string> subStr = split(vec[i], ' ');
				for (int k = 1; k < subStr.size(); k++) {
					territoryBordersVec.push_back(new Territory(stoi(subStr[0]), stoi(subStr[k]), territoryVec[j - 1]->getTerritoryName(), territoryVec[j - 1]->getTerritoryContinent()));
				}
			}
			// call displayTerritoriesInner(territoryBordersVec); for detailed info
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
}

string MapLoader::getFileName()
{
	return fileName;
}

vector<Continent*> MapLoader::getContinents() {
	return continentVec;
}

vector<Territory*> MapLoader::getTerritories() {
	return territoryVec;
}

vector<Territory*> MapLoader::getTerritoriesWithBorders() {
	return territoryBordersVec;
}

// Function to return the corresponding Continent object to the continent index
Continent MapLoader::getTerritoryContinentObject(int index) {
	for (int i = 0; i < continentVec.size(); ++i) {
		if (index == i + 1)
		{
			return *continentVec.at(i);
		};
	}
}

// Split function to separate a line of strings into a vector of substrings to extract specific information from a .map file line
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream. 
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}


//////////////////////////////
// CONQUEST MAP READER
//////////////

const string CONQUEST_MAP_WORD = "[Map]";
const string CONQUEST_CONTINENTS_WORD = "[Continents]";
const string CONQUEST_TERRITORIES_WORD = "[Territories]";
const string END_OF_FILE = "[end]";

// will return Continent given a continent name
Continent getTerritoryContinentObject(vector<Continent*> continents, string name) {
	for (int i = 0; i < continents.size(); ++i) {
		if (name == continents.at(i)->getContinentName())
		{
			return *continents.at(i);
		}
	}
}
// will return Territory given a territory name
int getTerritoryIndex(vector<Territory*> territories, string name) {
	for (int i = 0; i < territories.size(); ++i) {
		if (name == territories.at(i)->getTerritoryName())
		{
			return territories.at(i)->getTerritoryIndex();
		}
	}
}

void DisplayContinents(vector<Continent*> continentVec)
{
	for (int i = 0; i < continentVec.size(); i++) {
		continentVec.at(i)->displayContinents();
	}
}

void DisplayTerritories(vector<Territory*> territoryVec) {
	for (int i = 0; i < territoryVec.size(); i++) {
		territoryVec.at(i)->displayTerritories();
	}
}

ConquestFileReader::ConquestFileReader()
{
}

ConquestFileReader::ConquestFileReader(string fileName)
{
	this->fileName = fileName;
	this->storeFileContents();
}

void ConquestFileReader::setFileName(string name)
{
	this->fileName = name;
}

ConquestFileReader& ConquestFileReader::operator=(const ConquestFileReader& c)
{
	this->fileName = c.fileName;
	this->fileContents = c.fileContents;
	this->continentVec = c.continentVec;
	this->territoryVec = c.territoryVec;
	this->territoryBordersVec = c.territoryBordersVec;
	return *this;
}

ConquestFileReader::ConquestFileReader(const ConquestFileReader& c)
{
	this->fileName = c.fileName;
	this->fileContents = c.fileContents;
	this->continentVec = c.continentVec;
	this->territoryVec = c.territoryVec;
	this->territoryBordersVec = c.territoryBordersVec;
}

void ConquestFileReader::storeFileContents()
{
	if (this->getIsValidConquestMapFile()) {
		fstream conquestMapFile;
		vector<string> vec;
		int continentsStart = 0, continentsEnd = 0;
		conquestMapFile.open(this->fileName, ios::in);
		if (conquestMapFile.is_open()) {
			string token;
			while (getline(conquestMapFile, token, '\n')) {
				if (token.empty()) {
					continue;
				}
				vec.push_back(token);
			}
			conquestMapFile.close();
		}
		this->setFileContents(vec);
	}
}

void ConquestFileReader::storeContinents()
{
	vector<string> vec = this->getFileContents();
	int continentsStart = 0, continentsEnd = 0;
	vector<string>::iterator continentsIt = find(vec.begin(), vec.end(), CONQUEST_CONTINENTS_WORD);
	if (continentsIt != vec.end()) {
		continentsStart = static_cast<int>(distance(vec.begin(), continentsIt));
	}
	vector<string>::iterator territoriesIt = find(vec.begin(), vec.end(), CONQUEST_TERRITORIES_WORD);
	if (territoriesIt != vec.end()) {
		continentsEnd = static_cast<int>(distance(vec.begin(), territoriesIt));
	}
	int j = 0;
	for (int i = continentsStart + 1; i < continentsEnd; ++i) {
		j++;
		string str = vec[i];
		string continentName = str.substr(0, str.find("="));
		int continentBonus = stoi(str.substr(str.find("=") + 1));
		Continent* c = new Continent(j, continentName, continentBonus);
		this->continentVec.push_back(c);
	}
	//DisplayContinents(this->continentVec);
}



void ConquestFileReader::storeTerritories()
{
	ofstream out;
	out.open(this->fileName, ios::app);
	out << END_OF_FILE << "\n";
	out.close();

	vector<string> vec = this->getFileContents();
	int territoriesStart = 0, territoriesEnd = 0;
	vector<string>::iterator territoriesIt = find(vec.begin(), vec.end(), CONQUEST_TERRITORIES_WORD);
	if (territoriesIt != vec.end()) {
		territoriesStart = static_cast<int>(distance(vec.begin(), territoriesIt));
	}
	vector<string>::iterator endOfFileIt = find(vec.begin(), vec.end(), END_OF_FILE);
	if (endOfFileIt != vec.end()) {
		territoriesEnd = static_cast<int>(distance(vec.begin(), endOfFileIt));
	}
	int j = 0;
	for (int i = territoriesStart + 1; i < territoriesEnd; ++i) {
		j++;
		string str = vec[i];
		vector<string> internal;
		stringstream ss(str);
		string token;
		while (getline(ss, token, ',')) {
			internal.push_back(token);
		}

		string territoryName = internal[0];
		string continentName = internal[3];
		Continent c = getTerritoryContinentObject(this->continentVec, continentName);
		Territory* t = new Territory(j, territoryName, c);
		territoryVec.push_back(t);
	}
	//DisplayTerritories(this->territoryVec);
}

void ConquestFileReader::storeTerritoriesWithBorders()
{
	vector<string> vec = this->getFileContents();
	int territoriesStart = 0, territoriesEnd = 0;
	vector<string>::iterator it = find(vec.begin(), vec.end(), CONQUEST_TERRITORIES_WORD);
	if (it != vec.end()) {
		territoriesStart = static_cast<int>(distance(vec.begin(), it));
	}
	vector<string>::iterator endOfFileIt = find(vec.begin(), vec.end(), END_OF_FILE);
	if (endOfFileIt != vec.end()) {
		territoriesEnd = static_cast<int>(distance(vec.begin(), endOfFileIt));
	}
	int source = 0;
	for (int i = territoriesStart + 1; i < territoriesEnd; ++i) {
		source++;
		string str = vec[i];
		vector<string> internal;
		stringstream ss(str);
		string token;
		while (getline(ss, token, ',')) {
			internal.push_back(token);
		}
		// storing adjacencies
		string territoryName = internal[0];
		string continentName = internal[3];
		Continent c = getTerritoryContinentObject(this->continentVec, continentName);
		for (int k = 4; k < internal.size(); k++) {
			int dest = getTerritoryIndex(this->territoryVec, internal[k]);
			Territory* t = new Territory(source, dest, territoryName, c);
			territoryBordersVec.push_back(t);
		}
	}
	//DisplayTerritories(this->territoryBordersVec);
}

void ConquestFileReader::storeAllContents()
{
	this->storeContinents();
	this->storeTerritories();
	this->storeTerritoriesWithBorders();
}

string ConquestFileReader::getFileName()
{
	return this->fileName;
}

vector<Continent*> ConquestFileReader::getContinents()
{
	return this->continentVec;
}

vector<Territory*> ConquestFileReader::getTerritories()
{
	return this->territoryVec;
}

vector<Territory*> ConquestFileReader::getTerritoriesWithBorders()
{
	return this->territoryBordersVec;
}

vector<string> ConquestFileReader::getFileContents()
{
	return this->fileContents;
}

bool ConquestFileReader::getIsValidConquestMapFile()
{
	fstream mapFile;
	bool condition = false;
	mapFile.open(this->fileName, ios::in);
	if (mapFile.is_open()) {
		int countMapWord = 0, countContinentsWord = 0, countTerritoriesWord = 0;
		string candidate;
		while (mapFile >> candidate) // for each candidate word read from the file 
		{
			if (CONQUEST_MAP_WORD == candidate) ++countMapWord;
			if (CONQUEST_CONTINENTS_WORD == candidate) ++countContinentsWord;
			if (CONQUEST_TERRITORIES_WORD == candidate) ++countTerritoriesWord;
		}
		// if [Continents] [Map] [Territories] appear exactly one time, then this is a conquest map
		if (countMapWord == 1 && countContinentsWord == 1 && countTerritoriesWord == 1)
			condition = true;
	}
	return condition;
}

void ConquestFileReader::setFileContents(vector<string> strVec)
{
	this->fileContents = strVec;
}

ConquestFileReaderAdapter::ConquestFileReaderAdapter()
{
}

ConquestFileReaderAdapter::ConquestFileReaderAdapter(ConquestFileReader* cfr)
{
	conquestFileReader = cfr;
}

void ConquestFileReaderAdapter::storeContinents()
{
	this->conquestFileReader->storeContinents();
}

void ConquestFileReaderAdapter::storeTerritories()
{
	this->conquestFileReader->storeTerritories();
}

void ConquestFileReaderAdapter::storeTerritoriesWithBorders()
{
	this->conquestFileReader->storeTerritoriesWithBorders();
}

void ConquestFileReaderAdapter::storeAllContents()
{
	this->conquestFileReader->storeAllContents();
}

vector<Continent*> ConquestFileReaderAdapter::getContinents()
{
	return this->conquestFileReader->getContinents();
}

vector<Territory*> ConquestFileReaderAdapter::getTerritories()
{
	return this->conquestFileReader->getTerritories();
}

vector<Territory*> ConquestFileReaderAdapter::getTerritoriesWithBorders()
{
	return this->conquestFileReader->getTerritoriesWithBorders();
}

string ConquestFileReaderAdapter::getFileName()
{
	return this->conquestFileReader->getFileName();
}