/***********************************************************************
	Assignment 3 - TEAM 21

***********************************************************************/

#include "PlayerStrategies.h"
#include <sstream>






/*************************Player Strategy Master Class impl*********************************/
PlayerStrategies::PlayerStrategies() {

}


PlayerStrategies::~PlayerStrategies() {

}




/*************************************HumanPlayerStrategy **************************************/

HumanPlayerStrategy::HumanPlayerStrategy() {

	strategyName = "HumanPlayer";
}

HumanPlayerStrategy::~HumanPlayerStrategy() {

}



//Returns a list of territories to attack
list<Territory>* HumanPlayerStrategy::toAttack(list<Territory>* targetTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;

	std::cout << "Lit of territories to attack by HumanPlayer: \n";

	for (ptr = targetTerritories->begin(); ptr != targetTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}

	std::cout << std::endl;


	return targetTerritories;
}

//Returns a list of territories to defend
list<Territory>* HumanPlayerStrategy::toDefend(list<Territory>* myTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;
	std::cout << "List of territories to defend by HumanPlayer: \n";
	for (ptr = myTerritories->begin(); ptr != myTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}
	std::cout << std::endl;

	return myTerritories;
}

//Creates an object containing this player's list of Order
void HumanPlayerStrategy::issueOrder(Order o, list<Order>* myOrder) {

	std::cout << "Order issued by HumanPlayer: \n";
	myOrder->push_back(o);

	return;
}




/*************************************AggressivePlayerStrategy **************************************/

AggressivePlayerStrategy::AggressivePlayerStrategy() {

	strategyName = "AggressivePlayer";
}



AggressivePlayerStrategy::~AggressivePlayerStrategy() {


}

//Returns a list of territories to attack
list<Territory>* AggressivePlayerStrategy::toAttack(list<Territory>* targetTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;

	std::cout << "Lit of territories to attack by AggressivePlayer: \n";

	for (ptr = targetTerritories->begin(); ptr != targetTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}

	std::cout << std::endl;


	return targetTerritories;
}

//Returns a list of territories to defend
list<Territory>* AggressivePlayerStrategy::toDefend(list<Territory>* myTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;
	std::cout << "List of territories to defend by AggressivePlayer: \n";
	for (ptr = myTerritories->begin(); ptr != myTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}
	std::cout << std::endl;

	return myTerritories;
}

//Creates an object containing this player's list of Order
void AggressivePlayerStrategy::issueOrder(Order o, list<Order>* myOrder) {

	std::cout << "Order issued by AggressivePlayer: \n";
	myOrder->push_back(o);
}


/*************************************BenevolentPlayerStrategy **************************************/

BenevolentPlayerStrategy::BenevolentPlayerStrategy() {
	strategyName = "BenevolentPlayer";
}



BenevolentPlayerStrategy::~BenevolentPlayerStrategy() {

}


//Returns a list of territories to attack
list<Territory>* BenevolentPlayerStrategy::toAttack(list<Territory>* targetTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;

	std::cout << "Lit of territories to attack by BenevolentPlayer: \n";

	for (ptr = targetTerritories->begin(); ptr != targetTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}

	std::cout << std::endl;


	return targetTerritories;
}

//Returns a list of territories to defend
list<Territory>* BenevolentPlayerStrategy::toDefend(list<Territory>* myTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;
	std::cout << "List of territories to defend by BenevolentPlayer: \n";
	for (ptr = myTerritories->begin(); ptr != myTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}
	std::cout << std::endl;

	return myTerritories;
}

//Creates an object containing this player's list of Order
void BenevolentPlayerStrategy::issueOrder(Order o, list<Order>* myOrder) {

	std::cout << "Order issued by BenevolentPlayer: \n";
	myOrder->push_back(o);

}



/*************************************NeutralPlayerStrategy **************************************/

NeutralPlayerStrategy::NeutralPlayerStrategy() {

	strategyName = "NeuralPlayer";

}


NeutralPlayerStrategy::~NeutralPlayerStrategy() {


}

//Returns a list of territories to attack
list<Territory>* NeutralPlayerStrategy::toAttack(list<Territory>* targetTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;

	std::cout << "Lit of territories to attack by NeutralPlayer: \n";

	for (ptr = targetTerritories->begin(); ptr != targetTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}

	std::cout << std::endl;


	return targetTerritories;
}

//Returns a list of territories to defend
list<Territory>* NeutralPlayerStrategy::toDefend(list<Territory>* myTerritories) {

	list<Territory >::iterator ptr;
	int i = 0;
	std::cout << "List of territories to defend by NeutralPlayer: \n";
	for (ptr = myTerritories->begin(); ptr != myTerritories->end(); ++ptr) {
		std::cout << "\n\t" << *ptr << "\n";
	}
	std::cout << std::endl;

	return myTerritories;
}

//Creates an object containing this player's list of Order
void NeutralPlayerStrategy::issueOrder(Order o, list<Order>* myOrder) {

	std::cout << "Order issued by NeutralPlayer: \n";
	myOrder->push_back(o);
}

string NeutralPlayerStrategy::getStrategyName() {
	return strategyName;
}

string HumanPlayerStrategy::getStrategyName() {
	return strategyName;
}

string AggressivePlayerStrategy::getStrategyName() {
	return strategyName;
}

string BenevolentPlayerStrategy::getStrategyName() {
	return strategyName;
}