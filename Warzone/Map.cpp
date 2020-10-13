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

void Map::displayAdjacencyList()
{
	cout << "Adjacency List" << endl;
	for (int v = 0; v < numVertices; v++)
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

void Map::addEdge(Territory t)
{
	adjList[t.source].push_back(t.destination);
	adjList[t.destination].push_back(t.source);
	territoriesVec.push_back(t);
}

void Map::addEdge(Continent c)
{
	adjList[c.source].push_back(c.destination);
	adjList[c.destination].push_back(c.source);
	continentsVec.push_back(c);
}

bool Map::isConnectedGraph()
{
	// if vertex does not start at 0
	bool isIndexStartAt1 = true;
	for (size_t i = 0; i < territoriesVec.size(); ++i) {
		if (territoriesVec[i].source == 0 || territoriesVec[i].destination == 0) {
			isIndexStartAt1 = false;
			break;
		}
	}
	for (int i = isIndexStartAt1 ? 1 : 0; i < numVertices; i++) {
		visited[i] = false;
	}
	DFS(isIndexStartAt1 ? 1 : 0, visited);
	int count = 0;
	for (int i = 0; i < numVertices; i++) {
		if (visited[i] == true) {
			count++;
		}
	}
	return numVertices == count;
}

bool Map::isTerritoryBelongToAContinent()
{
	bool cond = true;
	if (territoriesVec.size() > 0) {
		for (size_t i = 0; i < territoriesVec.size(); ++i) {
			if (territoriesVec[i].continent.getSource() == -1) {
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

void Map::validate()
{
	if (isConnectedGraph() && isTerritoryBelongToAContinent()) {
		cout << "Graph is connected!" << endl;
		cout << "All territories belong to a continent!" << endl;
	}
	else {
		if (!isConnectedGraph()) {
			cout << "Graph is NOT connected!" << endl;
		}
		else {
			cout << "Graph is connected!" << endl;
		}
		if (!isTerritoryBelongToAContinent()) {
			cout << "One or more territory do(es) NOT belong to a continent!" << endl;
		}
		else {
			cout << "All territories belong to a continent!" << endl;
		}
	}
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