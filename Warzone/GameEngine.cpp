#include "GameEngine.h"
#include "Map.h"
#include <iostream>
#include <filesystem>
#include <time.h>
#include <random>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;
namespace fs = std::filesystem;

int main() {
	GameStart g;
	g.runAllFunctions();
	StartUpPhase sup(g.getTerritories(), g.getNumPlayers(), g.getPlayersCreated());
	sup.startupPhase();
	MainGameLoop mgl(g.getTerritories(), sup.getPlayers());
	mgl.setContinents(g.getContinents());
	mgl.mainGameLoop();
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

// create random sequence of integers given length
// e.g. if length is 3, then this will return a random sequence of 0-3 every time it is called, 
// for example: {0,2,1}, {1,0,2}, {2,1,0}, etc.
vector<int> createRandomSequence(int sequenceLength)
{
	random_device rd;
	mt19937 rng(rd());
	vector<int> data(sequenceLength);
	iota(data.begin(), data.end(), 0);
	shuffle(data.begin(), data.end(), rng);
	return data;
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
	this->createPlayers();

	/*for (int i = 0; i < this->getChosenMap().size(); i++) {
		if (this->getChosenMap().at(i)->getTerritoryIndex() == 1) {
			cout << this->getChosenMap().at(i)->getBorder() << endl;
		}
	}*/
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
	this->setTerritories(mapLoaders.at(chosenIndex)->getTerritories());
	this->setContinents(mapLoaders.at(chosenIndex)->getContinents());
}

void GameStart::setChosenMap(vector<Territory*> chosenMap)
{
	this->chosenMap = chosenMap;
}

void GameStart::setTerritories(vector<Territory*> territories)
{
	this->territories = territories;
}

void GameStart::setContinents(vector<Continent*> continents)
{
	this->continents = continents;
}

vector<Territory*> GameStart::getTerritories()
{
	return territories;
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
	cout << "Creating " << this->getNumPlayers() << " players" << endl;
	vector<string> names{ "Ben", "Tom", "Jerry", "Batman", "Robin" };
	vector<Player*> players;
	vector<int> randomSequence = createRandomSequence(maxPlayer);
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
}


int GameStart::getNumPlayers()
{
	return numPlayers;
}

vector<Player*> GameStart::getPlayersCreated()
{
	return this->playersCreated;
}

vector<Territory*> GameStart::getChosenMap() {
	return chosenMap;
}

vector<Continent*> GameStart::getContinents()
{
	return continents;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 2
/////////////////////////////////////////////////////////////////////////////////////////////////////

StartUpPhase::StartUpPhase(vector<Territory*> territories, int numOfPlayers, vector<Player*> players)
{
	this->territories = territories;
	this->numOfPlayers = numOfPlayers;
	this->players = players;
}

void StartUpPhase::startupPhase()
{
	this->distrubuiteTerritories();
	this->setReinforcements();
	this->createOrderOfPlay();
}

void StartUpPhase::createOrderOfPlay()
{
	int numPlayers = this->getPlayers().size();
	vector<int> randomSequence = createRandomSequence(numPlayers);
	for (int i = 0; i < this->getPlayers().size(); i++) {
		this->players.at(i)->setTurnNumber(randomSequence.at(i));
	}
	cout << "\norder of play\n";
	for (int i = 0; i < this->getPlayers().size(); i++) {
		cout << this->getPlayers().at(i)->getPlayerName() << " : " << this->getPlayers().at(i)->getTurnNumber() << endl;
	}
}

void StartUpPhase::distrubuiteTerritories() {
	int numberOfTerritories = this->territories.size();
	vector<int> randomSequence = createRandomSequence(numberOfTerritories); // create a random sequence of [0-numberOfTerritories]
	// e.g. numberOfTerritories = 24, a random sequence would be something like [23,1,4,6,1,2,0,8,5,...]

	cout << "\nditributing territories...\n";
	for (int i = 0; i < numberOfTerritories; i++) {
		this->players.at(i % this->numOfPlayers)->addTerritory(this->territories.at(randomSequence.at(i)));
	}

	// display territories own by players
	for (int i = 0; i < this->getPlayers().size(); i++) {
		for (int j = 0; j < this->getPlayers().at(i)->getTerritoriesOwn().size(); j++) {
			cout << this->getPlayers().at(i)->getPlayerName() << " owns ";
			this->getPlayers().at(i)->getTerritoriesOwn().at(j)->displayTerritories();
		}
	}
	cout << "All Territories ranadomly allowcated\n";
}

void StartUpPhase::setReinforcements() {
	int numOfPlayers = this->getNumOfPlayers();
	int reinforcePool = 0;
	switch (numOfPlayers) {
	case 2: reinforcePool = 40; break;
	case 3: reinforcePool = 35; break;
	case 4: reinforcePool = 30; break;
	case 5: reinforcePool = 25; break;
	}
	for (int i = 0; i < numOfPlayers; i++) {
		this->players.at(i)->setreinforcePool(reinforcePool);
	}
	cout << "\nFilled each players reinforcement pool with " << reinforcePool << " armies each" << endl;
	for (int i = 0; i < this->getPlayers().size(); i++) {
		cout << this->getPlayers().at(i)->getPlayerName() << " has " << this->getPlayers().at(i)->getreinforcePool() << " armies " << endl;
	}
}

vector<Territory*> StartUpPhase::getTerritories()
{
	return territories;
}

int StartUpPhase::getNumOfPlayers()
{
	return numOfPlayers;
}

vector<Player*> StartUpPhase::getPlayers()
{
	return players;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 3
/////////////////////////////////////////////////////////////////////////////////////////////////////

MainGameLoop::MainGameLoop(vector<Territory*> territories, vector<Player*> players)
{
	this->territories = territories;
	this->players = players;
}

void MainGameLoop::mainGameLoop()
{
	bool playOn = true;
	while (playOn) {
		cout << "\nin main loop";
		this->issueOrdersPhase();
		this->executeOrdersPhase();
		int temp;
		temp = 0;
		for (auto& x : players) {
			players.at(temp)->setNumTerritoriesOwn(players.at(temp)->getTerritoriesOwn().size());
			if (x->getNumTerritoriesOwn() == 0) {
				cout << "\nremoving " << players.at(temp)->getPlayerName() << " as he has no territories\n";
				players.erase(players.begin() + temp);//remove the player if he owns no territories
				continue;
			}
			temp++;
		}
		if (players.size() == 1) {
			cout << "\n\nPlayer " << players.at(0)->getPlayerName() << " Won ending game";
			playOn = false;
		}
		this->reinforcementPhase();
	}
	//this->getContinentBonus(this->players.at(0));
}

void MainGameLoop::reinforcementPhase()
{

	cout << "\nin reinforcement phase";
}

void MainGameLoop::issueOrdersPhase()
{
	cout << "\nissuing Orders\n";
	for (int i = 0; i < this->players.size(); i++) {
		this->players.at(i)->setNumTerritoriesOwn(this->players.at(i)->getTerritoriesOwn().size());
		vector<Player*> players = this->players;
		vector<Territory*> playerTerritories = players.at(i)->getTerritoriesOwn();
		int reinforcementPool = players.at(i)->getreinforcePool();
		int unit = 0;
		int territoriesOwn = playerTerritories.size();
		for (int j = 0; j < territoriesOwn; j++) {
			unit += ceil(reinforcementPool / territoriesOwn);
			if (j == (territoriesOwn - 2)) { // if this is the last territory, take whatever is left
				players.at(i)->addArmiesToTerritory(playerTerritories.at(j), (reinforcementPool - unit));
			}
			else {
				players.at(i)->addArmiesToTerritory(playerTerritories.at(j), ceil(reinforcementPool / territoriesOwn));
			}
		}
	}

	for (int i = 0; i < this->players.size(); i++) {
		vector<Territory*> playerTerritories = players.at(i)->getTerritoriesOwn();
		for (int j = 0; j < playerTerritories.size(); j++) {
			//playerTerritories.at(j)->displayTerritories();
			cout << this->players.at(i)->getPlayerName() << " territory " << playerTerritories.at(j)->getTerritoryName() << " has "
				<< playerTerritories.at(j)->getTerritoryArmies() << " armies " << endl;
		}
	}
}

void MainGameLoop::executeOrdersPhase()
{
	for (int i = 0; i < players.size(); i++) {
		if (!(players.at(i)->getOrderlist()->OrderListIsEmpty())) {
			for (auto& x : players.at(i)->getOrderlist()->getOrderList()) {//doing all the deploy orders first
				if (x->getName().compare("Deploy") == 0) {
					players.at(i)->executeOrderOfList(x);
				}
			}
		}
	}
	cout << "\nAll deploy orders are done";
	for (int i = 0; i < players.size(); i++) {
		if (!(players.at(i)->getOrderlist()->OrderListIsEmpty())) {//rechecking as there might have only be deploy orders
			for (auto& x : players.at(i)->getOrderlist()->getOrderList()) {//doing all the airlift orders next
				if (x->getName().compare("Airlift") == 0) {
					players.at(i)->executeOrderOfList(x);
				}
			}
		}
	}
	cout << "\nAll airlift orders are done";
	for (int i = 0; i < players.size(); i++) {
		if (!(players.at(i)->getOrderlist()->OrderListIsEmpty())) {//rechecking as there might have only be deploy orders
			for (auto& x : players.at(i)->getOrderlist()->getOrderList()) {//doing all the airlift orders next
				if (x->getName().compare("Blockade") == 0) {
					players.at(i)->executeOrderOfList(x);
				}
			}
		}
	}
	cout << "\nAll blockade orders are done";
	bool keepGoing=false;
	for (int i = 0; i < players.size(); i++) {
		if (!(players.at(i)->getOrderlist()->OrderListIsEmpty())) {
			keepGoing = true;
		}
	}
	while (keepGoing) {
		for (int i = 0; i < players.size(); i++) {
			if (!(players.at(i)->getOrderlist()->OrderListIsEmpty())) {
						players.at(i)->executeOrderOfList(players.at(i)->getOrderlist()->getOrderList().front());
			}
		}
		keepGoing = false;
		for (int i = 0; i < players.size(); i++) {
			if (!(players.at(i)->getOrderlist()->OrderListIsEmpty())) {
				keepGoing = true;
			}
		}
	}
}

int MainGameLoop::getContinentBonus(Player* p)
{
}

void MainGameLoop::setContinents(vector<Continent*> continents)
{
	this->continents = continents;
}
