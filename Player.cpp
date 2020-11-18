/***********************************************************************
	Assignment 1 - TEAM 21
	Part 4
***********************************************************************/
#include "Player.h"
#include <list>
#include "Map.h"
#include "Cards.h"
#include <sstream>
#include "Order.h"

Player::Player(string playerName, const char* pid) {

	playerID = pid;
	playerName = playerName;

	//Allocate memory to Order list.
	try {
		myOrder = new list<Order>();

		cout << "myOrder list dynamically created.\n" << endl;
	}
	catch (bad_alloc&) {
		cout << "Error allocating memory to player." << endl;
		exit(1);
	}


	//Allocate memory to my territories list.
	try {
		myTerritories = new list<Territory>;
		cout << "myTerritories list dynamically created.\n" << endl;
	}
	catch (bad_alloc&) {
		cout << "Error allocating memory to player." << endl;
		exit(1);
	}


	//Allocate memory to target territories list.
	try {
		targetTerritories = new list<Territory>;
		cout << "targetTerritories list dynamically created.\n" << endl;
	}
	catch (bad_alloc&) {
		cout << "Error allocating memory to player." << endl;
		exit(1);
	}

	//Allocate memory to territories list.
	try {
		handOfCards = new Hand();
		cout << "Player hand of cards dynamically created.\n" << endl;
	}
	catch (bad_alloc&) {
		cout << "Error allocating memory to player hand of cards." << endl;
		exit(1);
	}

}

Player::Player(string playerName)
{
	this->playerName = playerName;
	cout << "\nCreating: " << playerName << endl;
	
	////Allocate memory to Order list.
	//try {
	//	myOrder = new list<Order>();
	//	cout << "Order list dynamically created." << endl;
	//}
	//catch (bad_alloc&) {
	//	cout << "Error allocating memory to player." << endl;
	//	exit(1);
	//}

	////Allocate memory to my territories list.
	//try {
	//	myTerritories = new list<Territory>;
	//	cout << "Territories list dynamically created." << endl;
	//}
	//catch (bad_alloc&) {
	//	cout << "Error allocating memory to player." << endl;
	//	exit(1);
	//}

	//

	////Allocate memory to target territories list.
	//try {
	//	targetTerritories = new list<Territory>;
	//	cout << "targetTerritories list dynamically created." << endl;
	//}
	//catch (bad_alloc&) {
	//	cout << "Error allocating memory to player." << endl;
	//	exit(1);
	//}

	////Allocate memory to territories list.
	//try {
	//	handOfCards = new Hand();
	//	cout << "Player hand of cards dynamically created." << endl;
	//}
	//catch (bad_alloc&) {
	//	cout << "Error allocating memory to player hand of cards." << endl;
	//	exit(1);
	//}
}

//Player copy constructor
Player::Player(const Player& anotherPlayer) {
	playerID = anotherPlayer.playerID;//does nothing as it is a const pointer cannot move the intial allocated memmory
	playerName = anotherPlayer.playerName;
	targetTerritories = nullptr;
	myOrder = nullptr;
	myTerritories = nullptr;
	handOfCards = nullptr;

	list<Territory>::iterator ptrTarget;
	list<Territory>::iterator ptrTerritory;
	list<Order>::iterator ptrOrder;
	list<Card>::iterator ptrCards;

	//Copy target territories
	if (!(anotherPlayer.targetTerritories->empty())) {
		if (targetTerritories == nullptr) {
			targetTerritories = new list<Territory>;
		}
		for (ptrTarget = anotherPlayer.targetTerritories->begin(); ptrTarget != anotherPlayer.targetTerritories->end(); ++ptrTarget) {
			targetTerritories->push_back(*ptrTarget);
		}
	}
	//Copy territories
	if (!(anotherPlayer.myTerritories->empty())) {
		if (myTerritories == nullptr) {
			myTerritories = new list<Territory>;
		}
		for (ptrTerritory = anotherPlayer.myTerritories->begin(); ptrTerritory != anotherPlayer.myTerritories->end(); ++ptrTerritory) {
			myTerritories->push_back(*ptrTerritory);
		}
	}
	//Copy cards ( just need to copy the reference to the hand of cards)
	handOfCards = new Hand(*anotherPlayer.handOfCards);

	//Copy Order
	if (!(anotherPlayer.myOrder->empty())) {
		if (myOrder == nullptr) {
			myOrder = new list<Order>;
		}
		for (ptrOrder = anotherPlayer.myOrder->begin(); ptrOrder != anotherPlayer.myOrder->end(); ++ptrOrder) {
			myOrder->push_back(*ptrOrder);
		}
	}

}


//Player assignment operator
Player& Player::operator= (const Player& t)
{
	cout << "Player assignment operator called " << endl;
	return *this;
}


list<Territory >* Player::toAttack() {

	list<Territory >::iterator ptr;
	int i = 0;

	std::cout << "Lit of territories to attack: \n";

	for (ptr = targetTerritories->begin(); ptr != targetTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}

	std::cout << std::endl;


	return targetTerritories;
}
list<Territory >* Player::toDefend() {

	list<Territory >::iterator ptr;
	int i = 0;
	std::cout << "Lit of territories to defend: \n";
	for (ptr = myTerritories->begin(); ptr != myTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}
	std::cout << std::endl;

	return myTerritories;
}
void Player::issueOrder(Order o) {

	myOrder->push_back(o);

	return;
}

void Player::executeOrder() {

	std::cout << "Executing order: ....\n";
	return;
}

list<Order>* Player::listPlayerOrder() {
	list<Order>::iterator ptr;
	int i = 0;
	std::cout << "My list of Order: \n";
	for (ptr = myOrder->begin(); ptr != myOrder->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";

	}
	std::cout << std::endl;

	return myOrder;
}

void Player::addOrder(Order order) {

	myOrder->push_back(order);
	return;
}

void Player::setThisPlayerRef(Player* myPlayer) {
	thisPlayerRef = myPlayer;
}

void Player::addMyTerritory(Territory aTerrytory) {

	//Add territory at the end of myTerritories
	cout << "Adding territory: " << aTerrytory << "\n";
	this->myTerritories->push_back(aTerrytory);
	return;
}

void Player::addTargetTerritory(Territory aTerrytory) {

	//Add territory at the end of myTerritories
	targetTerritories->push_back(aTerrytory);
	return;
}

void Player::addcardToHandOfCards(Card* card) {

	handOfCards->addCard(card);
	return;
}


std::ostream& operator<<(std::ostream& strm, const Player p)
{
	return strm << "Player ID: " << p.playerName << "\n";
}

//Returns this player's ID
const char* Player::getPlayerID() {
	return playerID;
}

string Player::getPlayerName()
{
	return playerName;
}

Player* playerFactory(string pid) {

	Player* myPlayer = nullptr;

	//Allocate memory to player.
	try {
		myPlayer = new Player(pid);
		cout << "Player " << pid << " dynamically created.\n" << endl;
	}
	catch (bad_alloc&) {
		cout << "Error allocating memory to player." << endl;
		exit(1);
	}

	myPlayer->setThisPlayerRef(myPlayer);
	return myPlayer;
}



Player::~Player() {
	destroyPlayerObject();;
}


//Clean heap memory used by player objects
void Player::destroyPlayerObject() {
	if (!(playerID == nullptr)) {
		cout << "Cleaning player " << this->playerID << " from heap before ending program.\n" << endl;
	}
	if (!(handOfCards == nullptr)) {
		delete handOfCards;
	}
	if (!(myOrder == nullptr)) {
		delete myOrder;
	}
	if (!(myTerritories == nullptr)) {
		delete myTerritories;
	}
	if (!(targetTerritories == nullptr)) {
		delete targetTerritories;
	}
	for (auto& x : territoriesOwn) {
		delete x;
		x = NULL;
	}
	myOrder = NULL;
	myTerritories = NULL;
	targetTerritories = NULL;
	handOfCards = NULL;
}

int Player::getreinforcePool() { return reinforcePool; }
int Player::getTurnNumber()
{
	return turnNumber;
}
int Player::getNumTerritoriesOwn()
{
	return numberTerritoriesOwn;
}
void Player::setreinforcePool(int value) { if (value >= 0) { reinforcePool = value; } }

void Player::setNumTerritoriesOwn(int value)
{
	this->numberTerritoriesOwn = value;
}

void Player::setTurnNumber(int value)
{
	this->turnNumber = value;
}

void Player::addTerritory(Territory* terrytory)
{
	//Add territory at the end of myTerritories
	this->territoriesOwn.push_back(terrytory);
	return;
}

void Player::addArmiesToTerritory(Territory* territory, int value)
{
	territory->setTerritoryArmies(value);
}

vector<Territory*> Player::getTerritoriesOwn()
{
	return this->territoriesOwn;
}

void Player::removeTerritory(Territory* aterrytory) {
	int temp = 0;
	for (auto&& x : territoriesOwn) {
		if (x == aterrytory) { delete x; break; }
		temp++;
	}
	territoriesOwn.erase(territoriesOwn.begin() + temp);
}
/*void Player::removeMyTerritory(Territory aTerrytory) {
	myTerritories->remove(aTerrytory);
}
void Player::removeTargetTerritory(Territory aTerrytory) {
	targetTerritories->remove(aTerrytory);
}
void Player::removeOrder(Order o) {
	myOrder->remove(o);
}*/
