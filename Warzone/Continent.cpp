#include "Continent.h"

Continent::Continent()
{
}

Continent::Continent(int index, string name)
{
	continentIndex = index;
	continentName = name;
	continentBunos = 0;
}

Continent::Continent(int index, string name, int bunos)
{
	continentIndex = index;
	continentName = name;
	continentBunos = bunos;
}

int Continent::getContinentIndex()
{
	return continentIndex;
}

std::ostream& operator<<(std::ostream& strm, const Continent c)
{
	return strm << "Continent(" << c.continentIndex << ", " << c.continentName << ", " << c.continentBunos << ")\n";
}
