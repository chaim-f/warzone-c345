#pragma once
#include <iostream>
using namespace std;

class Continent
{
	string continentName;
	int continentIndex;
	int continentBunos;
public:
	Continent();
	Continent(int index, string name);
	Continent(int index, string name, int bunos);
	int getContinentIndex();
};

