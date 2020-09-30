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
