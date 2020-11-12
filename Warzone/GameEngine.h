#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
using namespace std;

// [ ] 1.2.1 validate map
// [ ] 1.2.4 the user can select a map from a list of maps stored in a directory
// [ ] 1.2.5 the user can select the number of players
class GameEngine
{
	vector<Territory*> territories;
	vector<MapLoader*> mapLoaders;
public:
	void readMapDir();
	void loadMaps();
	void storeMaps();
	//void validatingMaps();
	list<string> mapFiles;
};

