#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
using namespace std;

// [x] 1.2.1 driver that demonstrate that different valid maps can be loaded and their validity verified
// [ ] 1.2.4 the user can select a map from a list of maps stored in a directory
// [ ] 1.2.5 the user can select the number of players
class GameEngine
{
	vector<Territory*> selectedMap;
	vector<MapLoader*> mapLoaders;
	int numPlayers;
public:
	void GameStart(); // calls all related game start functions 
	void readMapDir();
	void loadMaps();
	void storeMaps();
	void validatingMaps();
	void promptNumberOfPlayers();
	void setNumPlayers(int num);
	int getNumPlayers();
	list<string> mapFiles;
};

