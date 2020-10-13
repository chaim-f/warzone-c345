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

ostream& operator<<(ostream& strm, const Territory t)
{
	return strm << "Territory(" << t.source << ", " << t.continent << ")";
}