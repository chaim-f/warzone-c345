#include "Continent.h"

Continent::Continent(int src, int dest, string name, int bunos) {
	source = src;
	destination = dest;
	continentName = name;
	continentBunos = bunos;
}

Continent::Continent(int src, string name, int bunos)
{
	source = src;
	continentName = name;
	continentBunos = bunos;
}

ostream& operator<<(ostream& strm, const Continent c)
{
	return strm << "Continent(" << c.source << ", " << c.continentName << ", " << c.continentBunos << ")";
}