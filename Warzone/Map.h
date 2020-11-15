#pragma once
#include <string>
#include <vector> 
#include "Player.h"
using std::string;
class Player;

class Territory
	// need to add copy constructor, = operator overload, maybe other types of constructors.---------------------
{
public:
	Territory();//default constructor
	Territory(int id,string name,int continent);//maybe add constructor with troops and owner
	~Territory();//destructor
	void SetOwner(Player *p1);//change the owner of the territory to another player
	Player* getOwner();// return which player currently owns the territory
	int getTroopsSationed();//how many troops are stationed here
	void setTroopsSationed(int troops=1);//set how many troops
	void addTroopsSationed(int troops=1);// add troops as reinforcemt or minus of troops as they die (troops = -1||-2)
	string toString();//return the state of the territory as a string
	void setTerritoryId(int tid);
	int getTerritoryId();
	void setTerritoryName(string name);
	string getTerritoryName();
	void setInContinent(int contNum);
	int getInContinent();
	std::vector <Territory*> adjacent;
	void addAdjacent(Territory* tid);//Add a territories id in this adjacent vector
	bool isAdjacent(Territory* tid);//Checks if a territory is adjacent
private:
	int* territoryId;
	int* troopsSationed;
	string* territoryName;
	int* inContinent;
	Player* Owner;
	//Continent* contenentName; //add if needed, need to add get and set as well as method to pair with inContenent or delete inContenent.
};



class  Continent
	// need to add copy constructor, = operator overload, maybe other types of constructors.---------------------
{
public:
	 Continent();
	 Continent(string name,int id, int reinforcement);
	~ Continent();
	int getReinforcementValue();//get the number of reinforecemnt one gets for holding this contentent (might not apply for warzone if anyone on the team knows the rules please comment).
	void setReinforcementValue(int a);//Sets the number of reinforecemnt one gets for holding this contentent
	std::vector <Territory*> territoryVector;// territorites in this contenent
	void addTerritory(Territory* tid);//Add a territories id in this continent to the list
	bool isContained(Territory* tid);//Checks if a territory is in this continent
	string toString();//return the state of the Contenent as a string
	string getContName();
	void setContName(string name);
	int getContinentId();
	void setContinentId(int cid);
private:
	string* contName;//name of the continent
	int* reinforcementValue;// the number of reinforecemnt one gets for holding this contentent
	int* continentId;
};



 class Map
	 // need to add copy constructor, = operator overload, maybe other types of constructors.---------------------
 {
 public:
	 Map();
	 //to do add diffrent constructors
	 ~Map();
	 //std::vector <Territory*> MapterritoryVector;
	 std::vector <Territory*> MapContinentVector;
	 bool validate();
	 string getMapName();
	 void setMapName(string mName);
 private:
	 string* mapName;
	 bool* validMap;
 };

