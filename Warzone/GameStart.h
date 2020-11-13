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
// [x] 1.3.2 game is initiated in the main() function that is in  GameEngine.cpp file
class GameStart
{
	vector<Territory*> chosenMap;
	vector<MapLoader*> mapLoaders;
	int numPlayers;
public:
	void runAllFunctions(); // calls all related game start functions 
	void readMapDirectory();
	void loadMaps();
	void storeMaps();
	void validatingMaps();
	void promptUserToSelectNumberOfPlayers();
	void promptUserToSelectMap();
	void setChosenMap(vector<Territory*> chosenMap);
	void setNumPlayers(int num);
	int getNumPlayers(); // refer to this to create your players based on this value
	vector<Territory*> getChosenMap(); // will return the chosen map by the user
	list<string> mapFiles;
};

