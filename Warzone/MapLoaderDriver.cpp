#include <iostream>
#include <fstream>
#include <string>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

int main() {

	string canadaMapFile = "maps/canada.map";
	MapLoader canadaMap = MapLoader();
	canadaMap.setFileName(canadaMapFile);
	canadaMap.storeContinents();
	canadaMap.storeTerritories();
	canadaMap.storeTerritoriesWithBorders();
	Map canadaCreatedMap = Map(canadaMap.getTerritories().size()+1);

	for (size_t i = 0; i < canadaMap.getTerritoriesWithBorders().size(); i++) {
		canadaCreatedMap.addEdge(canadaMap.getTerritoriesWithBorders()[i], false);
	}

	canadaCreatedMap.displayAdjacencyList();
	canadaCreatedMap.validate();
}

/*
******* Sample output *******
/*
extracting continents from maps/canada.map map...START!
Continent(1, Atlantic_Provinces, 3)
Continent(2, Ontario_and_Quebec, 4)
Continent(3, Western_Provinces-South, 3)
Continent(4, Western_Provinces-North, 2)
Continent(5, Nunavut, 3)
Continent(6, Northwestern_Territories, 2)
extracting continents from maps/canada.map map... DONE!
extracting countries/territories from maps/canada.map map...START!
Territory(1, -858993460, New_Brunswick, Continent(1, Atlantic_Provinces, 3))
Territory(2, -858993460, Prince_Edward_Island, Continent(1, Atlantic_Provinces, 3))
Territory(3, -858993460, Nova_Scotia, Continent(1, Atlantic_Provinces, 3))
Territory(4, -858993460, N&L-Newfoundland, Continent(1, Atlantic_Provinces, 3))
Territory(5, -858993460, N&L-Labrador, Continent(1, Atlantic_Provinces, 3))
Territory(6, -858993460, Quebec-North, Continent(2, Ontario_and_Quebec, 4))
Territory(7, -858993460, Quebec-Central, Continent(2, Ontario_and_Quebec, 4))
Territory(8, -858993460, Quebec-South, Continent(2, Ontario_and_Quebec, 4))
Territory(9, -858993460, Ontario-South, Continent(2, Ontario_and_Quebec, 4))
Territory(10, -858993460, Ontario-West, Continent(2, Ontario_and_Quebec, 4))
Territory(11, -858993460, Ontario-North, Continent(2, Ontario_and_Quebec, 4))
Territory(12, -858993460, Manitoba-South, Continent(3, Western_Provinces-South, 3))
Territory(13, -858993460, Saskatchewan-South, Continent(3, Western_Provinces-South, 3))
Territory(14, -858993460, Alberta-South, Continent(3, Western_Provinces-South, 3))
Territory(15, -858993460, British_Columbia-South, Continent(3, Western_Provinces-South, 3))
Territory(16, -858993460, BC-Vancouver_Island, Continent(3, Western_Provinces-South, 3))
Territory(17, -858993460, British_Columbia-North, Continent(4, Western_Provinces-North, 2))
Territory(18, -858993460, Alberta-North, Continent(4, Western_Provinces-North, 2))
Territory(19, -858993460, Saskatchewan-North, Continent(4, Western_Provinces-North, 2))
Territory(20, -858993460, Manitoba-North, Continent(4, Western_Provinces-North, 2))
Territory(21, -858993460, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(22, -858993460, NU-Southern_Islands, Continent(5, Nunavut, 3))
Territory(23, -858993460, NU-Baffin_Island, Continent(5, Nunavut, 3))
Territory(24, -858993460, NU-Victoria_Island-East, Continent(5, Nunavut, 3))
Territory(25, -858993460, NU-Northern_Islands, Continent(5, Nunavut, 3))
Territory(26, -858993460, NU-Ellesmere_Island, Continent(5, Nunavut, 3))
Territory(27, -858993460, NT-Northern_Islands, Continent(6, Northwestern_Territories, 2))
Territory(28, -858993460, NT-Banks_Island, Continent(6, Northwestern_Territories, 2))
Territory(29, -858993460, NT-Victoria_Island-West, Continent(6, Northwestern_Territories, 2))
Territory(30, -858993460, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(31, -858993460, Yukon_Territory, Continent(6, Northwestern_Territories, 2))
extracting countries/territories from maps/canada.map map... DONE!
extracting countries/territories with borders from maps/canada.map map...START!
Territory(1, 8, New_Brunswick, Continent(1, Atlantic_Provinces, 3))
Territory(1, 2, New_Brunswick, Continent(1, Atlantic_Provinces, 3))
Territory(1, 3, New_Brunswick, Continent(1, Atlantic_Provinces, 3))
Territory(2, 1, Prince_Edward_Island, Continent(1, Atlantic_Provinces, 3))
Territory(2, 3, Prince_Edward_Island, Continent(1, Atlantic_Provinces, 3))
Territory(3, 1, Nova_Scotia, Continent(1, Atlantic_Provinces, 3))
Territory(3, 2, Nova_Scotia, Continent(1, Atlantic_Provinces, 3))
Territory(3, 4, Nova_Scotia, Continent(1, Atlantic_Provinces, 3))
Territory(4, 3, N&L-Newfoundland, Continent(1, Atlantic_Provinces, 3))
Territory(4, 5, N&L-Newfoundland, Continent(1, Atlantic_Provinces, 3))
Territory(4, 7, N&L-Newfoundland, Continent(1, Atlantic_Provinces, 3))
Territory(5, 4, N&L-Labrador, Continent(1, Atlantic_Provinces, 3))
Territory(5, 7, N&L-Labrador, Continent(1, Atlantic_Provinces, 3))
Territory(5, 6, N&L-Labrador, Continent(1, Atlantic_Provinces, 3))
Territory(6, 5, Quebec-North, Continent(2, Ontario_and_Quebec, 4))
Territory(6, 7, Quebec-North, Continent(2, Ontario_and_Quebec, 4))
Territory(6, 22, Quebec-North, Continent(2, Ontario_and_Quebec, 4))
Territory(6, 23, Quebec-North, Continent(2, Ontario_and_Quebec, 4))
Territory(7, 4, Quebec-Central, Continent(2, Ontario_and_Quebec, 4))
Territory(7, 5, Quebec-Central, Continent(2, Ontario_and_Quebec, 4))
Territory(7, 6, Quebec-Central, Continent(2, Ontario_and_Quebec, 4))
Territory(7, 8, Quebec-Central, Continent(2, Ontario_and_Quebec, 4))
Territory(7, 11, Quebec-Central, Continent(2, Ontario_and_Quebec, 4))
Territory(8, 1, Quebec-South, Continent(2, Ontario_and_Quebec, 4))
Territory(8, 7, Quebec-South, Continent(2, Ontario_and_Quebec, 4))
Territory(8, 9, Quebec-South, Continent(2, Ontario_and_Quebec, 4))
Territory(9, 8, Ontario-South, Continent(2, Ontario_and_Quebec, 4))
Territory(9, 11, Ontario-South, Continent(2, Ontario_and_Quebec, 4))
Territory(9, 10, Ontario-South, Continent(2, Ontario_and_Quebec, 4))
Territory(10, 9, Ontario-West, Continent(2, Ontario_and_Quebec, 4))
Territory(10, 11, Ontario-West, Continent(2, Ontario_and_Quebec, 4))
Territory(10, 12, Ontario-West, Continent(2, Ontario_and_Quebec, 4))
Territory(11, 7, Ontario-North, Continent(2, Ontario_and_Quebec, 4))
Territory(11, 9, Ontario-North, Continent(2, Ontario_and_Quebec, 4))
Territory(11, 10, Ontario-North, Continent(2, Ontario_and_Quebec, 4))
Territory(11, 20, Ontario-North, Continent(2, Ontario_and_Quebec, 4))
Territory(11, 22, Ontario-North, Continent(2, Ontario_and_Quebec, 4))
Territory(12, 10, Manitoba-South, Continent(3, Western_Provinces-South, 3))
Territory(12, 13, Manitoba-South, Continent(3, Western_Provinces-South, 3))
Territory(12, 20, Manitoba-South, Continent(3, Western_Provinces-South, 3))
Territory(13, 12, Saskatchewan-South, Continent(3, Western_Provinces-South, 3))
Territory(13, 19, Saskatchewan-South, Continent(3, Western_Provinces-South, 3))
Territory(13, 14, Saskatchewan-South, Continent(3, Western_Provinces-South, 3))
Territory(14, 13, Alberta-South, Continent(3, Western_Provinces-South, 3))
Territory(14, 18, Alberta-South, Continent(3, Western_Provinces-South, 3))
Territory(14, 15, Alberta-South, Continent(3, Western_Provinces-South, 3))
Territory(15, 14, British_Columbia-South, Continent(3, Western_Provinces-South, 3))
Territory(15, 16, British_Columbia-South, Continent(3, Western_Provinces-South, 3))
Territory(15, 17, British_Columbia-South, Continent(3, Western_Provinces-South, 3))
Territory(16, 15, BC-Vancouver_Island, Continent(3, Western_Provinces-South, 3))
Territory(17, 15, British_Columbia-North, Continent(4, Western_Provinces-North, 2))
Territory(17, 31, British_Columbia-North, Continent(4, Western_Provinces-North, 2))
Territory(17, 30, British_Columbia-North, Continent(4, Western_Provinces-North, 2))
Territory(17, 18, British_Columbia-North, Continent(4, Western_Provinces-North, 2))
Territory(18, 14, Alberta-North, Continent(4, Western_Provinces-North, 2))
Territory(18, 17, Alberta-North, Continent(4, Western_Provinces-North, 2))
Territory(18, 19, Alberta-North, Continent(4, Western_Provinces-North, 2))
Territory(18, 30, Alberta-North, Continent(4, Western_Provinces-North, 2))
Territory(19, 13, Saskatchewan-North, Continent(4, Western_Provinces-North, 2))
Territory(19, 18, Saskatchewan-North, Continent(4, Western_Provinces-North, 2))
Territory(19, 20, Saskatchewan-North, Continent(4, Western_Provinces-North, 2))
Territory(19, 30, Saskatchewan-North, Continent(4, Western_Provinces-North, 2))
Territory(20, 11, Manitoba-North, Continent(4, Western_Provinces-North, 2))
Territory(20, 12, Manitoba-North, Continent(4, Western_Provinces-North, 2))
Territory(20, 19, Manitoba-North, Continent(4, Western_Provinces-North, 2))
Territory(20, 21, Manitoba-North, Continent(4, Western_Provinces-North, 2))
Territory(21, 20, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(21, 22, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(21, 23, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(21, 24, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(21, 25, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(21, 30, Nunavut-Continental, Continent(5, Nunavut, 3))
Territory(22, 6, NU-Southern_Islands, Continent(5, Nunavut, 3))
Territory(22, 11, NU-Southern_Islands, Continent(5, Nunavut, 3))
Territory(22, 21, NU-Southern_Islands, Continent(5, Nunavut, 3))
Territory(22, 23, NU-Southern_Islands, Continent(5, Nunavut, 3))
Territory(23, 6, NU-Baffin_Island, Continent(5, Nunavut, 3))
Territory(23, 21, NU-Baffin_Island, Continent(5, Nunavut, 3))
Territory(23, 22, NU-Baffin_Island, Continent(5, Nunavut, 3))
Territory(23, 26, NU-Baffin_Island, Continent(5, Nunavut, 3))
Territory(23, 25, NU-Baffin_Island, Continent(5, Nunavut, 3))
Territory(24, 21, NU-Victoria_Island-East, Continent(5, Nunavut, 3))
Territory(24, 25, NU-Victoria_Island-East, Continent(5, Nunavut, 3))
Territory(24, 29, NU-Victoria_Island-East, Continent(5, Nunavut, 3))
Territory(25, 21, NU-Northern_Islands, Continent(5, Nunavut, 3))
Territory(25, 23, NU-Northern_Islands, Continent(5, Nunavut, 3))
Territory(25, 24, NU-Northern_Islands, Continent(5, Nunavut, 3))
Territory(25, 26, NU-Northern_Islands, Continent(5, Nunavut, 3))
Territory(25, 27, NU-Northern_Islands, Continent(5, Nunavut, 3))
Territory(26, 23, NU-Ellesmere_Island, Continent(5, Nunavut, 3))
Territory(26, 25, NU-Ellesmere_Island, Continent(5, Nunavut, 3))
Territory(27, 25, NT-Northern_Islands, Continent(6, Northwestern_Territories, 2))
Territory(27, 28, NT-Northern_Islands, Continent(6, Northwestern_Territories, 2))
Territory(27, 29, NT-Northern_Islands, Continent(6, Northwestern_Territories, 2))
Territory(28, 27, NT-Banks_Island, Continent(6, Northwestern_Territories, 2))
Territory(28, 29, NT-Banks_Island, Continent(6, Northwestern_Territories, 2))
Territory(28, 30, NT-Banks_Island, Continent(6, Northwestern_Territories, 2))
Territory(29, 24, NT-Victoria_Island-West, Continent(6, Northwestern_Territories, 2))
Territory(29, 27, NT-Victoria_Island-West, Continent(6, Northwestern_Territories, 2))
Territory(29, 28, NT-Victoria_Island-West, Continent(6, Northwestern_Territories, 2))
Territory(29, 30, NT-Victoria_Island-West, Continent(6, Northwestern_Territories, 2))
Territory(30, 17, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(30, 18, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(30, 19, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(30, 21, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(30, 28, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(30, 29, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(30, 31, Northwest_Territories-Continental, Continent(6, Northwestern_Territories, 2))
Territory(31, 17, Yukon_Territory, Continent(6, Northwestern_Territories, 2))
Territory(31, 30, Yukon_Territory, Continent(6, Northwestern_Territories, 2))
extracting countries/territories from maps/canada.map map... DONE!
Adjacency List
0 :
1 : 8 2 3
2 : 1 3
3 : 1 2 4
4 : 3 5 7
5 : 4 7 6
6 : 5 7 22 23
7 : 4 5 6 8 11
8 : 1 7 9
9 : 8 11 10
10 : 9 11 12
11 : 7 9 10 20 22
12 : 10 13 20
13 : 12 19 14
14 : 13 18 15
15 : 14 16 17
16 : 15
17 : 15 31 30 18
18 : 14 17 19 30
19 : 13 18 20 30
20 : 11 12 19 21
21 : 20 22 23 24 25 30
22 : 6 11 21 23
23 : 6 21 22 26 25
24 : 21 25 29
25 : 21 23 24 26 27
26 : 23 25
27 : 25 28 29
28 : 27 29 30
29 : 24 27 28 30
30 : 17 18 19 21 28 29 31
31 : 17 30
Graph is connected!
All territories belong to a continent!

C:\Users\Raymart\source\repos\tramyardg\warzone-c345\Warzone\Debug\Warzone.exe (process 1756) exited with code 0.
Press any key to close this window . . .

*/
/