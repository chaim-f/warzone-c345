#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

int main() {

	string canadaMapFile = "maps/canada.map";
	MapLoader canadaMap = MapLoader();
	canadaMap.setFileName(canadaMapFile);
	canadaMap.storeContinents();
	canadaMap.storeTerritories();
	canadaMap.storeTerritoriesWithBorders();
	Map canadaCreatedMap = Map(canadaMap.getTerritories().size()+1);

	for (size_t i = 0; i < canadaMap.getTerritoriesWithBorders().size(); i++) {
		canadaCreatedMap.addEdge(canadaMap.getTerritoriesWithBorders()[i]);
	}

	canadaCreatedMap.displayAdjacencyList();
	canadaCreatedMap.validate();
}