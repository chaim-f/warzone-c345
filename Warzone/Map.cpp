#include "Map.h"

Map* Map::createMap(int t)
{
	Map* map = new Map;
	map->numVertices = t;
	map->adjacencyListArray = new AdjacencyList[t];
	for (int i = 0; i < t; i++)
	{
		map->adjacencyListArray[i].head = NULL;
	}
	return map;
}

void Map::addEgde(Map* map, Territory t)
{
	int source = t.source;
	int dest = t.destination;
	Node* node{};
	node = node->newNode(dest);;
	node->next = map->adjacencyListArray[source].head;
	map->adjacencyListArray[source].head = node;

	node = node->newNode(source);
	node->next = map->adjacencyListArray[dest].head;
	map->adjacencyListArray[dest].head = node;

	territoriesVec.push_back(t);
}

void Map::addEgde(Map* map, Continent c)
{
	int source = getSource(c);
	int dest = getDestination(c);
	Node* node{};
	node = node->newNode(dest);;
	node->next = map->adjacencyListArray[source].head;
	map->adjacencyListArray[source].head = node;

	node = node->newNode(source);
	node->next = map->adjacencyListArray[dest].head;
	map->adjacencyListArray[dest].head = node;

	// storing continent
	continentsVec.push_back(c);
}

void Map::printMap(Map* m, string type)
{
	for (int i = 0; i < m->numVertices; i++) {
		Node* root = adjacencyListArray[i].head;
		cout << "Adjacency list of " << type << i << ": (";
		
		while (root != NULL) {
			cout << root->data << ",";
			root = root->next;
		}
		cout << ")" << endl;
	}
	cout << endl;
}

Node* Node::newNode(int data)
{
	Node* nodePtr = new Node;
	nodePtr->data = data;
	nodePtr->next = NULL;
	return nodePtr;
}

vector<Continent> getContinents(Map* m)
{
	return m->continentsVec;
}

void printContinents(Map* map)
{
	for (size_t i = 0; i < map->continentsVec.size(); ++i) {
		cout << map->continentsVec[i] << endl;
	}
	cout << endl;
}

void printTerritories(Map* map)
{
	for (size_t i = 0; i < map->territoriesVec.size(); ++i) {
		cout << map->territoriesVec[i] << endl;
	}
	cout << endl;
}

int getSource(Continent c)
{
	return c.source;
}

int getDestination(Continent d)
{
	return d.destination;
}
