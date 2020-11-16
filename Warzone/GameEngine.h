#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
#include "Player.h"
using namespace std;

class GameEngine
{

public:

};

class GameStart
{
	// [x] 1.2.1 driver that demonstrate that different valid maps can be loaded and their validity verified
	// [-] 1.2.2 driver that demonstrate the right number of players has been added to the game and a deck of cards has been created
	// [x] 1.2.4 the user can select a map from a list of maps stored in a directory
	// [x] 1.2.5 the user can select the number of players
	// [x] 1.3.2 game is initiated in the main() function that is in  GameEngine.cpp file
	vector<Territory*> chosenMap;
	vector<MapLoader*> mapLoaders;
	vector<Player*> playersCreated;
	int numPlayers;
public:
	void runAllFunctions(); // calls all related game start functions 

	// all related to maps
	void readMapDirectory();
	void loadMaps();
	void storeMaps();
	void validatingMaps();
	void setChosenMap(vector<Territory*> chosenMap);
	vector<Territory*> getChosenMap(); // will return the chosen map by the user
	list<string> mapFiles;

	// user input
	void promptUserToSelectNumberOfPlayers();
	void promptUserToSelectMap();

	// all related to player
	void setPlayersCreated(vector<Player*> playersCreated);
	void setNumPlayers(int num);
	void createPlayers();
	int getNumPlayers(); // refer to this to create your players based on this value	
	vector<Player*> getPlayersCreated();
};

