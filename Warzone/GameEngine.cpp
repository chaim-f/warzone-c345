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
	vector<MapLoader*>::iterator iter;
	for (iter = mapLoaders.begin(); iter != mapLoaders.end(); ++iter) {
		Map* map;
		map = new Map();
		map->createMap((*iter)->getTerritories().size() + 1, true);

		for (int i = 0; i < (*iter)->getTerritoriesWithBorders().size(); i++) {
			map->addEdge((*iter)->getTerritoriesWithBorders()[i]);
		}
		// map->displayAdjacencyList();
		cout << "> validating " << (*iter)->getFileName() << endl;
		map->validate();
	}
	cout << "done..." << endl;
}
