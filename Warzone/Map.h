using namespace std;
#include <list>
#include <iostream>
using namespace std;
class Territory; // forward declaration
class Continent;

class Node {
public:
	int data;
	Node* newNode(int);
	Node* next;
};

class AdjacencyList {
public:
	Node* head;
};

class Map
{
	AdjacencyList* adjacencyListArray;
	int numTerritories;
public:
	Map* createMap(int);
	void addEgde(Map* map, Territory territory);
	void printMap(Map*);
};

class Continent
{
	string continentName;
	int continentIndex = 0;
	int continentBunos = 0;
public:
	Continent() {};
	Continent(int index, string name) : continentIndex(index), continentName(name) {}
	Continent(int index, string name, int bunos) : continentIndex(index), continentName(name), continentBunos(bunos) {}
};

class Territory {
public:
	int source;
	int destination;
	Continent continent;
	Territory() {
		source = 0;
		destination = 0;
	}
	Territory(int src, int dest) {
		source = src;
		destination = dest;
	}
	Territory(int src, int dest, Continent c) {
		source = src;
		destination = dest;
		continent = c;
	}
	friend class Map;
};

