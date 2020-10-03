#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>      
#include <iostream>
#include <vector>

MapLoader::MapLoader()
{
}
void MapLoader::storeContinents() {
	fstream mapFile;
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
			vector<string> vec;
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
			vector<string>::iterator countriesIt = find(vec.begin(), vec.end(), "[countries]");
			if (countriesIt != vec.end()) {
				continentsEnd = distance(vec.begin(), countriesIt);
			}
			mapFile.close();
			// using the starting point for continent and countries
			// store continent objects
			vector<Continent> continentVec;
			int j = 0;
			for (size_t i = continentsStart + 1; i < continentsEnd - 1; ++i) {
				j++;
				string str = vec[i];
				continentVec.push_back(Continent(j, str.substr(0, str.find(" ")), stoi(str.substr(str.find(" ") + 1))));
			}
			for (int i = 0; i < continentVec.size(); i++) {
				cout << continentVec[i];
			}
			cout << "extracting continents from " << this->fileName << " map... DONE!" << endl;
		}
		else {
			cout << this->fileName << " not found!" << endl;
		}
	}
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


