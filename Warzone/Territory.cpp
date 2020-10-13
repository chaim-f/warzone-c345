#include "Territory.h"

Territory::Territory(int src, int dest)
{
	source = src;
	destination = dest;
}

Territory::Territory(int src, int dest, Continent c)
{
	source = src;
	destination = dest;
	continent = c;
}

Territory::Territory(int src, string name, Continent c)
{
	source = src;
	territoryName = name;
	continent = c;
}

Territory::Territory(int src, int dest, string name, Continent c)
{
	source = src;
	destination = dest;
	territoryName = name;
	continent = c;
}

Continent Territory::getTerritoryContinent() {
	return continent;
}

string Territory::getTerritoryName() {
	return territoryName;
}

ostream& operator<<(ostream& strm, const Territory t)
{
	if (t.destination > 0 || t.destination >= 1) {
		return strm << "Territory(" << t.source << ", " << t.destination << ", " << t.territoryName << ", " << t.continent << ")";
	}
	else {
		return strm << "Territory(" << t.source << ", " << t.territoryName << ", " << t.continent << ")";
	}
}