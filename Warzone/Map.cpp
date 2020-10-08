#include "Map.h"

Map* Map::createMap(int t)
{
	Map* map = new Map;
	map->numTerritories = t;
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
}

void Map::printMap(Map* m)
{
	for (int i = 0; i < m->numTerritories; i++) {
		Node* root = adjacencyListArray[i].head;
		cout << "Adjacency list of vertex " << i << ": (";
		
		while (root != NULL) {
			cout << root->data << ",";
			root = root->next;
		}
		cout << ")" << endl;

	}
}


Node* Node::newNode(int data)
{
	Node* nodePtr = new Node;
	nodePtr->data = data;
	nodePtr->next = NULL;
	return nodePtr;
}
