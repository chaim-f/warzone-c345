#include "GameEngine.h"
#include "Map.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void GameEngine::GameStart()
{
	this->readMapDir();
	this->loadMaps();
	this->storeMaps();
	this->validatingMaps();
}

void GameEngine::readMapDir()
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
	cout << "loading maps..." << endl;
	list<string>::iterator it;
	for (it = mapFiles.begin(); it != mapFiles.end(); ++it) {
		string filename = (*it);
		mapLoaders.push_back(new MapLoader((*it)));
	}
	cout << "done..." << endl;
}

void GameEngine::storeMaps()
{
	cout << "storing map..." << endl;
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
	cout << "validating maps..." << endl;
	int invalidMapIndex = 0;
	for (int i = 0; i < mapLoaders.size(); i++) {
		Map* map;
		map = new Map();
		map->createMap(mapLoaders.at(i)->getTerritories().size() + 1, true);
		for (int j = 0; j < mapLoaders.at(i)->getTerritoriesWithBorders().size(); j++) {
			map->addEdge(mapLoaders.at(i)->getTerritoriesWithBorders()[j]);
		}
		cout << "> validating " << mapLoaders.at(i)->getFileName() << endl;
		map->validate();
		if (!map->getIsValidMapFile()) {
			invalidMapIndex = i; // store index of invalid map
		}
	}
	cout << "gracefully rejecting invalid map..." << endl;
	mapLoaders.erase(mapLoaders.begin() + invalidMapIndex);
	/*for (unsigned k = 0; k < mapLoaders.size(); ++k) { // open to see valid map
		cout << mapLoaders.at(k)->getFileName();
	}*/
	cout << "done..." << endl;
}

void GameEngine::promptNumberOfPlayers()
{
	int num;
	cout << "How many players? Min=2, Max=5" << endl;
	cin >> num;
	this->setNumPlayers(num);
}

void GameEngine::setNumPlayers(int num)
{
	this->numPlayers = num;
}

int GameEngine::getNumPlayers()
{
	return numPlayers;
}
