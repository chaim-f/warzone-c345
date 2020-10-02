#include "Cards.h"
#include <time.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <string>

std::string CardsAllow[5] = { "bomb", "reinforcement", "blockade", "airlift", "diplomacy" };//see how to make this a pointer***
int amountAllow[5] = { 2,2,2,2,2 };//not set yet

//Card functions-------------------------------------------------------------------------------------------------------------
Card::Card(std::string cardID)//currently creates any type of card without looking at limit of cards allowed
{
	cardType = new std::string();
	bool correct = false;
	for (std::string* p = &CardsAllow[0]; p != &CardsAllow[5]; ++p) {
		if ((p->compare(cardID)) == 0) { correct = true; }
	}
	if (correct)
	{
		*cardType = cardID;
	}
	else {
		std::cout << "incorrect card type it need to be lowercase so using the default contructor\n";
		Card();
	}
}

Card::Card()//currently creates any type of card without looking at limit of cards allowed
{
	cardType = new std::string();
	srand((unsigned)time(NULL));
	int temp = (int)rand() % 5;
	*cardType = CardsAllow[temp];
}

Card::~Card()
{
	delete cardType;
}

Card& Card::operator=(const Card &orig) {
	if (&orig != this) {
		delete cardType;
		cardType = new std::string(*orig.cardType);
	}
	return *this;
}
Card::Card(const Card& orig) {
	cardType = new std::string(*orig.cardType);
}

std::string Card::getCardType()
{
	return *cardType;
}
void Card::setCardType(std::string s)
{
	*cardType = s;
}
void Card::play(std::string cardType)//to do fill it in such that it fills the order list*********************************************
{
	if (cardType.compare(CardsAllow[0]) == 0)//it is a bomb card
	{
		std::cout << "played a bomb card\n";
	}
	else if (cardType.compare(CardsAllow[1]) == 0)//it is a reinforcement card
	{
		std::cout << "played a reinforcement card\n";
	}
	else if (cardType.compare(CardsAllow[2]) == 0)//it is a blockade card
	{
		std::cout << "played a blockade card\n";
	}
	else if (cardType.compare(CardsAllow[3]) == 0)//it is a airlift card
	{
		std::cout << "played a airlift card\n";
	}
	else if (cardType.compare(CardsAllow[4]) == 0)//it is a diplomacy card
	{
		std::cout << "played a diplomacy card\n";
	}
	else { std::cout << "error there should be no other type of card, it is of type: " << cardType << "\n"; }
}

void Card::play()//to do fill it in such that it fills the order list*********************************************
{
	std::string cardType = getCardType();
	if (cardType.compare(CardsAllow[0]) == 0)//it is a bomb card
	{
		std::cout << "played a bomb card\n";
	}
	else if (cardType.compare(CardsAllow[1]) == 0)//it is a reinforcement card
	{
		std::cout << "played a reinforcement card\n";
	}
	else if (cardType.compare(CardsAllow[2]) == 0)//it is a blockade card
	{
		std::cout << "played a blockade card\n";
	}
	else if (cardType.compare(CardsAllow[3]) == 0)//it is a airlift card
	{
		std::cout << "played a airlift card\n";
	}
	else if (cardType.compare(CardsAllow[4]) == 0)//it is a diplomacy card
	{
		std::cout << "played a diplomacy card\n";
	}
	else { std::cout << "error there should be no other type of card, it is of type: " << cardType << "\n"; }
}

void Card::toString()
{
	std::cout << "the card type is: " << getCardType() << "\n";
}

//Deck functions-------------------------------------------------------------------------------
Deck::Deck()
{
	int totalCards = amountAllow[0] + amountAllow[1] + amountAllow[2] + amountAllow[3] + amountAllow[4];
	int actualAmount[5];
	bool Allowed = false;
	std::string tempString;
	for (int i = 0; i < 5; i++) {
		actualAmount[i] = amountAllow[i];
	}
	//Populating the cards in the deck
	for (int i = 0; i < totalCards; i++) {
		Card* tempCard = new Card();
		while (!Allowed) {
			srand((unsigned)time(NULL));
			int temp = (int)rand() % 5;
			tempString = CardsAllow[temp];
			if (amountAllow[temp] > 0) {
				amountAllow[temp]--;
				Allowed = true;
			}
		}
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
		Allowed = false;
	}
}

Deck::Deck(int nbomb = 2, int nreinforcement = 2, int nblockade = 2, int nairlift = 2, int ndiplomacy = 2)
{
	int totalCards = nbomb + nreinforcement + nblockade + nairlift + ndiplomacy;
	amountAllow[0] = nbomb;
	amountAllow[1] = nreinforcement;
	amountAllow[2] = nblockade;
	amountAllow[3] = nairlift;
	amountAllow[4] = ndiplomacy;
	int actualAmount[5];
	bool Allowed = false;
	std::string tempString;
	for (int i = 0; i < 5; i++) {
		actualAmount[i] = amountAllow[i];
	}
	//Populating the cards in the deck
	for (int i = 0; i < totalCards; i++) {
		Card* tempCard = new Card();
		while (!Allowed) {
			srand((unsigned)time(NULL));
			int temp = (int)rand() % 5;
			tempString = CardsAllow[temp];
			if (amountAllow[temp] > 0) {
				amountAllow[temp]--;
				Allowed = true;
			}
		}
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
		Allowed = false;
	}
}

Deck::~Deck()
{
	for (auto&& x : deckCards) {
		delete x;
	}
}

Deck& Deck::operator=(const Deck &orig) {
	if (&orig != this) {
		for (auto&& x : deckCards) {
			delete x;
		}
		for (auto && x : orig.deckCards) {
			deckCards.push_back(new Card(*x));
		}
	}
	return *this;
}


Deck::Deck(const Deck& orig) {
	for (auto && x : orig.deckCards) {
		deckCards.push_back(new Card(*x));
	}
}

void Deck::Draw(Hand& handID)
{
	//to do remove random card from deck add to hand of player calling function
	int currentDeckSize = deckCards.size();
	srand((unsigned)time(NULL));
	int temp = (int)rand() % currentDeckSize;
	/*Card* tempCard = new Card(*deckCards.at(temp));
	handID.addCard(tempCard);*/
	handID.addCard(deckCards.at(temp));
	deckCards.erase(deckCards.begin() + temp);
}

void Deck::returnCard(Card* cardId)//currently allows returns of cards from else where
{
	deckCards.push_back(cardId);
}

void Deck::printDeck()
{
	std::cout << "the deck contains the following cards:\n";
	int cardInHand[5] = { 0 };
	for (auto && x : deckCards) {
		std::string cardType = x->getCardType();
		if (cardType.compare(CardsAllow[0]) == 0)//it is a bomb card
		{
			cardInHand[0]++;
		}
		else if (cardType.compare(CardsAllow[1]) == 0)//it is a reinforcement card
		{
			cardInHand[1]++;
		}
		else if (cardType.compare(CardsAllow[2]) == 0)//it is a blockade card
		{
			cardInHand[2]++;
		}
		else if (cardType.compare(CardsAllow[3]) == 0)//it is a airlift card
		{
			cardInHand[3]++;
		}
		else if (cardType.compare(CardsAllow[4]) == 0)//it is a diplomacy card
		{
			cardInHand[4]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << CardsAllow[i] << ": " << cardInHand[i] << "\n";
	}
}

//Hand functions-------------------------------------------------------------------------------
Hand::Hand()
{
	//do nothing hand starts empty
}

Hand::~Hand()
{
	for (auto&& x : handCards) {
		delete x;
	}
}
Hand& Hand::operator=(const Hand &orig)
{
	if (&orig != this) {
		for (auto&& x : handCards) {
			delete x;
		}
		for (auto && x : orig.handCards) {
			handCards.push_back(new Card(*x));
		}
	}
	return *this;
}

Hand::Hand(const Hand& orig)
{
	for (auto && x : orig.handCards) {
		handCards.push_back(new Card(*x));
	}
}

void Hand::addCard(Card* cardID)
{
	handCards.push_back(cardID);
}

void Hand::removeCard(Card* cardID)
{
	int temp = 0;
	for (auto&& x : handCards) {
		if (x== cardID) {  break; }
		temp++;
	}
	handCards.erase(handCards.begin() + temp);
}

void Hand::play(std::string cardType, Deck& deckId)
{
	if (isInHand(cardType))//check if the type card is in hand  
	{
		Card* tempCardP=nullptr;
		for (auto&& x : handCards) {
			if (x->getCardType().compare(cardType) == 0) { tempCardP = x; break; }
		}
		if(tempCardP != nullptr)tempCardP->play();
		deckId.returnCard(tempCardP);
		removeCard(tempCardP);
	}


}
bool Hand::isInHand(std::string cardType)
{
	for (auto&& x : handCards) {
		if (x->getCardType().compare(cardType) == 0) { return true; }
	}
	return false;
}

void Hand::printHand()
{
	std::cout << "the hand contains the following cards:\n";
	int cardInHand[5] = { 0 };
	int index = 0;
	for (auto && x : handCards) {
		std::cout << index++<<x->getCardType() << "\t";
		std::string cardType = x->getCardType();
		if (cardType.compare(CardsAllow[0]) == 0)//it is a bomb card
		{
			cardInHand[0]++;
		}
		else if (cardType.compare(CardsAllow[1]) == 0)//it is a reinforcement card
		{
			cardInHand[1]++;
		}
		else if (cardType.compare(CardsAllow[2]) == 0)//it is a blockade card
		{
			cardInHand[2]++;
		}
		else if (cardType.compare(CardsAllow[3]) == 0)//it is a airlift card
		{
			cardInHand[3]++;
		}
		else if (cardType.compare(CardsAllow[4]) == 0)//it is a diplomacy card
		{
			cardInHand[4]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << CardsAllow[i] << ": " << cardInHand[i] << "\n";
	}
}

void printCommands() {
	std::cout<<"\nList of commands:\n";
	std::cout << "For Deck: \nDraw(Hand handID): draws a card and adds it to the Hand HandID,\nreturnCard(Card* cardId): returns a card to the deck, \nprintDeck(): prints the types of cards in the deck\n";
	std::cout << "\nFor Hand: \naddCard(Card* cardID): adds card to hand,\nremoveCard(Card* cardID): removes card from Hand,\nplay(string cardType, Deck deck): plays card type and returns played card to deck,\nisInHand(string cardType): check if card type is in hand returns a boolean value,\n;printHand() prints the contents of the hand\n";
}