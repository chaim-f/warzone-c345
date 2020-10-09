#include <list>
#include <iostream>
#include <vector>
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
	int numVertices;
	vector<Continent> continentsVec;
	vector<Territory> territoriesVec;
public:
	Map* createMap(int);
	void addEgde(Map* map, Territory t);
	void addEgde(Map* map, Continent c);
	void printMap(Map* m, string type);
	friend vector<Continent> getContinents(Map* m);
	friend void printContinents(Map* map);
	friend void printTerritories(Map* map);
};

class Continent
{
	string continentName;
	int continentBunos = 0;
	int source;
	int destination;
public:
	Continent() {
		source = 0;
		destination = 0;
	};
	Continent(int src, int dest, string name, int bunos) {
		source = src;
		destination = dest;
		continentName = name;
		continentBunos = bunos;
	}
	friend int getSource(Continent c);
	friend int getDestination(Continent d);
	friend ostream& operator<<(ostream& strm, const Continent c) {
		return strm << "Continent(" << c.source << ", " << c.destination << ", " << c.continentName << ", " << c.continentBunos << ")";
	}
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
	friend ostream& operator<<(ostream& strm, const Territory t) {
		return strm << "Territory(" << t.source << ", " << t.destination << ", " << t.continent << ")";
	}
};

