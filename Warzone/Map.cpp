#include "map.h"
#include <iostream>
#include <list>
#include "Player.h"
//to do fix all destructors so it destroys all pointers.
using std::string;

class Player;

//territory functions-----------------------------------------------------------------------------------------
Territory::Territory()
{
	//Allocate memory to pointers.
	territoryId = new int(1);
	territoryName = new string("");
	troopsSationed = new  int(0);
	inContinent = new  int(0);
	Owner = nullptr;
}

Territory::Territory(int id, string name, int continent)
{
	territoryId = new int(1);
	territoryName = new string("");
	troopsSationed = new  int(0);
	inContinent = new  int(0);
	*territoryId =id;
	*territoryName = name;
	*inContinent = continent;
	Owner = nullptr;
}

Territory::~Territory()
{
	delete territoryId;
	delete troopsSationed;
	delete territoryName;
	delete inContinent;
	delete Owner;
}

void Territory::SetOwner(Player* p1)
{
	this.Owner->removePTerritory(this);//to do fix this so it checks if the the territory is owned and removes it from the current owner 
	Owner = p1;
	p1->addPTerritory(this);//need to make sure this works and makes sense----------------------------
}

Player* Territory::getOwner() 
{
	std::cout << "Player #"<< Owner->getPName() <<" owns this territory \n";
	return Owner;
}


string Territory::toString() //to do fix so I can print adjacent
{
	string temp = "\nTeritory ID: " + std::to_string((int)*territoryId) + "\nTeritory Name: "+*territoryName;
	if (Owner != nullptr) { temp += "\nOwner: " + Owner->getPName() + "\n"; }
	else { temp += "\nOwner: No current Owner\n"; };
	if (troopsSationed != nullptr) temp += "Troops stationed: " + std::to_string((int)*troopsSationed);
	if(*inContinent!=0) { temp += "\nIn contenent: " + std::to_string((int)*inContinent) + "\n"; }
	else { temp += "\nIn contenent: No current contenent\n"; };
	//temp+="\nAdjacent:\n";
	//for (auto&& x : adjacent) temp += "\t" + std::to_string((int)x->getTerritoryId) + "\n";// to do find a way to get this
	return temp;
}

int Territory::getTroopsSationed()
{
	return *troopsSationed;
}

void Territory::setTroopsSationed(int troops)
{
	*troopsSationed = troops;
}

void Territory::addTroopsSationed(int troops)
{
	*troopsSationed += troops;
}
void Territory::setTerritoryId(int tid) 
{
	*territoryId = tid;
}

int Territory::getTerritoryId()
{
	return *territoryId;
}

void Territory::setTerritoryName(string name)
{
	*territoryName = name;
}

string Territory::getTerritoryName()
{
	return *territoryName;
}

void Territory::setInContinent(int contNum)
{
	*inContinent = contNum;
}

int Territory::getInContinent()
{
	return *inContinent;
}
void Territory::addAdjacent(Territory* tid)
{
	adjacent.push_back(tid);
}

bool Territory::isAdjacent(Territory* tid)
{
	for (auto&& x : adjacent) if (x == tid) return true;
	return false;
}


//contenent functions------------------------------------------------------------------------------------
Continent::Continent()
{
	contName =  new string("");
	reinforcementValue = new int(1);
	continentId = new int(0);
}

Continent::Continent(string name, int id, int reinforcement)
{
	contName = new string("");
	reinforcementValue = new int(1);
	continentId = new int(0);
	*contName =name;//name of the continent
	*reinforcementValue= reinforcement;// the number of reinforecemnt one gets for holding this contentent
	*continentId =id;
}

Continent::~Continent()
{
	delete contName;
	delete reinforcementValue;
	delete continentId;
}

int Continent::getReinforcementValue()
{
	return *reinforcementValue;
}

void Continent::setReinforcementValue(int reinforceNum)
{
	*reinforcementValue = reinforceNum;
}

void Continent::addTerritory(Territory* tid) {
	territoryVector.push_back(tid);
}

bool Continent::isContained(Territory* tid) 
{
	for (auto&& x : territoryVector) if (x == tid) return true;
	return false;
}

string Continent::toString()
{
	string temp = "";
	//to do fill in temp += "...";
	return temp;
}
string Continent::getContName()
{
	return *contName;
}

void Continent::setContName(string name)
{
	*contName = name;
}

int Continent::getContinentId()
{
	return *continentId;
}

void Continent::setContinentId(int cid)
{
	*continentId = cid;
}


//map functions-----------------------------------------------------------------------------------
Map::Map()
{
	mapName =new string("");;
	validMap = new bool(true);
}

Map::~Map()
{
}

string Map::getMapName()
{
	return *mapName;
}

void Map::setMapName(string mName)
{
	*mapName = mName;
}

bool Map::validate()
{
	//to do fill with logic
	return false;
}