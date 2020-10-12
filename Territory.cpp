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

ostream& operator<<(ostream& strm, const Territory t)
{
	return strm << "Territory(" << t.source << ", " << t.destination << ", " << t.continent << ")";
}
