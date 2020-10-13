//#include "Map.h"
//
//using namespace std;
//
//int main() {
//
//	Map m(3);
//	Continent c1(0, 1, "Continent A", 2);
//	Continent c2(0, 2, "Continent A", 1);
//	Continent c3(1, 2, "Continent C", 3);
//	m.addEdge(c1);
//	m.addEdge(c2);
//	m.addEdge(c3);
//	m.displayAdjacencyList();
//	m.validate();
//
//	cout << endl;
//
//	Map m1(3);
//	m1.addEdge(Territory(0, 1, c1));
//	m1.addEdge(Territory(0, 2, c2));
//	m1.addEdge(Territory(1, 2, c3));
//	m1.displayAdjacencyList();
//	m1.validate();
//
//	cout << endl;
//
//	Map m2(5);
//	m2.addEdge(Territory(0, 1, c1));
//	m2.addEdge(Territory(0, 2, c2));
//	m2.addEdge(Territory(3, 4, c3));
//	m2.displayAdjacencyList();
//	m2.validate();
//
//	cout << endl;
//
//	Map m3(6);
//	m3.addEdge(Territory(0, 4));
//	m3.addEdge(Territory(0, 3));
//	m3.addEdge(Territory(1, 2));
//	m3.addEdge(Territory(1, 4));
//	m3.addEdge(Territory(1, 5));
//	m3.addEdge(Territory(2, 3));
//	m3.addEdge(Territory(2, 5));
//	m3.addEdge(Territory(5, 3));
//	m3.addEdge(Territory(5, 4));
//	m3.displayAdjacencyList();
//	m3.validate();
//	return 0;
//}
///*
//Adjacency List
//0 : 1 2
//1 : 0 2
//2 : 0 1
//Graph is connected!
//One or more territory do(es) NOT belong to a continent!
//Adjacency List
//0 : 1 2
//1 : 0 2
//2 : 0 1
//Graph is connected!
//All territories belong to a continent!
//Adjacency List
//0 : 1 2
//1 : 0
//2 : 0
//3 : 4
//4 : 3
//Graph is NOT connected!
//All territories belong to a continent!
//Adjacency List
//0 : 4 3
//1 : 2 4 5
//2 : 1 3 5
//3 : 0 2 5
//4 : 0 1 5
//5 : 1 2 3 4
//Graph is connected!
//One or more territory do(es) NOT belong to a continent!
//*/