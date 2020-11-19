/***********************************************************************
	Assignment 1 - TEAM 21
	Part 4
***********************************************************************/

#pragma once

#include "Map.h"
#include "Order.h"
#include <list>
#include "Cards.h"
#include <sstream>
class Order;
class Orderlist;
class Card;
class Hand;
class Player
{

public:

	Player(string playerName);
	Player(string playerName, const char* pid);

	//Copy constructor
	Player(const Player& anotherPlayer);

	//Returns a list of territories to attack
	list<Territory>* toAttack();

	//Returns a list of territories to defend
	list<Territory>* toDefend();

	//Creates an object containing this player's list of Order
	void issueOrder(Order o);


	//Executes player Order
	void executeOrder();

	//Add Order to list of Order
	void addOrder(Order order);

	//List plyer Order
	list<Order>* listPlayerOrder();

	//Add card to hand of cards
	void addcardToHandOfCards(Card* card);

	//Adds a terrytory to the player's territories
	void addMyTerritory(Territory aTerrytory);

	//Adds a terrytory to the player's target territories
	void addTargetTerritory(Territory aTerrytory);

	void setThisPlayerRef(Player* myPlayer);

	void destroyPlayerObject();

	friend std::ostream& operator<<(std::ostream&, const Player);

	Player& operator = (const Player& t);

	const char* getPlayerID();
	string getPlayerName();

	~Player();

	int getreinforcePool();//getter of reinforcePool
	int getTurnNumber();
	int getNumTerritoriesOwn();
	void setreinforcePool(int value);//setter/mutator of reinforcePool
	void setNumTerritoriesOwn(int value);
	void setTurnNumber(int value);

	void addTerritory(Territory* terrytory);
	void addArmiesToTerritory(Territory* territory, int value);
	vector<Territory*> getTerritoriesOwn();
	void removeTerritory(Territory* terrytory);
	void issueOrdertoList(Order* o);
	//Executes player Order
	void executeOrderOfList(Order* o);
	//Add Order to list of Order
	void addOrderToList(Order* order);
	void addOrderToList(Deploy* order);
	void addOrderToList(Advance* order);
	void addOrderToList(Bomb* order);
	void addOrderToList(Blockade* order);
	void addOrderToList(Airlift* order);
	void addOrderToList(Negotiate* order);
	
	//List plyer Order
	Orderlist* getOrderlist();
	void removeOrderOrderList(Order* o);
	void executeOrderOfList(Deploy* o);
	void executeOrderOfList(Advance* o);
	void executeOrderOfList(Bomb* o);
	void executeOrderOfList(Blockade* o);
	void executeOrderOfList(Airlift* o);
	void executeOrderOfList(Negotiate* o);
	void setConqueredTerratory(bool set);
	bool getConqueredTerratory();
	Hand* getHand();
	void Play(string cd, Deck adeck);
private:

	//myTerritories contains a list of pointers to territories. Each territory is unique and can be owned by one player at the time and we will manipulate the pointer to that territory.
	//Create pointer to a list ofpointers to territories
	list<Territory>* myTerritories;
	vector<Territory*> territoriesOwn;
	//targetTerritories contains a list of pointers to territories. Each territory is unique,
	list<Territory>* targetTerritories;
	Orderlist* myOrderList;
	//List of Order
	list<Order>* myOrder;
	//list<Card > * handOfCards;
	Hand* handOfCards;
	const char* playerID;
	Player* thisPlayerRef = nullptr;
	string playerName;
	int reinforcePool;//holds th ammout to be used in the reinforcement
	int turnNumber;
	int numberTerritoriesOwn;
	bool conqueredTerratory;
};


Player* playerFactory(string pid);