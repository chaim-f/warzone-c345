#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
using namespace std;

class GameEngine
{
	vector<Territory*> chosenMap; // refer to this, it contains all the territories with continents and adjacencies from the chosen map
	vector<MapLoader*> mapLoaders;
	int numPlayers;
public:
	//void GameStart_setChosenMap(vector<Territory*> chosenMap);
	//void GameStart_setNumPlayers(int num);
	//int GameStart_getNumPlayers(); // refer to this to create your players based on this value
	list<string> mapFiles;
};

