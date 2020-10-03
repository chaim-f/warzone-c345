#include "Map.h"
#include <sstream>

// check if minimum number of nodes is attain or not
// e.g. if you have 5 nodes, you must have at least 5 edges
// e.g. Territory t1 = Territory(1, "Territory A", c1, { }); returns 0 edges
// e.g. Territory t4 = Territory(4, "Territory D", c2, { 2,3,5 }); returns 3 edges
bool Map::isNumberOfNodesEdgesValid() {
	list<Territory>::iterator it;
	int counter = 0;
	for (it = territoryList.begin(); it != territoryList.end(); it++)
	{
		cout << it->getTerritoryName() << " makes " << it->getListAdjacencies().size() << " edges" << endl;
		if (it->getListAdjacencies().size() < 1) {
			break;
			return false;
		}
	}
	return true;
}

// check if a territory belongs to a continent
bool Map::isTerritoryBelongsToAContinent()
{
	// loop through all the territories
	list<Territory>::iterator it;
	int counter = 0;
	for (it = territoryList.begin(); it != territoryList.end(); it++)
	{
		if (it->getTerritoryContinentIndex() > 0) { // in domination map continent number always start at index 1
			counter++;
		}
	}
	// all territories/countries of a valid map belong to a continent
	return counter < territoryList.size() ? false : true;
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
	return counter < territoryList.size() ? false : true;
}

void Map::validate()
{
	string isValidMap;
	if (isTerritoryHasAdjacencies() && isTerritoryBelongsToAContinent() && isNumberOfNodesEdgesValid()) {
		isValidMap = "*** Map is valid! ***";
	}
	else {
		isValidMap = "*** Map is invalid! ***";
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