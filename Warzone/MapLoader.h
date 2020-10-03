#pragma once
#include <iostream>
#include "Continent.h"
using namespace std;

class MapLoader
{
	string fileName;
public:
	void setFileName(string name);
	void read();
	void storeContinents();
	MapLoader();
};