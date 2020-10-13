#include <list>
#include "Territory.h"
#include "Map.h"
#include "Maploader.h"
using namespace std;

int main()
{

	list<Continent> continents;
	Continent c1 = Continent(1, "Continent A", 2);
	Continent c2 = Continent(2, "Continent B", 4);
	Continent c3 = Continent(3, "Continent C", 3);
	continents = { c1, c2, c3 };

	/*
	Nodes: 1, 2, 3, 4, 5
	###################################
	###################################
	######(1)--------------(2)  ###############
	###### |           //   |  \\  ##########
	###### |       //       |    \\    #########
	###### |    //          |    //(3)  ########
	###### | //             |  //     ###########
	######(5)--------------(4)    #############
	###################################
	###################################
	Edges
	node 1: (1, 2), (1, 5)
	node 2: (2, 1), (2, 3), (2, 4) (2, 5)
	node 3: (3, 2), (3, 4)
	node 4: (4, 2), (4, 3), (4, 5)
	node 5: (5, 1), (5, 2), (5, 4)
	*/
	// it can be represented as
	list<Territory> tValid;
	Territory t1 = Territory(1, "Territory A", c1, { 2,5 });
	Territory t2 = Territory(2, "Territory B", c1, { 1,3,4,5 });
	Territory t3 = Territory(3, "Territory C", c3, { 2,4 });
	Territory t4 = Territory(4, "Territory D", c2, { 2,3,5 });
	Territory t5 = Territory(5, "Territory E", c2, { 1,2,4 });
	tValid = { t1, t2, t3, t4, t5 };

	cout << "printing the territories..." << endl;
	list<Territory>::iterator it;
	for (it = tValid.begin(); it != tValid.end(); it++)
	{
		cout << *it;
	}
	cout << "number of territories: " << tValid.size() << "\n\n";

	cout << "validating the territories...\n";
	Map m2 = Map(tValid, continents);
	m2.validate();

	// Part 2 - MapLoader example
	string canadaMapFile = "maps/canada.map";
	MapLoader canadaMap = MapLoader();
	canadaMap.setFileName(canadaMapFile);
	Map m3 = Map(canadaMap.getTerritories(), canadaMap.getContinents());

}