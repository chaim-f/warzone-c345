#include "Map.h"
using namespace std;

int main() {
	int territories = 5;
	Map* map{};
	map = map->createMap(territories);
	map->addEgde(map, Territory(0, 1));
	map->addEgde(map, Territory(0, 4));
	map->addEgde(map, Territory(1, 2));
	map->addEgde(map, Territory(1, 3));
	map->addEgde(map, Territory(1, 4));
	map->addEgde(map, Territory(2, 3));
	map->addEgde(map, Territory(3, 4));
	map->printMap(map);
	/*
	Adjacency list of vertex 0: (4,1,)
	Adjacency list of vertex 1: (4,3,2,0,)
	Adjacency list of vertex 2: (3,1,)
	Adjacency list of vertex 3: (4,2,1,)
	Adjacency list of vertex 4: (3,1,0,)
	*/
	return 0;
}