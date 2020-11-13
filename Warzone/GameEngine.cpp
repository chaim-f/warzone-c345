#include "GameEngine.h"
#include "Map.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void GameEngine::GameStart()
{
	cout << "********** GAME START **********" << endl;
	this->readMapDirectory();
	this->loadMaps();
	this->storeMaps();
	this->validatingMaps();
	this->promptUserToSelectMap();
}

void GameEngine::readMapDirectory()
{
	cout << "Reading map directory..." << endl;
	int i = 0;
	for (const auto& p : fs::directory_iterator("maps")) {
		const auto path = p.path();
		if (p.is_regular_file() && path.filename().extension() == ".map") {
			i++;
			cout << "> map " << i << ": maps/" + path.filename().string() << endl; // e.g. "maps/canada.map"
			mapFiles.push_back("maps/" + path.filename().string());
		}
	}
	cout << "done..." << endl;
}

void GameEngine::loadMaps()
{
	cout << "Loading maps..." << endl;
	list<string>::iterator it;
	for (it = mapFiles.begin(); it != mapFiles.end(); ++it) {
		string filename = (*it);
		mapLoaders.push_back(new MapLoader((*it)));
	}
	cout << "done..." << endl;
}

void GameEngine::storeMaps()
{
	cout << "Storing map..." << endl;
	vector<MapLoader*>::iterator iter;
	for (iter = mapLoaders.begin(); iter != mapLoaders.end(); ++iter) {
		(*iter)->storeContinents();
		(*iter)->storeTerritories();
		(*iter)->storeTerritoriesWithBorders();
	}
	cout << "done..." << endl;
}

void GameEngine::validatingMaps()
{
	cout << "Validating maps..." << endl;
	int invalidMapIndex = NULL;
	for (int i = 0; i < mapLoaders.size(); i++) {
		Map* map;
		map = new Map();
		map->createMap(mapLoaders.at(i)->getTerritories().size() + 1, true);
		for (int j = 0; j < mapLoaders.at(i)->getTerritoriesWithBorders().size(); j++) {
			map->addEdge(mapLoaders.at(i)->getTerritoriesWithBorders()[j]);
		}
		cout << "> validating " << mapLoaders.at(i)->getFileName() << endl;
		map->validate();
		if (map->getIsValidMapFile() == 0) {
			invalidMapIndex = i; // store index of invalid map
		}
	}
	cout << "done..." << endl;
	if (invalidMapIndex != NULL) {
		cout << "Gracefully rejecting " << mapLoaders.at(invalidMapIndex)->getFileName() << endl;
		mapLoaders.erase(mapLoaders.begin() + invalidMapIndex);
		cout << "done..." << endl;
	}
	/*for (unsigned k = 0; k < mapLoaders.size(); ++k) { // open to see valid map
		cout << mapLoaders.at(k)->getFileName();
	}*/
}

void GameEngine::promptUserToSelectNumberOfPlayers()
{
	int num;
	cout << endl << "How many players? Min=2, Max=5" << endl;
	cin >> num;
	this->setNumPlayers(num);
}

void GameEngine::promptUserToSelectMap()
{
	cout << endl << "Please choose a map..." << endl;
	int chosenMapIndex;
	for (unsigned k = 0; k < mapLoaders.size(); ++k) {
		cout << "Enter number " << k << " to choose " << mapLoaders.at(k)->getFileName() << endl;
	}
	cin >> chosenMapIndex;
	cout << mapLoaders.at(chosenMapIndex)->getFileName() << " was chosen!";
	this->setChosenMap(mapLoaders.at(chosenMapIndex)->getTerritoriesWithBorders());
}

void GameEngine::setChosenMap(vector<Territory*> chosenMap)
{
	this->chosenMap = chosenMap;
}

void GameEngine::setNumPlayers(int num)
{
	this->numPlayers = num;
}

int GameEngine::getNumPlayers()
{
	return numPlayers;
}
