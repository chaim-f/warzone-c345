#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
using namespace std;

// [x] 1.2.1 driver that demonstrate that different valid maps can be loaded and their validity verified
// [x] 1.2.4 the user can select a map from a list of maps stored in a directory
// [x] 1.2.5 the user can select the number of players
class GameEngine
{
	vector<Territory*> chosenMap; // refer to this, it contains all the territories with continents and adjacencies from the chosen map
	vector<MapLoader*> mapLoaders;
	int numPlayers;
public:
	void GameStart(); // calls all related game start functions 
	void readMapDirectory();
	void loadMaps();
	void storeMaps();
	void validatingMaps();
	void promptUserToSelectNumberOfPlayers();
	void promptUserToSelectMap();
	void setChosenMap(vector<Territory*> chosenMap);
	void setNumPlayers(int num);
	int getNumPlayers(); // refer to this to create your players based on this value
	list<string> mapFiles;
};

