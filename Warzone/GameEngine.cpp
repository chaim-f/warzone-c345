#include "GameEngine.h"
#include "Map.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
	GameStart g;
	g.runAllFunctions();
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
	//this->createPlayers();
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

void GameStart::createPlayers()
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
	cout << this->getPlayersCreated().at(0)->getPlayerName();

	cout << "done...";
}

int GameStart::getNumPlayers()
{
	return numPlayers;
}

vector<Player*> GameStart::getPlayersCreated()
{
	return playersCreated;
}

vector<Territory*> GameStart::getChosenMap() {
	return chosenMap;
}