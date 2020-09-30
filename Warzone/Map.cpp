#include "Map.h"

/*
The Map class can be used to represent any map graph configuration.
The Map class includes a validate() method that makes the following checks:
1) the map is a connected graph,
2) continents are connected subgraphs and
3) each country belongs to one and only one continent.
*/

bool Map::isTerritoryBelongToAContinent()
{
	// TODO
	return true;
}

// returns 0 if one territory has no adjacencies, otherwise return 1
bool Map::isTerritoryHasAdjacencies()
{
	// loop through all the territories
	// increment the counter if a territory has adjacencies
	list<Territory>::iterator it;
	int counter = 0;
	for (it = territoryList.begin(); it != territoryList.end(); it++)
	{
		if (it->adjacenciesString != "") {
			counter++;
		}
		if (it->adjacenciesString == "[]") {
			counter--;
		}
	}
	// for a valid map, usually all territories has adjacencies
	// if counter is less than the size of territories that's means one (or more) territor(ies)y does(do) not have adjacencies
	if (counter < territoryList.size())
	{
		return false;
	}
	return true;
}

void Map::validate()
{
	// TODO
	// using territoryList and continentList
	// validate if a territory has borders/adjacencies
	// validate if a territory belongs to a continent
	string isValidMap;
	if (isTerritoryHasAdjacencies() && isTerritoryBelongToAContinent()) {
		isValidMap = "Map is valid";
	}
	else {
		isValidMap = "Map is invalid";
	}
	cout << isValidMap;
}


Map::Map(list<Territory> territories)
{
	territoryList = territories;
}

Map::Map(list<Territory> territories, list<Continent> continents)
{
	territoryList = territories;
	continentList = continents;
}