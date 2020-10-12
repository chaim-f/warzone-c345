#include "Cards.h"
#include <time.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

int main() {
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
	return 0;
}