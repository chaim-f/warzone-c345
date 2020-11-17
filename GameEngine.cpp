#include "GameEngine.h"
#include "GameStart.h"
#include <iostream>
#include "DriverSelector.h";
#include "Map.h"
#include "MapLoader.h"
#include "Player.h"
#include <time.h>
using namespace std;
/*variables I am assuming are somehow passed to me*/
vector<Player> playerList;
Map* aMap;
/*Functions I need in the Map class
NumberOfTerritories(); return territoriesVec.size(); or equivlent
aTterritoriesVec(int value); return territoriesVec.at(value)

value and functions I need added in Player (it will be usefull for the reinforcement stage too)
int reinforcePool; //can be left alone as it will be intialzed before the first turn
int getreinforcePool(); return reinforcePool;
void setreinforcePool(int value); reinforcePool = value;
*/


void startupPhase(vector<Player> pList,Map* aMap) {
	int numOfPlayers=pList.size();
	int holder[5] = { -1,-1,-1,-1,-1 };
	vector<Player> tempVector;//put the order in here than copy to pList
	srand((unsigned)time(NULL));//seeds the rand function based on the time
	int temp;
	int counter = numOfPlayers;
	for (int i = 0; i < numOfPlayers; i++) {
		temp = (int)rand() % counter--;//takes the random values and takes the mod so it returns values between 0 and number ofplayers -1
		for (int j = 0; j < i; j++) {
			if (temp >= holder[j]) { temp = (temp + 1) % numOfPlayers; }
		}
		holder[i] = temp;
		tempVector.push_back(pList.at(temp));
	}
	pList = tempVector;
	int numberOfTerritories = aMap->NumberOfTerritories();
	counter = numberOfTerritories;
	int holderT[214748364];
	for (int i = 0; i < 214748364; i++) {
		holderT[i] = -1;
	}
	vector<Player> tempVector;//put the order in here than copy to pList
	for (int i = 0; i < numberOfTerritories; i++) {
		temp = (int)rand() % counter--;//takes the random values and takes the mod so it returns values between 0 and number ofplayers -1
		for (int j = 0; j < i; j++) {
			if (temp >= holder[j]) { temp = (temp + 1) % numberOfTerritories; }
		}
		holderT[i] = temp;
		pList.at(i % numOfPlayers).addMyTerritory(aMap->aTterritoriesVec(temp));
	}
	int reinforcePool;
	switch (numOfPlayers) {
	case 2: reinforcePool = 40; break;
	case 3:reinforcePool = 35; break;
	case 4:reinforcePool = 30; break;
	case 5:reinforcePool = 25; break;
	}
	for (auto& x : pList) {
		x.setsetreinforcePool(reinforcePool);
	}
}
