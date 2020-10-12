/***********************************************************************
	Assignment 1 - TEAM 21
	Part 4
*/

/**********************************************************************/

#pragma once
#include "Territory.h"
#include "Map.h"
#include "Orders.h"
#include <list>
#include "Cards.h"
#include <sstream>

class Player
{
	
public:

	Player(const char * pid);

	//Copy constructor
	Player(const Player& anotherPlayer);

	//Returns a list of territories to attack
	list<Territory> * toAttack(); 

	//Returns a list of territories to defend
	list<Territory> * toDefend();

	//Creates an object containing this player's list of orders
	void issueOrders(Orders o);

	/*TODO
		- add copy constructor
		- add assigment operator
		- add stream insertion operator
		
	*/

	//Executes player orders
	void executeOrder();

	//Add orders to list of orders
	void addOrders(Orders order);

	//List plyer orders
	list<Orders>* listPlayerOrders();

	//Add card to hand of cards
	void addcardToHandOfCards(Cards card);

	//Adds a terrytory to the player's territories
	void addMyTerritory(Territory aTerrytory);


	//Adds a terrytory to the player's target territories
	void addTargetTerritory(Territory aTerrytory);

	void setThisPlayerRef(Player * myPlayer);

	void destroyPlayerObject();

	friend std::ostream& operator<<(std::ostream&, const Player);

	Player& operator = (const Player& t);
	
	const char* getPlayerID();

	~Player();
		
private:

	//myTerritories contains a list of pointers to territories. Each territory is unique and can be owned by one player at the time and we will manipulate the pointer to that territory.
	//Create pointer to a list ofpointers to territories
	list<Territory> *myTerritories;

	//targetTerritories contains a list of pointers to territories. Each territory is unique,
	list<Territory> *targetTerritories;

	//List of orders
	list<Orders> * myOrders;
	
	list<Cards > * handOfCards;

	const char * playerID;
	Player * thisPlayerRef = nullptr;

};


Player *playerFactory(const char * pid);