#pragma once
#include <iostream>
using namespace std;

class MapLoader
{
	string fileName;
public:
	void setFileName(string name);
	void read();
	MapLoader();
};