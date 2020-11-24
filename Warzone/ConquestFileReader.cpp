#include "ConquestFileReader.h"
#include <fstream>
#include <string>
#include <sstream>      
#include <iostream>
#include <vector>


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
		};
	}
}
// will return Territory given a territory name
int getTerritoryIndex(vector<Territory*> territories, string name) {
	for (int i = 0; i < territories.size(); ++i) {
		if (name == territories.at(i)->getTerritoryName())
		{
			return territories.at(i)->getTerritoryIndex();
		};
	}
}

ConquestFileReader::ConquestFileReader()
{
	this->isValidConquestMapFile = false;
}

ConquestFileReader::ConquestFileReader(string fileName)
{
	this->isValidConquestMapFile = false;
	this->fileName = fileName;
	this->storeFileContents();
}

void ConquestFileReader::setFileName(string name)
{
	this->fileName = name;
}

void ConquestFileReader::storeFileContents()
{
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
	for (int i = 0; i < this->continentVec.size(); i++) {
		this->continentVec.at(i)->displayContinents();
	}
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
	for (int i = 0; i < this->territoryVec.size(); i++) {
		this->territoryVec.at(i)->displayTerritories();
	}
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

	for (int i = 0; i < this->territoryBordersVec.size(); i++) {
		this->territoryBordersVec.at(i)->displayTerritories();
	}
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
	return this->isValidConquestMapFile;
}

void ConquestFileReader::check_if_this_is_a_conquest_map() {
	fstream mapFile;
	if (this->fileName != "") {
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
				this->setIsValidConquestMapFile(true);
			else
				this->setIsValidConquestMapFile(false);
		}
	}
	else {

	}
}

void ConquestFileReader::setIsValidConquestMapFile(bool validity)
{
	this->isValidConquestMapFile = validity;
}

void ConquestFileReader::setFileContents(vector<string> strVec)
{
	this->fileContents = strVec;
}



