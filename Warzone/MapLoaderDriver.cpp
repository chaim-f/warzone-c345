#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

int main() {

	// Valid case
	// load and store map objects
	string canadaMapFile = "maps/canada.map";
	MapLoader canadaMap = MapLoader();
	canadaMap.setFileName(canadaMapFile);
	canadaMap.storeContinents();
	canadaMap.storeTerritories();
	canadaMap.storeTerritoriesWithBorders();
	
	// create map and validate
	Map* map;
	map = new Map();
	map->createMap(canadaMap.getTerritories().size() + 1, true);

	for (int i = 0; i < canadaMap.getTerritoriesWithBorders().size(); i++) {
		map->addEdge(canadaMap.getTerritoriesWithBorders()[i]);
	}
	map->displayAdjacencyList();
	map->validate();


	// Invalid case
	string europeFile = "maps/europe.map";
	MapLoader europeMap = MapLoader();
	europeMap.setFileName(europeFile);
	europeMap.storeContinents();
	europeMap.storeTerritories();
	europeMap.storeTerritoriesWithBorders();

	Map* map2;
	map2 = new Map();
	map2->createMap(static_cast<int>(europeMap.getTerritories().size() + 1), true);

	for (int i = 0; i < europeMap.getTerritoriesWithBorders().size(); i++) {
		map2->addEdge(europeMap.getTerritoriesWithBorders()[i]);
	}
	map2->displayAdjacencyList();
	map2->validate();


}

