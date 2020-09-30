using namespace std;
#include <list>
#include "Territory.h"

class Map
{
	list <Continent> continentList;
	list <Territory> territoryList;
	bool isTerritoryBelongToAContinent();
	bool isTerritoryHasAdjacencies();
public:
	void validate();
	Map(list <Territory> territories);
	Map(list <Territory> territories, list <Continent> continents);
};
