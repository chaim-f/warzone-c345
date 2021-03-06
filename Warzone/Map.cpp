#include "Map.h"
#include <vector>
#include <list>

using namespace std;
bool visited[100000];

void Map::DFS(int root, bool visitedArr[])
{
	visitedArr[root] = true;
	list<int>::iterator it;
	for (it = adjList[root].begin(); it != adjList[root].end(); ++it) {
		if (!visitedArr[*it]) {
			DFS(*it, visitedArr);
		}
	}
}

Map::~Map() {
	delete[] adjList;
}

Map::Map()
{
	numVertices = 0;
	isDirectedGraph = false;
	adjList = NULL;
}

Map::Map(const Map& m)
{
	numVertices = 0;
	isDirectedGraph = false;
	adjList = NULL;
}

Map& Map::operator=(const Map& t)
{
	numVertices = 0;
	isDirectedGraph = false;
	adjList = NULL;
	return *this;
}

void Map::displayAdjacencyList()
{
	cout << endl << "Adjacency List" << endl;
	int j = isTerritoryStartAtIndex0();
	for (int v = j; v < numVertices; v++)
	{
		cout << v << " : ";
		list<int>::iterator i;
		for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
}

void Map::addEdge(Territory* t)
{
	thisTerritory = t;
	adjList[t->source].push_back(t->destination);
	if (!isDirectedGraph) {
		adjList[t->destination].push_back(t->source);
	}
	territoriesVec.push_back(t);
}

void Map::addEdge(Continent* c)
{
	adjList[c->source].push_back(c->destination);
	adjList[c->destination].push_back(c->source);
	continentsVec.push_back(c);
}

void Map::createMap(int vertices, bool isDirected)
{
	this->isDirectedGraph = isDirected;
	this->numVertices = vertices;
	adjList = new list<int>[vertices];
}

// to accomodate if Territory (int src, int dest) src or dest does not start at 0
bool Map::isTerritoryStartAtIndex0() {
	bool isIndexStartAt1 = true;
	for (size_t i = 0; i < territoriesVec.size(); ++i) {
		if (territoriesVec[i]->source == 0 || territoriesVec[i]->destination == 0) {
			isIndexStartAt1 = false;
			break;
		}
	}
	return isIndexStartAt1 ? 1 : 0;
}

bool Map::isConnectedGraph()
{
	int j = isTerritoryStartAtIndex0();
	for (int i = j; i < numVertices; i++) {
		visited[i] = false;
	}
	DFS(j, visited);
	for (int i = j; i < numVertices; i++) {
		if (visited[i] == false) {
			return false;
		}
	}
	Map* map = getReverseGraph();
	for (int i = j; i < numVertices; i++) {
		visited[i] = false;
	}
	map->DFS(j, visited);
	for (int i = j; i < numVertices; i++) {
		if (visited[i] == false) {
			return false;
		}
	}
	return true;
}

bool Map::isTerritoryBelongToAContinent()
{
	bool cond = true;
	if (territoriesVec.size() > 0) {
		for (size_t i = 0; i < territoriesVec.size(); ++i) {
			if (territoriesVec[i]->continent.getSource() == -1) {
				cond = false;
				break;
			}
		}
	}
	else {
		cond = false;
	}
	return cond;
}

bool Map::getIsValidMapFile()
{
	return isValidMapFile;
}

void Map::validate()
{
	if (isConnectedGraph() && isTerritoryBelongToAContinent()) {
		cout << "Graph is connected!" << endl;
		// cout << "All territories belong to a continent!" << endl;
		this->setIsValidMapFile(true);
	}
	else {
		if (!isConnectedGraph()) {
			cout << "Graph is NOT connected!" << endl;
			this->setIsValidMapFile(false);
		}
		else {
			cout << "Graph is connected!" << endl;
		}
		if (!isTerritoryBelongToAContinent()) {
			// cout << "One or more territory do(es) NOT belong to a continent!" << endl;
			this->setIsValidMapFile(false);
		}
		else {
			// cout << "All territories belong to a continent!" << endl;
		}
	}
}

Map* Map::getReverseGraph()
{
	Map* m;
	m = new Map();
	m->createMap(numVertices, isDirectedGraph);
	for (int v = 0; v < numVertices; v++)
	{
		std::list<int>::iterator i;
		for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
		{
			m->adjList[*i].push_back(v);
		}
	}
	return m;
}

void Map::setIsValidMapFile(bool isValid)
{
	this->isValidMapFile = isValid;
}

vector<Territory*> Map::getTerritoriesVec()
{
	return territoriesVec;
}

int getSource(Continent c)
{
	return c.source;
}

int getDestination(Continent d)
{
	return d.destination;
}

int Continent::getSource()
{
	return source;
}

string Continent::getContinentName()
{
	return this->continentName;
}


/**************  Continent definition  **************************/
Continent::Continent() {
	source = -1; // if not set
	destination = -1;
};

Continent::Continent(int src, int dest, string name, int bunos) {
	source = src;
	destination = dest;
	continentName = name;
	continentBunos = bunos;
}

Continent::Continent(int src, string name, int bunos)
{
	source = src;
	continentName = name;
	continentBunos = bunos;
}

void Continent::displayContinents()
{
	cout << "Continent(" << source << ", " << continentName << ", " << continentBunos << ")" << endl;
}

ostream& operator<<(ostream& strm, const Continent c)
{
	return strm << "Continent(" << c.source << ", " << c.continentName << ", " << c.continentBunos << ")";
}


/**************  Territory definition  **************************/
Territory::Territory() {
	source = 0;
	destination = 0;
}

Territory::Territory(int src, int dest)
{
	source = src;
	destination = dest;
}

Territory::Territory(int src, int dest, Continent c)
{
	source = src;
	destination = dest;
	continent = c;
}

Territory::Territory(int src, string name, Continent c)
{
	source = src;
	territoryName = name;
	continent = c;
}

Territory::Territory(int src, int dest, string name, Continent c)
{
	source = src;
	destination = dest;
	territoryName = name;
	continent = c;
}

void Territory::displayTerritories()
{
	if (destination > 0) {
		cout << "Territory(" << source << ", " << destination << ", " << territoryName << ", " << continent << ")" << endl;
	} else {
		cout << "Territory(" << source << ", " << territoryName << ", " << continent << ")" << endl;
	}
}

void Territory::setTerritoryArmies(int v)
{
	this->territoryArmies = v;
}

Continent Territory::getTerritoryContinent() {
	return continent;
}

string Territory::getTerritoryName() {
	return territoryName;
}

int Territory::getTerritoryIndex()
{
	return source;
}

int Territory::getBorder()
{
	return destination;
}

int Territory::getTerritoryArmies()
{
	return territoryArmies;
}

ostream& operator<<(ostream& strm, const Territory t)
{
	if (t.destination > 0 || t.destination >= 1) {
		return strm << "Territory(" << t.source << ", " << t.destination << ", " << t.territoryName << ", " << t.continent << ")";
	}
	else {
		return strm << "Territory(" << t.source << ", " << t.territoryName << ", " << t.continent << ")";
	}
}