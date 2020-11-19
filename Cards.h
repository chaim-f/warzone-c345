#pragma once
#include <iostream>
#include <vector>
#include "Order.h"

class Hand;
class Deck;

class Card
{
	friend class Deck;
private:
	//constructors are private as only the Deck class which is a friend should be allowed to create and change the CardType
	std::string* cardType;//holds the card type acceptable inputs is "bomb", "reinforcement", "blockade", "airlift", "diplomacy" any other input will result in a random card being generated
	Card(std::string cardID);//constructer with the type as an input, if type is wrong randomly choses 
	Card();//default constructor
	void  setCardType(std::string cardType);//cardType setter
public:	
	~Card();//destructor
	Card& operator=(const Card &orig);//overloading the equals 
	Card(const Card& orig);//copy constructor
	std::string getCardType();//cardType getter 
	Order* play();// adds order of card type to the order list based on the cardType
	void printCard();//prints card type
};



class Deck
{
public:
	Deck();//default constructor
	Deck(int nbomb, int nreinforcement, int nblockade, int nairlift, int ndiplomacy);//constructor
	~Deck();//destructor
	Deck& operator=(const Deck &orig);//overloading the equals operator
	Deck(const Deck& orig);//copy constructor
	void Draw(Hand& handID);//draws a random card
	void returnCard(Card* cardId);//adds a card to the vector can move from one deck to another
	void printDeck();//prints the card types in the deck
	int amountAllow[5];//contains the amount of each card type if the default constructor is called other cards can be added manually
	void addCard();//adds a random card to the Deck
	void addCard(std::string cardID);//adds a specific card to the Deck
	bool isEmpty();
private:
	std::vector <Card*> deckCards;//vector of cards in the deck
};

class Hand
{
public:
	Hand();//default constructor
	~Hand();//destructor
	Hand& operator=(const Hand &orig);//overloading the equals operator
	Hand(const Hand& orig);//copy constructor
	void addCard(Card* cardID);//adds a card to the hand
	void removeCard(Card* cardID);//removes card from the hand
	Order* play(std::string cardType, Deck& deck);//plays a card (adds to deck, removes from hand, and adds order to the order list)
	bool isInHand(std::string cardType);//check if the type of card is in the hand
	void printHand();//prints the card types in the hand
private:
	std::vector <Card*> handCards;//vector of cards in the hand
};

void printCommands();//prints useable commands
