#include "Territory.h"
#include<sstream>

// convert adjacencies which of type list<int> to easily readable string
void Territory::setListAdjacencies()
{
	stringstream ss;
	string adjacencies;
	list <int> ::iterator it;
	string str;
	for (it = territoryAdjacencies.begin(); it != territoryAdjacencies.end(); ++it) {
		ss << *it << ",";
	}
	ss >> adjacencies;
	Territory::setStringAdjacencies(adjacencies.substr(0, adjacencies.length() - 1));
}

list<int> Territory::getListAdjacencies()
{
	return territoryAdjacencies;
}

string Territory::getTerritoryName()
{
	return territoryName;
}

int Territory::getTerritoryIndex()
{
	return territoryIndex;
}

int Territory::getTerritoryContinentIndex()
{
	return territoryContinent.getContinentIndex();
}

void Territory::setStringAdjacencies(string s)
{
	adjacenciesString = "[" + s + "]";
}

Territory::Territory(int index, string name)
{
	territoryIndex = index;
	territoryName = name;
}

Territory::Territory(int index, string name, Continent continent)
{
	territoryIndex = index;
	territoryName = name;
	territoryContinent = continent;
}

Territory::Territory(int index, string name, Continent continent, list<int> adjacencies)
{
	territoryIndex = index;
	territoryName = name;
	territoryContinent = continent;
	territoryContinentIndex = continent.getContinentIndex();
	territoryAdjacencies = adjacencies;
	Territory::setListAdjacencies();
}

// just like toString() in java
std::ostream& operator<<(std::ostream& strm, const Territory t)
{
	return strm << "Territory(" << t.territoryIndex << ", " << t.territoryName << ", " << t.territoryContinentIndex << ", " << t.adjacenciesString << ")\n";
}

