#pragma once
using namespace std;

// load maps
// user can select a map
// user can select num players
// create players 2 min, 5 max
class GameEngine
{
public:
	void readMapDir();
	list<string> mapFiles;
};

