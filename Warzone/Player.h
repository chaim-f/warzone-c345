#pragma once
#include <string>
#include <vector> 
#include "map.h"
#include <iostream>
#include <list>

using std::string;


enum Cards {spy, bomb, reinforcement, blockade, airlift, diplomacy};



class Player
{
public:
	Player();
	~Player();
	int getPID();
	void setPID(int id);
	string getPName();
	void setPName(string name);
	std::vector <Territory*> playerTerritoryVector;
	std::vector <Cards*> playerCardsVector;
	void addPTerritory(Territory* tid);
	void removePTerritory(Territory* tid);
	void toDefend();
	void toAttack();
	void issueOrder();
private:
	int* PID;
	string* pName;
};

