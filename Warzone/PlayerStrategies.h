/***********************************************************************
	Assignment 3 - TEAM 21

***********************************************************************/

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

	virtual string getStrategyName() = 0;

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
	string getStrategyName();
private:
	string strategyName;
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
	string getStrategyName();
private:
	string strategyName;
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
	string getStrategyName();
private:
	string strategyName;
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

	string getStrategyName();

private:
	string strategyName;
};

