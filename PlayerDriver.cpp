/***********************************************************************
	Assignment 1 - TEAM 21
	Part 4
*/

/**********************************************************************/


#include <cstdlib>
#include <list>
#include "Territory.h"
#include "Continent.h"
#include "Map.h"
#include "Order.h"
#include "Player.h"
#include "Cards.h"
using namespace std;



int main()
{

	const char*  player1 = "Ale";
	

	const char*  player2 = "Aisha";
	
	const char* player3 = "Noemie";
	

	//Player* p1 = new Player(player1);
	//Player* p2 = new Player(player2);

	Player* p1 = playerFactory(player1);
	Player* p2 = playerFactory(player2);

	Player* p3 = p2;

	Territory* t1 = nullptr;
	Territory* t2 = nullptr;

	Territory* target1 = nullptr;

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



/*
void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}
*/