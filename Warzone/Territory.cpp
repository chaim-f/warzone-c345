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
	return strm << "Territory(" << t.source << ", " << t.continent << ")";
}