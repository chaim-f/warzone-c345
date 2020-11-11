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

void MapLoader::setFileName(string name)
{
	this->fileName = name;
}

void MapLoader::storeContinents() {
	fstream mapFile;
	vector<string> vec;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		cout << endl << "*** Extracting continents from " << this->fileName << " map...START!" << endl;
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
			vector<Continent*>::iterator iter;
			for (iter = continentVec.begin(); iter != continentVec.end(); ++iter) {
				(*iter)->displayContinents();
			}
			cout << "*** Extracting Continents from " << this->fileName << " map... DONE!" << endl;
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
		cout << endl << "*** Extracting countries/territories from " << this->fileName << " map...START!" << endl;
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
			vector<Territory*>::iterator iter;
			for (iter = territoryVec.begin(); iter != territoryVec.end(); ++iter) {
				(*iter)->displayTerritories();
			}
			cout << "*** Extracting countries/territories from " << this->fileName << " map... DONE!" << endl;
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
		//Write to the end of the file
		ofstream out;
		// ios::app is the open mode "append" meaning
		// new data will be written to the end of the file.
		out.open(this->fileName, ios::app);
		string str = "[end]";
		out << str << "\n";
		out.close();

		cout << endl << "*** Extracting countries/territories with borders from " << this->fileName << " map...START!" << endl;
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
			vector<Territory*>::iterator iter;
			for (iter = territoryBordersVec.begin(); iter != territoryBordersVec.end(); ++iter) {
				(*iter)->displayTerritories();
			}
			cout << "*** Extracting countries/territories from " << this->fileName << " map... DONE!" << endl;
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
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