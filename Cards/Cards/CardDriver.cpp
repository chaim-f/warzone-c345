#include "Cards.h"
#include <time.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

int main() {
	//Deck deckDefaultConstruct;
	//deckDefaultConstruct.printDeck();
	Deck otherDeck(4, 5, 3, 2, 1);
	otherDeck.printDeck();
	Hand hand1;
	Hand hand2;
	hand1.printHand();
	std::cout << std::endl;
	//printCommands();
	otherDeck.Draw(hand1);
	otherDeck.Draw(hand1);
	hand1.printHand();
	std::cout << std::endl;
	Card* cardID = new Card("bomb");
	hand2.addCard(cardID);
	hand2.printHand();
	std::cout << std::endl;
	otherDeck.printDeck();
	hand2.play("bomb", otherDeck);
	otherDeck.printDeck();
	hand2.printHand();
	
	char a;
	cin >> a;


	return 0;
}