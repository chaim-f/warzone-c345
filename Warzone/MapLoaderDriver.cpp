#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

int main() {

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

	for (size_t i = 0; i < canadaMap.getTerritoriesWithBorders().size(); i++) {
		map->addEdge(canadaMap.getTerritoriesWithBorders()[i]);
	}
	map->displayAdjacencyList();
	map->validate();
}

