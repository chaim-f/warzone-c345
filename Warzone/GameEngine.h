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
	// [x] 1.2.2 driver that demonstrate the right number of players has been added to the game and a deck of cards has been created
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
	vector<Player*>& getPlayersCreated();
};

class StartUpPhase
{
	GameStart gameStart;
public:
	StartUpPhase(GameStart g);
	void startupPhase();
	
	// 2.2.3 The order of play of the players are determine randomly
	void createOrderOfPlay(); // order of play

	// 2.2.1 driver that clearly demonstrates that all territories in the map are assigned to one and only one player
	void distrubuiteTerritories();
	
	// 2.2.2 Driver that clearly demonstrates that all players are given a number of armies which is put in their reinforment pool
	void setReinforcements();
};