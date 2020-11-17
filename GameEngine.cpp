#include "GameEngine.h"
#include "Map.h"
#include <iostream>
#include <filesystem>
#include <time.h>
#include <random>
#include <algorithm>
#include <numeric>
using namespace std;
namespace fs = std::filesystem;

int main() {
	GameStart g;
	g.runAllFunctions(); 
	startupPhase(g);
	return 0;
}

const int minPlayer = 2;
const int maxPlayer = 5;

// if input is not of type integer
void cinFail() {
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void GameStart::runAllFunctions()
{
	cout << "********** GAME START **********" << endl;
	this->readMapDirectory();
	this->loadMaps();
	this->storeMaps();
	this->validatingMaps();
	this->promptUserToSelectMap();
	this->promptUserToSelectNumberOfPlayers();
	vector<Territory*>::iterator iter;
	this->createPlayers();
}

void GameStart::readMapDirectory()
{
	cout << "Reading map directory..." << endl;
	int i = 0;
	for (const auto& p : fs::directory_iterator("maps")) {
		const auto path = p.path();
		if (p.is_regular_file() && path.filename().extension() == ".map") {
			i++;
			cout << "> map " << i << ": maps/" + path.filename().string() << endl; // e.g. "maps/canada.map"
			mapFiles.push_back("maps/" + path.filename().string());
		}
	}
	cout << "done..." << endl;
}

void GameStart::loadMaps()
{
	cout << "Loading maps..." << endl;
	list<string>::iterator it;
	for (it = mapFiles.begin(); it != mapFiles.end(); ++it) {
		string filename = (*it);
		mapLoaders.push_back(new MapLoader((*it)));
	}
	cout << "done..." << endl;
}

void GameStart::storeMaps()
{
	cout << "Storing map..." << endl;
	vector<MapLoader*>::iterator iter;
	for (iter = mapLoaders.begin(); iter != mapLoaders.end(); ++iter) {
		(*iter)->storeContinents();
		(*iter)->storeTerritories();
		(*iter)->storeTerritoriesWithBorders();
	}
	cout << "done..." << endl;
}

void GameStart::validatingMaps()
{
	cout << "Validating maps..." << endl;
	int invalidMapIndex = NULL;
	for (int i = 0; i < mapLoaders.size(); i++) {
		Map* map;
		map = new Map();
		map->createMap(mapLoaders.at(i)->getTerritories().size() + 1, true);
		for (int j = 0; j < mapLoaders.at(i)->getTerritoriesWithBorders().size(); j++) {
			map->addEdge(mapLoaders.at(i)->getTerritoriesWithBorders()[j]);
		}
		cout << "> validating " << mapLoaders.at(i)->getFileName() << endl;
		map->validate();
		if (map->getIsValidMapFile() == 0) {
			invalidMapIndex = i; // store index of invalid map
		}
	}
	cout << "done..." << endl;
	if (invalidMapIndex != NULL) {
		cout << "Gracefully rejecting " << mapLoaders.at(invalidMapIndex)->getFileName() << endl;
		mapLoaders.erase(mapLoaders.begin() + invalidMapIndex);
		cout << "done..." << endl;
	}
}

void GameStart::promptUserToSelectNumberOfPlayers()
{
	int num;
	cout << endl << "Enter the number players. Must be a value between " << minPlayer << "-" << maxPlayer << endl;
	cin >> num;
	while (num < minPlayer || num > maxPlayer)
	{
		cinFail();
		cout << "Invalid input! Must be a value between " << minPlayer << "-" << maxPlayer << endl;
		cout << "Please try again." << endl;
		cin >> num;
	}
	this->setNumPlayers(num);
}

void GameStart::promptUserToSelectMap()
{
	cout << endl << "Please choose a map..." << endl;
	int chosenMapIndex;
	for (unsigned k = 0; k < mapLoaders.size(); ++k) {
		cout << "Enter number " << (k + 1) << " to choose " << mapLoaders.at(k)->getFileName() << endl;
	}
	cin >> chosenMapIndex;
	while (chosenMapIndex <= 0 || chosenMapIndex > mapLoaders.size())
	{
		cinFail();
		cout << "Invalid input! Must be a value between 1-" << mapLoaders.size() << endl;
		cout << "Please enter a number again." << endl;
		cin >> chosenMapIndex;
	}
	int chosenIndex = chosenMapIndex - 1;
	cout << mapLoaders.at(chosenIndex)->getFileName() << " was chosen" << endl;
	this->setChosenMap(mapLoaders.at(chosenIndex)->getTerritoriesWithBorders());
}

void GameStart::setChosenMap(vector<Territory*> chosenMap)
{
	this->chosenMap = chosenMap;
}

void GameStart::setPlayersCreated(vector<Player*> playersCreated)
{
	this->playersCreated = playersCreated;
}

void GameStart::setNumPlayers(int num)
{
	this->numPlayers = num;
}

/*void GameStart::createPlayers()
{
	cout << "Creating players..." << endl;
	vector<Player*> randPlayers{
		new Player("Ben"),
		new Player("Tom"),
		new Player("Jerry"),
		new Player("Batman"),
		new Player("Robin")
	};
	vector<Player*> players;
	for (int i = 0; i < this->getNumPlayers(); i++) {
		// select player randomly from the list
		int r = rand() % randPlayers.size() - 1;
		players.push_back(randPlayers.at(r));
	}
	this->setPlayersCreated(players);

	// just to see the name of the first created player
	cout << this->getPlayersCreated().at(0)->getPlayerName() << endl;

	cout << "done...";
}*/
void GameStart::createPlayers()
{
cout << "Creating " << this->getNumPlayers() << " players" << endl;
cout << "------------------------------------------------------" << endl;
vector<string> names{ "Ben", "Tom", "Jerry", "Batman", "Robin" };

random_device rd;
mt19937 rng(rd());
vector<int> data(maxPlayer); // this will create a random sequence of 0-4, e.g. [2,4,3,1,0]; [1,0,2,3,4]
iota(data.begin(), data.end(), 0);
shuffle(data.begin(), data.end(), rng); // every
vector<int> randomSequence;
vector<Player*> players;
for (auto& r : data) {
	randomSequence.push_back(r);
}
for (int i = 0; i < this->getNumPlayers(); i++) {
	players.push_back(new Player(names.at(randomSequence.at(i))));
}

// if the random sequence is [2,4,3,1,0]
// and number of player chosen was 4
// then we take select the first 4 elements from the sequence: [2,4,3,1]
// similarly, if the random sequence is [1,0,2,3,4]
// and number of player chosen was 2
// then players: Tom (at index 1) and Ben (at index 0) will play the game
this->setPlayersCreated(players);
cout << "------------------------------------------------------" << endl;
}


int GameStart::getNumPlayers()
{
	return numPlayers;
}

vector<Player*>& GameStart::getPlayersCreated()
{
	return playersCreated;
}

vector<Territory*> GameStart::getChosenMap() {
	return chosenMap;
}

void startupPhase(GameStart& g) {	
	createTheOrder(g);
	distrubuiteTerritories(g);
	setReinforcements(g);
}

void createTheOrder(GameStart& g) {
	int numOfPlayers = g.getNumPlayers();
	int holder[5] = { -1,-1,-1,-1,-1 };
	vector<Player> tempVector;//put the order in here than copy to pList
	srand((unsigned)time(NULL));//seeds the rand function based on the time
	int temp;
	int counter = numOfPlayers;
	for (int i = 0; i < numOfPlayers; i++) {
		temp = (int)rand() % counter--;//takes the random values and takes the mod so it returns values between 0 and number ofplayers who have not yet been assigned a value
		for (int j = 0; j < i; j++) {//goes through all previous value
			if (temp >= holder[j]) { temp = (temp + 1) % numOfPlayers; }//if the random value is greater or equal to a player already chosen temp++ so it can access the later values
		}
		holder[i] = temp;//the player number temp is in the ith postion
		tempVector.push_back(*g.getPlayersCreated().at(temp));//push the player at the temp position in the pList to the ith position in the tempVector
	}
	for (auto& x : g.getPlayersCreated()) {
		delete x;
		x = NULL;
	}
	g.getPlayersCreated().empty();
	for (auto& x : tempVector) {
		g.getPlayersCreated().push_back(new Player(x));
	}
	cout << "\nthe Players were randomly chosen with the following order: \n";
	for (int i = 0; i < numOfPlayers; i++) {
		cout << (i + 1) << " " << g.getPlayersCreated().at(temp)->getPlayerName();
	}
}
void distrubuiteTerritories(GameStart& g) {
	int numOfPlayers = g.getNumPlayers();
	int numberOfTerritories = g.getChosenMap().size();
	int counter = numberOfTerritories;
	int temp;
	int holderT[9999];//assumed max number of Territories 
	for (int i = 0; i < 9999; i++) {
		holderT[i] = -1;
	}
	for (int i = 0; i < numberOfTerritories; i++) {
		temp = (int)rand() % counter--;//takes the random values and takes the mod so it returns values between 0 and number of territories -1
		for (int j = 0; j < i; j++) {
			if (temp >= holderT[j]) { temp = (temp + 1) % numberOfTerritories; }
		}
		holderT[i] = temp;
		g.getPlayersCreated().at(i % numOfPlayers)->addMyTerritory(*g.getChosenMap().at(temp));
	}
	cout << "\nAll Territories ranadomly allowcated";//it is random and so long as each territory is unique in the map it will also be unique here and not allowcated to two players
}
void setReinforcements(GameStart& g) {
	int numOfPlayers = g.getNumPlayers();
	int reinforcePool = 0;
	switch (numOfPlayers) {
	case 2: reinforcePool = 40; break;
	case 3:reinforcePool = 35; break;
	case 4:reinforcePool = 30; break;
	case 5:reinforcePool = 25; break;
	}
	for (int i = 0; i < numOfPlayers; i++) {
		g.getPlayersCreated().at(i)->setreinforcePool(reinforcePool);
	}
	cout << "\nFilled each players reinforcement pool with " << reinforcePool << endl;
}