#pragma once
#include <string>
#include <list>
#include <vector>
#include "MapLoader.h"
//#include "ConquestFileReaderAdapter.h"
#include "Player.h"
using namespace std;

class GameStart
{
	// [x] 1.2.1 driver that demonstrate that different valid maps can be loaded and their validity verified
	// [x] 1.2.2 driver that demonstrate the right number of players has been added to the game and a deck of cards has been created
	// [x] 1.2.4 the user can select a map from a list of maps stored in a directory
	// [x] 1.2.5 the user can select the number of players
	// [x] 1.3.2 game is initiated in the main() function that is in  GameEngine.cpp file
	vector<Territory*> chosenMap;
	vector<MapLoader*> mapLoaders;
	vector<ConquestFileReaderAdapter*> conquestMapLoaders;
	vector<Player*> playersCreated;
	vector<Territory*> territories;
	int numPlayers;
public:
	void runAllFunctions(); // calls all related game start functions 

	// all related to maps
	void readMapDirectory();
	void loadMaps();
	void storeMaps();
	void validatingMaps();
	void validateConquestMaps();
	void setChosenMap(vector<Territory*> chosenMap);
	void setTerritories(vector<Territory*> territories);
	vector<Territory*> getTerritories();
	vector<Territory*> getChosenMap(); // will return the chosen map by the user
	
	// map files
	list<string> mapFiles;
	list<string> conquestMapFiles;


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

class StartUpPhase
{
	vector<Territory*> territories;
	int numOfPlayers;
	vector<Player*> players;
public:
	StartUpPhase(vector<Territory*> territories, int numOfPlayers, vector<Player*> players);
	void startupPhase();
	
	// [x] 2.2.3 The order of play of the players are determine randomly
	void createOrderOfPlay(); // order of play

	// [x] 2.2.1 driver that clearly demonstrates that all territories in the map are assigned to one and only one player
	void distrubuiteTerritories();
	
	// [x] 2.2.2 Driver that clearly demonstrates that all players are given a number of armies which is put in their reinforment pool
	void setReinforcements();

	vector<Territory*> getTerritories();
	int getNumOfPlayers();
	vector<Player*> getPlayers();
};

class MainGameLoop
{
	vector<Territory*> territories;
	vector<Player*> players;
	Deck* myDeck = new Deck();
public:
	MainGameLoop(vector<Territory*> territories, vector<Player*> players);
	void mainGameLoop();
	void reinforcementPhase();
	void issueOrdersPhase();
	void executeOrdersPhase();
};