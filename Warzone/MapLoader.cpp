#include "MapLoader.h"
#include <fstream>
#include <string>

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