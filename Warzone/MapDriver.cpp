//#include "Map.h"
//
//using namespace std;
//
//int main() {
//
//	Continent c1(0, 1, "Continent A", 2);
//	Continent c2(0, 2, "Continent A", 1);
//	Continent c3(1, 2, "Continent C", 3);
//
//	cout << endl;
//
//	// valid case: connected map & all territories belong to a continent
//	Map* m1;
//	m1 = new Map();
//	m1->createMap(3, false);
//	Territory* t1 = new Territory(0, 1, c1);
//	Territory* t2 = new Territory(0, 2, c2);
//	Territory* t3 = new Territory(1, 2, c3);
//	m1->addEdge(t1);
//	m1->addEdge(t2);
//	m1->addEdge(t3);
//	m1->displayAdjacencyList();
//	m1->validate();
//
//	cout << endl;
//
//	// invalid case: not connected
//	Map* m2;
//	m2 = new Map();
//	m2->createMap(5, false);
//	Territory* a1 = new Territory(0, 1, c1);
//	Territory* a2 = new Territory(0, 2, c2);
//	Territory* a3 = new Territory(3, 4, c3);
//	m2->addEdge(a1);
//	m2->addEdge(a2);
//	m2->addEdge(a3);
//	m2->displayAdjacencyList();
//	m2->validate();
//
//	cout << endl;
//
//	// invalid case: not all territories belong to a continent
//	Map* m3;
//	m3 = new Map();
//	m3->createMap(6, false);
//	Territory* b1 = new Territory(0, 4);
//	Territory* b2 = new Territory(0, 3);
//	Territory* b3 = new Territory(1, 2);
//	Territory* b4 = new Territory(1, 4);
//	Territory* b5 = new Territory(1, 5);
//	Territory* b6 = new Territory(2, 3);
//	Territory* b7 = new Territory(5, 3);
//	Territory* b8 = new Territory(5, 4);
//	m3->addEdge(b1);
//	m3->addEdge(b2);
//	m3->addEdge(b3);
//	m3->addEdge(b4);
//	m3->addEdge(b5);
//	m3->addEdge(b6);
//	m3->addEdge(b7);
//	m3->addEdge(b8);
//	m3->displayAdjacencyList();
//	m3->validate();
//
//	return 0;
//}
