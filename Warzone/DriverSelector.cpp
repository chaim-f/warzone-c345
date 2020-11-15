#include <iostream>
#include "DriverSelector.h"
#include "GameEngine.h"
#include "GameEngine.h"
#include "Map.h"
#include "MapLoader.h"
#include "Player.h"
using namespace std;


namespace DriverSelector {
	void runGameEngine() {
		GameStart g;
		g.runAllFunctions();
	}

	void runMapDriver()
	{
		Continent c1(0, 1, "Continent A", 2);
		Continent c2(0, 2, "Continent A", 1);
		Continent c3(1, 2, "Continent C", 3);

		cout << endl;

		// valid case: connected map & all territories belong to a continent
		Map* m1;
		m1 = new Map();
		m1->createMap(3, false);
		Territory* t1 = new Territory(0, 1, c1);
		Territory* t2 = new Territory(0, 2, c2);
		Territory* t3 = new Territory(1, 2, c3);
		m1->addEdge(t1);
		m1->addEdge(t2);
		m1->addEdge(t3);
		m1->displayAdjacencyList();
		m1->validate();

		cout << endl;

		// invalid case: not connected
		Map* m2;
		m2 = new Map();
		m2->createMap(5, false);
		Territory* a1 = new Territory(0, 1, c1);
		Territory* a2 = new Territory(0, 2, c2);
		Territory* a3 = new Territory(3, 4, c3);
		m2->addEdge(a1);
		m2->addEdge(a2);
		m2->addEdge(a3);
		m2->displayAdjacencyList();
		m2->validate();

		cout << endl;

		// invalid case: not all territories belong to a continent
		Map* m3;
		m3 = new Map();
		m3->createMap(6, false);
		Territory* b1 = new Territory(0, 4);
		Territory* b2 = new Territory(0, 3);
		Territory* b3 = new Territory(1, 2);
		Territory* b4 = new Territory(1, 4);
		Territory* b5 = new Territory(1, 5);
		Territory* b6 = new Territory(2, 3);
		Territory* b7 = new Territory(5, 3);
		Territory* b8 = new Territory(5, 4);
		m3->addEdge(b1);
		m3->addEdge(b2);
		m3->addEdge(b3);
		m3->addEdge(b4);
		m3->addEdge(b5);
		m3->addEdge(b6);
		m3->addEdge(b7);
		m3->addEdge(b8);
		m3->displayAdjacencyList();
		m3->validate();
	}

	void runMapLoaderDriver()
	{
		//	Valid case
		// load and store map objects
		string canadaMapFile = "maps/canada.map";
		MapLoader canadaMap = MapLoader();
		canadaMap.setFileName(canadaMapFile);
		canadaMap.storeContinents();
		canadaMap.storeTerritories();
		canadaMap.storeTerritoriesWithBorders();

		// create map and validate
		Map* map;
		map = new Map();
		map->createMap(canadaMap.getTerritories().size() + 1, true);

		for (int i = 0; i < canadaMap.getTerritoriesWithBorders().size(); i++) {
			map->addEdge(canadaMap.getTerritoriesWithBorders()[i]);
		}
		map->displayAdjacencyList();
		map->validate();


		// Invalid case
		string europeFile = "maps/europe.map";
		MapLoader europeMap = MapLoader();
		europeMap.setFileName(europeFile);
		europeMap.storeContinents();
		europeMap.storeTerritories();
		europeMap.storeTerritoriesWithBorders();

		Map* map2;
		map2 = new Map();
		map2->createMap(static_cast<int>(europeMap.getTerritories().size() + 1), true);

		for (int i = 0; i < europeMap.getTerritoriesWithBorders().size(); i++) {
			map2->addEdge(europeMap.getTerritoriesWithBorders()[i]);
		}
		map2->displayAdjacencyList();
		map2->validate();
	}

	void runPlayerDriver()
	{
		const char* player1 = "Ale";
		const char* player2 = "Aisha";
		const char* player3 = "Noemie";


		//Player* p1 = new Player(player1);
		//Player* p2 = new Player(player2);

		Player* p1 = playerFactory(player1);
		Player* p2 = playerFactory(player2);
		Player* p3 = p2;

		Territory* t1 = nullptr;
		Territory* t2 = nullptr;
		Territory* target1 = nullptr;

		Order* myOrder;
		myOrder = new Order();


		try {
			t1 = new Territory(1, 56);

		}
		catch (bad_alloc&) {
			cout << "Error allocating memory to territory." << endl;
		}

		try {
			t2 = new Territory(2, 100);
		}
		catch (bad_alloc&) {
			cout << "Error allocating memory to territory." << endl;
		}

		try {
			target1 = new Territory(1, 200);
		}
		catch (bad_alloc&) {
			cout << "Error allocating memory to territory." << endl;
		}

		//Add territory to player's territories

		p1->addMyTerritory(*t1);
		p2->addMyTerritory(*t2);

		//List players list of territories to defend
		p1->toDefend();

		//List player's list of territories to attack
		p1->toAttack();

		//Add Order

		//Test operator overloading
		cout << *p3;
		cout << *p2;
		cout << *p1;

		//Free memory used by test objects in Heap
		delete t1;
		t1 = NULL;

		delete t2;
		t2 = NULL;

		delete t2;
		t2 = NULL;

		delete p1;
		p1 = NULL;

		delete p2;
		p2 = NULL;
	}

	void runOrderDriver()
	{
		Orderlist* olist = new Orderlist();

		Airlift* airlift1 = new Airlift();
		Bomb* bomb1 = new Bomb();
		Deploy* deploy1 = new Deploy();
		Advance* adv1 = new Advance();
		Blockade* block1 = new Blockade();
		Negotiate* nego1 = new Negotiate();

		cout << *airlift1 << "\n";

		olist->add(airlift1);
		olist->add(bomb1);
		olist->add(block1);
		olist->add(adv1);
		olist->add(nego1);
		olist->add(deploy1);


		cout << *olist << "\n";


		olist->move(nego1, block1);

		cout << *olist << "\n";

		Airlift* airlift2 = airlift1;

		olist->add(airlift2);

		cout << *olist << "\n";

		olist->remove(airlift1);

		cout << *olist << "\n";
	}

	void runCardDriver()
	{
		cout << "creating a default deck\n";
		Deck deckDefaultConstruct;
		cout << "printing the default deck\n";
		deckDefaultConstruct.printDeck();
		cout << "\ncreating a deck with inputs 4, 5, 3, 2, 1 \n";
		Deck otherDeck(4, 5, 3, 2, 1);
		cout << "printing the deck\n";
		otherDeck.printDeck();
		cout << "\ncreating a default hand\n";
		Hand hand1;
		cout << "printing the contents of the hand\n";
		hand1.printHand();
		cout << "\ndrawing cards twice\n";
		otherDeck.Draw(hand1);
		otherDeck.Draw(hand1);
		cout << "reprinting the contents of the hand\n";
		hand1.printHand();
		cout << "\ntrying to play a bomb twice without looking if it is in the hand\n";
		hand1.play("bomb", otherDeck);
		hand1.play("bomb", otherDeck);
		cout << "reprinting the deck after 2 draws and playing the bomb twice\n";
		otherDeck.printDeck();
		cout << "\nadding 2 extra bombs to the deck\n";
		otherDeck.addCard("bomb");
		otherDeck.addCard("bomb");
		cout << "reprinting the deck after \n";
		otherDeck.printDeck();
		cout << "\nadding two random cards to the deck\n";
		otherDeck.addCard();
		otherDeck.addCard();
		cout << "reprinting the deck after \n";
		otherDeck.printDeck();
		cout << "\ncreating another default deck\n";
		Deck deckDefaultConstruct1;
		cout << "printing the default deck\n";
		deckDefaultConstruct1.printDeck();
		cout << "\nreprinting the original default deck\n";
		deckDefaultConstruct.printDeck();
		char b;
		cout << "\nenter any char and click enter to close the screen\n";
		cin >> b;
	}
}

//int main() {
//	int driverNum;
//	enum Driver { GAME_ENGINE = 0, MAP = 1, MAP_LOADER = 2, PLAYER = 3, ORDER = 4, CARD = 5 };
//	cout << "What driver to run?" << endl;
//	cout << "Enter [GAME_ENGINE = 0, MAP = 1, MAP_LOADER = 2, PLAYER = 3, ORDER = 4, CARD = 5]" << endl;
//	cin >> driverNum;
//	switch (driverNum) {
//	case GAME_ENGINE:
//		DriverSelector::runGameEngine();
//		break;
//	case MAP:
//		DriverSelector::runMapDriver();
//		break;
//	case MAP_LOADER:
//		DriverSelector::runMapLoaderDriver();
//		break;
//	case PLAYER:
//		DriverSelector::runPlayerDriver();
//		break;
//	case ORDER:
//		DriverSelector::runOrderDriver();
//		break;
//	case CARD:
//		DriverSelector::runCardDriver();
//		break;
//	}
//	return 0;
//}