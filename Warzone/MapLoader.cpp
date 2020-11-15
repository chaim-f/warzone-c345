#include <string>
#include <vector> 
#include <iostream>
#include "Player.h"
#include "map.h"
using namespace std;

int main() {
	Territory a=Territory(2, "USA", 3);
	Territory b = Territory(3, "Canada", 3);
	Territory c = Territory(4, "Mexico", 3);
	Territory c1 = Territory();
	b.getTroopsSationed();//how many troops are stationed here
	c1.setTroopsSationed(1);//set how many troops
	b.addTroopsSationed(3);// add troops as reinforcemt or minus of troops as they die (troops = -1||-2)
	cout<<b.toString();//return the state of the territory as a string
	c1.setTerritoryId(6);
	b.getTerritoryId();
	c1.setTerritoryName("Quebec");
	b.getTerritoryName();
	//c1.setInContinent(3);
	a.addAdjacent(&b);
	a.addAdjacent(&c);
	cout<<a.toString();
	cout << c1.toString();
	cout << "enter any char and then enter to exit";
	char d1;
	cin >> d1;
	return 0;
}