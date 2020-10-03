#pragma once
#include <iostream>
using namespace std;

class Continent
{
	string continentName;
	int continentIndex = 0;
	int continentBunos = 0;
public:
	Continent();
	Continent(int index, string name);
	Continent(int index, string name, int bunos);
	int getContinentIndex();
	friend std::ostream& operator<<(std::ostream&, const Continent);
};

