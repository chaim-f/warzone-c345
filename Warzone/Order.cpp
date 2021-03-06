/*COMP 345 A1
  Team 21
*/
#include "Order.h"
#include "Map.h"
#include "Player.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <time.h>


Order::Order() { setName("Order"); };

Order::Order(const Order& o) {
	name = o.name;
};

bool Order::validate() { return true; };
bool Order::execute() { return validate(); }
void Order::setName(string n) { name = n; }
string Order::getName() { return name; }

Order& Order::operator= (const Order& o) {
	name = o.name;
	return *this;
};


std::ostream& operator<<(std::ostream& strm, Order& o)
{
	return strm << o.getName();
};

//The subclasses have no attributes implemented yet
//As a result the validate and execute are just skeleton functions

//Deploy
Deploy::Deploy() {
	setName("Deploy");
	cout << "Created a deploy order\n";
};

Deploy::Deploy(const Deploy& o) {
	name = o.name;
	this->army = o.army;
	this->player = o.player;
	this->territory = o.territory;

};

Deploy::Deploy(Player* player, Territory* territory, int army) {
	this->army = army;
	this->player = player;
	this->territory = territory;
	setName("Deploy");
	cout << "Created a deploy order\n";
};

bool Deploy::validate() {

	vector<Territory*> myTerr = player->getTerritoriesOwn();
	bool territoryIsInList = std::find(myTerr.begin(), myTerr.end(), territory)
		!= myTerr.end();
	
	cout << "Deploy is valid: " << territoryIsInList;
	return territoryIsInList;

};

bool Deploy::execute() {

	if (validate()) {
		if (player->getreinforcePool() - army < 0) {
			army = player->getreinforcePool();
		}

		player->setreinforcePool((player->getreinforcePool()) - army);
		territory->setTerritoryArmies((territory->getTerritoryArmies()) + army);

		return true;
	}
	else {
		cout << "Deploy order not valid\n";
		return validate();
	}

}

Deploy& Deploy::operator= (const Deploy& o) {
	name = o.name;
	return *this;
};


//Advance
Advance::Advance() {
	setName("Advance");
	cout << "Created an advance order\n";
}

Advance::Advance(Player* player, Player* playerB, Territory* myTerritory, Territory* otherTerritory, int army)
{
	this->player = player;
	this->myTerritory = myTerritory;
	this->otherTerritory = otherTerritory;
	this->playerB = playerB;
	this->army = army;
	setName("Advance");
	cout << "Created an advance order\n";
}
;

Advance::Advance(const Advance& o) {
	name = o.name;
	this->player = o.player;
	this->myTerritory = o.myTerritory;
	this->otherTerritory = o.otherTerritory;
	this->playerB = o.playerB;
	this->army = o.army;
};

bool Advance::validate() {

	vector<Territory*> myTerr = player->getTerritoriesOwn();
	bool territoryIsInList = std::find(myTerr.begin(), myTerr.end(), myTerritory)
		!= myTerr.end();
	
	cout << "Advance is valid: " << territoryIsInList;
	// source territory doesn't belong to me
	if (territoryIsInList)
		return true;

	else
		return false;


};
bool Advance::execute() {

	if (!validate())
		return false;

	vector<Territory*> myTerr = player->getTerritoriesOwn();
	bool otherTerrIsMine = std::find(myTerr.begin(), myTerr.end(), otherTerritory)
		!= myTerr.end();

	//Both territories are mine
	if (otherTerrIsMine) {
		
		myTerritory->setTerritoryArmies((myTerritory->getTerritoryArmies() - army));
		otherTerritory->setTerritoryArmies((otherTerritory->getTerritoryArmies() + army));
		
		
	}
	//Source territory is mine, Dest territory is Other
	else {
		
		srand(static_cast<unsigned int>(time(NULL)));
		int diceroll;
		myTerritory->setTerritoryArmies((myTerritory->getTerritoryArmies() - army));

		int defArmy = otherTerritory->getTerritoryArmies();

		while (defArmy != 0 && army != 0) {
			
			diceroll = (rand() % 10) + 1;
			if (diceroll < 7)
				defArmy--;

			diceroll = (rand() % 10) + 1;
			if (diceroll < 8)
				army--;
			
		}

		otherTerritory->setTerritoryArmies(defArmy);
		if (defArmy == 0 && army > 0) {
			
			playerB->removeTerritory(otherTerritory);
			player->addTerritory(otherTerritory);
			player->addArmiesToTerritory(otherTerritory, army);

			//player->addcardToHandOfCards();
		}
		
			
	}

	return true;
}

Advance& Advance::operator= (const Advance& o) {
	name = o.name;
	return *this;

};

//Bomb
Bomb::Bomb() {
	setName("Bomb");
	cout << "Created a bomb order\n";
};

Bomb::Bomb(const Bomb& o) {
	name = o.name;
	this->player = o.player;
	this->otherTerritory = o.otherTerritory;

}
Bomb::Bomb(Player* player, Territory* otherTerritory)
{
	this->player = player;
	this->otherTerritory = otherTerritory;
	setName("Bomb");
	cout << "Created a bomb order\n";
}
;


bool Bomb::validate() {

	vector<Territory*> myTerr = player->getTerritoriesOwn();
	bool territoryIsInList = std::find(myTerr.begin(), myTerr.end(), otherTerritory)
		!= myTerr.end();

	cout << "Bomb is valid: " << !territoryIsInList;
	return !territoryIsInList;

};
bool Bomb::execute() {

	if (!validate())
		return false;

	otherTerritory->setTerritoryArmies(otherTerritory->getTerritoryArmies() / 2);

	return true;
}

Bomb& Bomb::operator= (const Bomb& o) {
	name = o.name;
	return *this;

};


//Blockade
Blockade::Blockade() {
	setName("Blockade");
	cout << "Created a blockade order\n";
}
Blockade::Blockade(Player* player, Territory* myTerritory)
{
	this->player = player;
	this->myTerritory = myTerritory;
	setName("Blockade");
	cout << "Created a blockade order\n";
}
;

Blockade::Blockade(const Blockade& o) {
	name = o.name;
	this->player = o.player;
	this->myTerritory = o.myTerritory;

};

bool Blockade::validate() {

	vector<Territory*> myTerr = player->getTerritoriesOwn();
	bool territoryIsInList = std::find(myTerr.begin(), myTerr.end(), myTerritory)
		!= myTerr.end();
	cout << "Blockade is valid: " << territoryIsInList;
	return territoryIsInList;

};

bool Blockade::execute() {

	if (!validate())
		return false;

	myTerritory->setTerritoryArmies(myTerritory->getTerritoryArmies() * 2);
	player->removeTerritory(myTerritory);

	return true;


}

Blockade& Blockade::operator= (const Blockade& o) {
	name = o.name;
	return *this;

};

//Airlift
Airlift::Airlift() {
	setName("Airlift");
	cout << "Created an airlift order\n";
}

Airlift::Airlift(Player* player, Territory* fromTerritory, Territory* toTerritory, int army)
{
	this->player = player;
	this->fromTerritory = fromTerritory;
	this->toTerritory = toTerritory;
	this->army = army;
	setName("Airlift");
	cout << "Created an airlift order\n";
}
;

Airlift::Airlift(const Airlift& o) {
	name = o.name;
	this->player = o.player;
	this->fromTerritory = o.fromTerritory;
	this->toTerritory = o.toTerritory;
	this->army = o.army;

};

bool Airlift::validate() {

	vector<Territory*> myTerr = player->getTerritoriesOwn();
	bool territoryAIsInList = std::find(myTerr.begin(), myTerr.end(), fromTerritory)
		!= myTerr.end();

	bool territoryBIsInList = std::find(myTerr.begin(), myTerr.end(), toTerritory)
		!= myTerr.end();

	
	cout << "Airlift is valid: " << territoryAIsInList && territoryBIsInList;
	return territoryAIsInList && territoryBIsInList;

};
bool Airlift::execute() {

	if (!validate())
		return false;

	fromTerritory->setTerritoryArmies(fromTerritory->getTerritoryArmies() - army);
	toTerritory->setTerritoryArmies(toTerritory->getTerritoryArmies() + army);

	return true;
}

Airlift& Airlift::operator= (const Airlift& o) {
	name = o.name;
	return *this;

};


//Negotiate
Negotiate::Negotiate() {
	setName("Negotiate");
	cout << "Created a negotiate order\n";
}

Negotiate::Negotiate(Player* player, Player* otherPlayer)
{
	this->player = player;
	this->otherPlayer = otherPlayer;
	setName("Negotiate");
	cout << "Created a negotiate order\n";
}
;

Negotiate::Negotiate(const Negotiate& o) {
	name = o.name;
	this->player = o.player;
	this->otherPlayer = o.otherPlayer;

};

bool Negotiate::validate() {
	cout << "Negotiate is valid: " << (player != otherPlayer);
	return player != otherPlayer;

};
bool Negotiate::execute() {

	if (!validate())
		return false;



	return true;
}

Negotiate& Negotiate::operator= (const Negotiate& o) {
	name = o.name;
	return *this;

};

//Orderlist

Orderlist::Orderlist() { };

Orderlist::Orderlist(const Orderlist& ol) {
	orderList = ol.orderList;

}

void Orderlist::add(Order* order) {
	orderList.push_back(order);
}

bool Orderlist::remove(Order* order) {
	
	for (auto it = orderList.begin(); it != orderList.end(); it++)
		if (*it == order) {
			delete* it;//delete what the pointer is pointing to not sure if this is correct
			orderList.erase(it);
			return true;
		}
	return false;
}


void Orderlist::move(Order* insertOrder, Order* destinationOrder) {


	auto insert = std::find(orderList.begin(), orderList.end(), insertOrder);
	
	auto destination = std::find(orderList.begin(), orderList.end(), destinationOrder);

	orderList.splice(destination, orderList, insert);

}


std::ostream& operator<<(std::ostream& strm, const Orderlist& ol)
{	
	for (auto it = ol.orderList.begin(); it != ol.orderList.end(); it++)
		strm << (*it) << " ";

	return strm;
};

Orderlist::~Orderlist() {
	for (auto& x : orderList) {
		delete x;
	}
}
list <Order*> Orderlist::getOrderList() {
	return orderList;
}
bool  Orderlist::OrderListIsEmpty() {
	if (orderList.empty()) { return true; }
	cout << "\n returned false\n";
	return true;
}
void Orderlist::printOrderList() {
	for (auto& x:orderList) {
		cout << *x;
	}
}

