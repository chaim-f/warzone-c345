#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>      
#include <iostream>
#include <vector>
#include "Territory.h"

//Internal/private function implemented at the end of the file
vector<string> split(string str, char delimiter);

MapLoader::MapLoader()
{
}

void MapLoader::setFileName(string name)
{
	this->fileName = name;
}


void MapLoader::read()
{
	cout << "STARTING reading map..." << endl;
	fstream mapFile;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		mapFile.open(this->fileName, ios::in);
		if (mapFile.is_open()) {
			string tp;
			while (getline(mapFile, tp)) {
				cout << tp << "\n";
			}
			mapFile.close();
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
	cout << "FINISHED reading map..." << endl;
}

void MapLoader::storeContinents() {
	fstream mapFile;
	vector<string> vec;
	//vector<Continent> continentVec;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		cout << "extracting continents from " << this->fileName << " map...START!" << endl;
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
				continentsStart = distance(vec.begin(), continentsIt);
			}
			// find countries starting point
			vector<string>::iterator territoriesIt = find(vec.begin(), vec.end(), "[countries]");
			if (territoriesIt != vec.end()) {
				continentsEnd = distance(vec.begin(), territoriesIt);
			}
			mapFile.close();
			// using the starting point for continent and countries
			// store continent objects

			int j = 0;
			for (size_t i = continentsStart + 1; i < continentsEnd - 1; ++i) {
				j++;
				string str = vec[i];
				continentVec.push_back(Continent(j, str.substr(0, str.find(" ")), stoi(str.substr(str.find(" ") + 1))));
			}
			for (int i = 0; i < continentVec.size(); i++) {
				cout << continentVec[i] << endl;;
			}
			cout << "extracting continents from " << this->fileName << " map... DONE!" << endl;
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
}

void MapLoader::storeTerritories() {
	//storeContinents;
	fstream mapFile;
	vector<string> vec;
	if (this->fileName == "")
	{
		cout << "no map file set!" << endl;
	}
	else {
		cout << "extracting countries/territories from " << this->fileName << " map...START!" << endl;
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
				territoriesStart = distance(vec.begin(), territoriesIt);
			}
			// find borders starting point
			vector<string>::iterator bordersIt = find(vec.begin(), vec.end(), "[borders]");
			if (bordersIt != vec.end()) {
				territoriesEnd = distance(vec.begin(), bordersIt);
			}
			mapFile.close();
			// using the starting point for countries and borders
			// store territory objects

			int j = 0;
			for (size_t i = territoriesStart + 1; i < territoriesEnd - 1; ++i) {
				j++;
				vector<string> str = split(vec[i], ' ');
				territoryVec.push_back(Territory(stoi(str[0]), str[1], getTerritoryContinentObject(stoi(str[2]))));
			}
			for (int i = 0; i < territoryVec.size(); i++) {
				cout << territoryVec[i] << endl;
			}
			cout << "extracting countries/territories from " << this->fileName << " map... DONE!" << endl;
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
}

void MapLoader::storeTerritoriesWithBorders() {
	//storeTerritories;
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

		cout << "extracting countries/territories with borders from " << this->fileName << " map...START!" << endl;
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
				bordersStart = distance(vec.begin(), bordersIt);
			}


			// find end of file
			vector<string>::iterator endOfFileIt = find(vec.begin(), vec.end(), str);
			if (endOfFileIt != vec.end()) {
				bordersEnd = distance(vec.begin(), endOfFileIt);
			}
			mapFile.close();
			// using the starting point for countries and borders
			// store territory objects

			int j = 0;
			for (size_t i = bordersStart + 1; i < bordersEnd; ++i) {
				j++;
				vector<string> subStr = split(vec[i], ' ');
				for (int k = 1; k < subStr.size(); k++) {
					territoryBordersVec.push_back(Territory(stoi(subStr[0]), stoi(subStr[k]), territoryVec[j-1].getTerritoryName(), territoryVec[j-1].getTerritoryContinent()));
				}
			}
			for (int i = 0; i < territoryBordersVec.size(); i++) {
				cout << territoryBordersVec[i] << endl;
			}
			cout << "extracting countries/territories from " << this->fileName << " map... DONE!" << endl;
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
}

vector<Continent> MapLoader::getContinents() {
	return continentVec;
}

vector<Territory> MapLoader::getTerritories() {
	return territoryVec;
}

vector<Territory> MapLoader::getTerritoriesWithBorders() {
	return territoryBordersVec;
}


// Function to return the corresponding Continent object to the continent index
Continent MapLoader::getTerritoryContinentObject(int index) {
	for (size_t i = 0; i < continentVec.size(); ++i) {
		if (index == i+1)
		{
			return continentVec[i];
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