#include "Map.h"
#include <vector>
#include<cstdlib>
#include <time.h>

using namespace std;

int main() {
	int numContinents = 3;

	Map* map2{};
	map2 = map2->createMap(numContinents);
	map2->addEgde(map2, Continent(0, 1, "Continent A", 2));
	map2->addEgde(map2, Continent(0, 2, "Continent B", 1));
	map2->addEgde(map2, Continent(1, 2, "Continent C", 3));
	printContinents(map2);
	map2->printMap(map2, "Continent ");

	int numTerritories = 5;
	Map* map{};
	map = map->createMap(numTerritories);
	srand(time(NULL));
	vector<Territory> territories = {
		Territory(0, 1, getContinents(map2)[rand() % numContinents]),
		Territory(0, 4, getContinents(map2)[rand() % numContinents]),
		Territory(1, 2, getContinents(map2)[rand() % numContinents]),
		Territory(1, 3, getContinents(map2)[rand() % numContinents]),
		Territory(1, 4, getContinents(map2)[rand() % numContinents]),
		Territory(2, 3, getContinents(map2)[rand() % numContinents]),
		Territory(3, 4, getContinents(map2)[rand() % numContinents])
	};
	for (size_t i = 0; i < territories.size(); ++i) {
		map->addEgde(map, territories[i]);
	}

	printTerritories(map);
	map->printMap(map, "Territory ");
	return 0;
}
/*
*******Sample output******

Continent(0, 1, Continent A, 2)
Continent(0, 2, Continent B, 1)
Continent(1, 2, Continent C, 3)

Adjacency list of Continent 0: (2,1,)
Adjacency list of Continent 1: (2,0,)
Adjacency list of Continent 2: (1,0,)

Territory(0, 1, Continent(1, 2, Continent C, 3))
Territory(0, 4, Continent(1, 2, Continent C, 3))
Territory(1, 2, Continent(0, 2, Continent B, 1))
Territory(1, 3, Continent(0, 1, Continent A, 2))
Territory(1, 4, Continent(1, 2, Continent C, 3))
Territory(2, 3, Continent(1, 2, Continent C, 3))
Territory(3, 4, Continent(1, 2, Continent C, 3))

Adjacency list of Territory 0: (4,1,)
Adjacency list of Territory 1: (4,3,2,0,)
Adjacency list of Territory 2: (3,1,)
Adjacency list of Territory 3: (4,2,1,)
Adjacency list of Territory 4: (3,1,0,)
*/