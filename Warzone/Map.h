#include <list>
#include <iostream>
#include <vector>
using namespace std;
class Territory; // forward declaration
class Continent;

class Map
{
	int numVertices;
	vector<Territory> territoriesVec;
	vector<Continent> continentsVec;
	list<int> *adjList;
	void DFS(int v, bool visitedArr[]);
public:
	Map(int vertices)
	{
		this->numVertices = vertices;
		adjList = new list<int>[vertices];
	}
	~Map() {
		delete [] adjList; 
	}
	void addEdge(Territory t);
	void addEdge(Continent c);
	void displayAdjacencyList();
	bool isConnectedGraph();
	bool isTerritoryBelongToAContinent();
	void validate();
};

class Continent
{
	string continentName;
	int continentBunos = 0;
	int source;
	int destination;
public:
	Continent() {
		source = -1; // if not set
		destination = -1;
	};
	Continent(int src, int dest, string name, int bunos) {
		source = src;
		destination = dest;
		continentName = name;
		continentBunos = bunos;
	}
	int getSource();
	friend class Map;
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

