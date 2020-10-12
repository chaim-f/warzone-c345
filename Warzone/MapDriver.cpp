#include "Map.h"
#include <vector>
#include<cstdlib>
#include <time.h>

using namespace std;

int main() {
	Map m1(3);
	m1.addEdge(Territory(0, 1, Continent(0, 1, "Continent A", 2)));
	m1.addEdge(Territory(0, 2, Continent(0, 2, "Continent B", 1)));
	m1.addEdge(Territory(1, 2, Continent(1, 2, "Continent C", 3)));
	m1.displayAdjacencyList();
	m1.validate();

	cout << endl;

	Map m2(5);
	m2.addEdge(Territory(0, 1, Continent(0, 1, "Continent A", 2)));
	m2.addEdge(Territory(0, 2, Continent(0, 1, "Continent A", 2)));
	m2.addEdge(Territory(3, 4, Continent(0, 1, "Continent A", 2)));
	m2.displayAdjacencyList();
	m2.validate();

	cout << endl;

	Map m3(6);
	m3.addEdge(Territory(0, 4));
	m3.addEdge(Territory(0, 3));
	m3.addEdge(Territory(1, 2));
	m3.addEdge(Territory(1, 4));
	m3.addEdge(Territory(1, 5));
	m3.addEdge(Territory(2, 3));
	m3.addEdge(Territory(2, 5));
	m3.addEdge(Territory(5, 3));
	m3.addEdge(Territory(5, 4));
	m3.displayAdjacencyList();
	m3.validate();
	return 0;
}

/*
Adjacency List
0 : 1 2
1 : 0 2
2 : 0 1
Map is VALID!

Adjacency List
0 : 1 2
1 : 0
2 : 0
3 : 4
4 : 3
Map is INVALID!
Graph is not connected!
All territories belong to a continent!

Adjacency List
0 : 4 3
1 : 2 4 5
2 : 1 3 5
3 : 0 2 5
4 : 0 1 5
5 : 1 2 3 4
Map is INVALID!
Graph is connected!
One or more territory do(es) not belong to a continent!
*/