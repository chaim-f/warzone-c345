#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
using namespace std;
int main() {

	string canadaMapFile = "maps/canada.map";
	MapLoader canadaMap = MapLoader();
	canadaMap.setFileName(canadaMapFile);
	canadaMap.read();
	// canadaMap.createTerritories();
	// canadaMap.createContinents();
	// canadaMap.getTerritories();
	// canadaMap.getContinents();


}