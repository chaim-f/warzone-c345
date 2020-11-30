#pragma once
#include <list>
#include "Map.h"
#include "Order.h"


//class Territory;
//class Order;

class PlayerStrategies
{

public:
	PlayerStrategies();
	~PlayerStrategies();

	//Returns a list of territories to attack
	virtual list<Territory>* toAttack(list<Territory>* targetTerritorie) = 0;

	//Returns a list of territories to defend
	virtual list<Territory>* toDefend(list<Territory>* myTerritories) = 0;

	//Creates an object containing this player's list of Order
	virtual void issueOrder(Order o, list<Order>* myOrder) = 0;

private:


};


/*****************************************HumanPlayerStrategy***********************************/

class HumanPlayerStrategy : public PlayerStrategies
{
public:
	HumanPlayerStrategy();
	~HumanPlayerStrategy();


	//Returns a list of territories to attack
	list<Territory>* toAttack(list<Territory>* targetTerritorie);

	//Returns a list of territories to defend
	list<Territory>* toDefend(list<Territory>* myTerritories);

	//Creates an object containing this player's list of Order
	void issueOrder(Order o, list<Order>* myOrder);

private:

};





/***************************************AggressivePlayerStrategy*****************************/
class AggressivePlayerStrategy : public PlayerStrategies
{
public:
	AggressivePlayerStrategy();
	~AggressivePlayerStrategy();


	//Returns a list of territories to attack
	list<Territory>* toAttack(list<Territory>* targetTerritorie);

	//Returns a list of territories to defend
	list<Territory>* toDefend(list<Territory>* myTerritories);

	//Creates an object containing this player's list of Order
	void issueOrder(Order o, list<Order>* myOrder);

private:

};




/****************************************BenevolentPlayerStrategy**********************************/
class BenevolentPlayerStrategy : public PlayerStrategies
{
public:
	BenevolentPlayerStrategy();
	~BenevolentPlayerStrategy();


	//Returns a list of territories to attack
	list<Territory>* toAttack(list<Territory>* targetTerritorie);

	//Returns a list of territories to defend
	list<Territory>* toDefend(list<Territory>* myTerritories);

	//Creates an object containing this player's list of Order
	void issueOrder(Order o, list<Order>* myOrder);

private:

};


/*******************************************NeutralPlayerStrategy*************************************/

class NeutralPlayerStrategy : public PlayerStrategies
{
public:
	NeutralPlayerStrategy();
	~NeutralPlayerStrategy();

	//Returns a list of territories to attack
	list<Territory>* toAttack(list<Territory>* targetTerritorie);

	//Returns a list of territories to defend
	list<Territory>* toDefend(list<Territory>* myTerritories);

	//Creates an object containing this player's list of Order
	void issueOrder(Order o, list<Order>* myOrder);

private:

};

