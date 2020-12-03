
/***********************************************************************
	Assignment 3 - TEAM 21

***********************************************************************/

/*
#include "Order.h"
#include <iostream>
#include <time.h>
#include "Map.h"
#include "Player.h"


using namespace std;


//COMP 345 A1
//Team 21

void printTerr(Player* pla1, Player* pla2) {

	vector<Territory*> p1TerritoryList = pla1->getTerritoriesOwn();
	vector<Territory*> p2TerritoryList = pla2->getTerritoriesOwn();

	cout << "Player 1's territories: ";
	for (auto element : p1TerritoryList) {
		cout << " " << element->getTerritoryName() << " Units: " << element->getTerritoryArmies();
	}
	cout << "\n";

	cout << "Player 2's territories: ";
	for (auto element : p2TerritoryList) {
		cout << " " << element->getTerritoryName() << " Units: " << element->getTerritoryArmies();
	}
	cout << "\n";
}

int main() {

	Continent c1(0, 1, "Continent A", 2);
	Continent c2(0, 2, "Continent A", 1);
	Continent c3(1, 2, "Continent C", 3);

	Map* m1;
	m1 = new Map();
	m1->createMap(3, false);
	Territory* t1 = new Territory(0, 1, "Territory1", c1);
	Territory* t2 = new Territory(0, 2, "Territory2", c2);
	Territory* t3 = new Territory(1, 2, "Territory3", c3);
	m1->addEdge(t1);
	m1->addEdge(t2);
	m1->addEdge(t3);
	m1->displayAdjacencyList();
	m1->validate();

	t1->setTerritoryArmies(0);
	t3->setTerritoryArmies(0);
	t2->setTerritoryArmies(0);

	Player* p1 = new Player("Player 1");
	Player* p2 = new Player("Player 2");

	p1->addTerritory(t1);
	p1->addTerritory(t2);

	p2->addTerritory(t3);

	p1->setreinforcePool(15);
	p2->setreinforcePool(5);

	Deploy* deploy1 = new Deploy(p1, t1, 12);
	deploy1->execute();
	
	Deploy* deploy2 = new Deploy(p1, t2, 3);
	deploy2->execute();
	
	Deploy* deploy3 = new Deploy(p2, t3, 5);
	deploy3->execute();
	cout << "\n";

	cout <<"Armies in t1: "<< t1->getTerritoryArmies() << "\n";
	cout << "Armies in t2: " << t2->getTerritoryArmies() << "\n";
	cout << "Armies in t3: " << t3->getTerritoryArmies() << "\n";
		
	cout << "\n\n";
	printTerr(p1, p2);


/////ADVANCE
	cout << "\n";
	Advance* advance = new Advance(p1,p2, t1, t3, 10);
	advance->execute();
	cout << "\n";

	printTerr(p1,p2);

/////BOMB
	cout << "\n";
	Bomb* bomb = new Bomb(p2, t3);
	bomb->execute();
	cout << "\n";
	printTerr(p1, p2);


/////BLOCKADE
	cout << "\n";
	Blockade* blockade = new Blockade(p1, t3);
	blockade->execute();
	cout << "\n\n";
	printTerr(p1, p2);
	cout << "\n\n" << "Units in t3" << t3->getTerritoryArmies();

}

*/
