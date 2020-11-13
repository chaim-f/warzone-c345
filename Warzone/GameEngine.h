#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
using namespace std;

// [x] 1.2.1 driver that demonstrate that different valid maps can be loaded and their validity verified
// [ ] 1.2.2 driver that demonstrate the right number of players has been added to the game and a deck of cards has been created
// [x] 1.2.4 the user can select a map from a list of maps stored in a directory
// [x] 1.2.5 the user can select the number of players
class GameEngine
{
	vector<Territory*> chosenMap; // refer to this, it contains all the territories with continents and adjacencies from the chosen map
	vector<MapLoader*> mapLoaders;
	int numPlayers;
public:
	void GameStart(); // calls all related game start functions 
	void GameStart_readMapDirectory();
	void GameStart_loadMaps();
	void GameStart_storeMaps();
	void GameStart_validatingMaps();
	void GameStart_promptUserToSelectNumberOfPlayers();
	void GameStart_promptUserToSelectMap();
	void GameStart_setChosenMap(vector<Territory*> chosenMap);
	void GameStart_setNumPlayers(int num);
	int GameStart_getNumPlayers(); // refer to this to create your players based on this value
	list<string> mapFiles;
};

