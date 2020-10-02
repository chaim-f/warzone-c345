#pragma once
#include <iostream>
#include <vector>

class Hand;

class Card
{
private:
	std::string* cardType;
public:
	Card(std::string cardID);
	Card();
	~Card();
	Card& operator=(const Card &orig);
	Card(const Card& orig);
	std::string getCardType();
	void setCardType(std::string cardType);
	void play(std::string cardType);
	void play();
	void toString();
};



class Deck
{
public:
	Deck();
	Deck(int nbomb, int nreinforcement, int nblockade, int nairlift, int ndiplomacy);
	~Deck();
	Deck& operator=(const Deck &orig);
	Deck(const Deck& orig);
	void Draw(Hand& handID);
	void returnCard(Card* cardId);
	void printDeck();
private:
	std::vector <Card*> deckCards;
};

class Hand
{
public:
	Hand();
	~Hand();
	Hand& operator=(const Hand &orig);
	Hand(const Hand& orig);
	void addCard(Card* cardID);
	void removeCard(Card* cardID);
	void play(std::string cardType, Deck& deck);
	bool isInHand(std::string cardType);
	void printHand();
private:
	std::vector <Card*> handCards;
};

void printCommands();