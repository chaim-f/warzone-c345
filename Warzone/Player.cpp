#include "Player.h"
#include <string>
#include <vector> 
#include "map.h"
#include <iostream>
#include <list>
using std::string;

//player functions
Player::Player()
{
}

Player::~Player()
{
}

int Player::getPID()
{
	return *PID;
}

void Player::setPID(int id)
{
	*PID = id;
}
string Player::getPName()
{
	return *pName;
}

void Player::setPName(string name)
{
	*pName = name;
}

void Player::addPTerritory(Territory* tid)
{
	playerTerritoryVector.push_back(tid);
}

void Player::removePTerritory(Territory* tid)
{
	//to do implement this (maybe change to list for this).
}

void Player::toDefend()
{
	std::cout << "";//to do fix this to print my territories  
}

void Player::toAttack()
{
	std::cout << "";//to do fix this to print territories adjacent to my terretories that are not mine
}

void Player::issueOrder()
{
}