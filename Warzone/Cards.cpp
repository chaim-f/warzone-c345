#include "Cards.h"
#include <time.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <string>

#include "Order.h"

//to do add the orderlist implementation to lines 79-104 then remove this comment.
std::string const CardsAllow[5] = { "bomb", "reinforcement", "blockade", "airlift", "diplomacy" };//strings allowed for Card types 
int const defaultAmountAllow[5] = { 3,3,3,3,3 };//the default number for amount of each card to be created

												//Card functions-------------------------------------------------------------------------------------------------------------
Card::Card(std::string cardID)//currently creates any type of card without looking at limit of cards allowed
{
	try
	{
		cardType = new std::string();//allocates memory
		bool correct = false;//sets the bool value that determins if the CardID is a correct string.
		for (int i = 0; i < 5; i++) {//loops through the strings allowed for Card types
			std::string p = CardsAllow[i];
			if ((p.compare(cardID)) == 0) { correct = true; }//if the string is allowed changes the boolean to true
		}
		if (correct)
		{
			*cardType = cardID;//as the card type is correct it sets the card type to the CardID string
		}
		else {
			std::cout << "incorrect card type it need to be lowercase so randomly allocating\n";
			srand((unsigned)time(NULL));//seeds the rand function based on the time
			int temp = (int)rand() % 5;//takes the random values and takes the mod5 so it returns values between 0 and 4
			*cardType = CardsAllow[temp];//set the card type to the random allowable string 
		}
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "\nError allocating memory in Cards non default constructor";
	}
	
}

Card::Card()//currently creates any type of card without looking at limit of cards allowed
{
	try
	{
		cardType = new std::string();
		srand((unsigned)time(NULL));//seeds the rand function based on the time
		int temp = (int)rand() % 5;//takes the random values and takes the mod5 so it returns values between 0 and 4
		*cardType = CardsAllow[temp];//set the card type to the random allowable string 
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "\nError allocating memory in Cards non default constructor";
	}
}

Card::~Card()//destructor 
{
	delete cardType;
}

Card& Card::operator=(const Card &orig) {//overloads the equals sign for the Card class
	if (&orig != this) {
		delete cardType;
		cardType = new std::string(*orig.cardType);	
	}
	return *this;
}
Card::Card(const Card& orig) {//copy constructor
	cardType = new std::string(*orig.cardType);
}

std::string Card::getCardType()//getter
{
	return *cardType;
}
void Card::setCardType(std::string s)//setter
{
	cardType = new std::string();
	bool correct = false;
	for (int i = 0; i < 5; i++) {//loops through the strings allowed for Card types
		std::string p = CardsAllow[i];
		if ((p.compare(s)) == 0) { correct = true; }//if the string is allowed changes the boolean to true
	}
	if (correct)
	{
		*cardType = s;
	}
	else {
		std::cout << "incorrect card type, ignoring the change the  type " << s << " is not a valid type \n";
	}
}

void Card::play()//to do fill it in such that it fills the order list
{
	
	
	
	std::string cardType = getCardType();
	Order myOrder;

	//myOrder = new Order();


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

void Card::printCard()
{
	std::cout << "the card type is: " << getCardType() << "\n";
}

//Deck functions-------------------------------------------------------------------------------
Deck::Deck()//default constructor
{
	for (int i = 0; i < 5; i++) {
		amountAllow[i] = defaultAmountAllow[i];
	}
	std::string tempString;
	Card* tempCard;
	for (int i = 0; i < amountAllow[0]; i++) {
		tempCard = new Card();
		tempString = CardsAllow[0];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < amountAllow[1]; i++) {
		tempCard = new Card();
		tempString = CardsAllow[1];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < amountAllow[2]; i++) {
		tempCard = new Card();
		tempString = CardsAllow[2];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < amountAllow[3]; i++) {
		tempCard = new Card();
		tempString = CardsAllow[3];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < amountAllow[4]; i++) {
		tempCard = new Card();
		tempString = CardsAllow[4];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
}

Deck::Deck(int nbomb = 3, int nreinforcement = 3, int nblockade = 3, int nairlift = 3, int ndiplomacy = 3)//constructor
{
	if (nbomb<0) { nbomb = defaultAmountAllow[0]; }
	amountAllow[0] = nbomb;
	if (nreinforcement<0) { nreinforcement = defaultAmountAllow[1]; }
	amountAllow[1] = nreinforcement;
	if (nblockade<0) { nblockade = defaultAmountAllow[2]; }
	amountAllow[2] = nblockade;
	if (nairlift<0) { nairlift = defaultAmountAllow[3]; }
	amountAllow[3] = nairlift;
	if (ndiplomacy <0) { ndiplomacy = defaultAmountAllow[4]; }
	amountAllow[4] = ndiplomacy;

	std::string tempString;
	Card* tempCard = new Card();
	//Populating the cards in the deck
	for (int i = 0; i < nbomb; i++) {
		tempCard = new Card();
		tempString = CardsAllow[0];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < nreinforcement; i++) {
		tempCard = new Card();
		tempString = CardsAllow[1];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < nblockade; i++) {
		tempCard = new Card();
		tempString = CardsAllow[2];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < nairlift; i++) {
		tempCard = new Card();
		tempString = CardsAllow[3];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
	for (int i = 0; i < ndiplomacy; i++) {
		tempCard = new Card();
		tempString = CardsAllow[4];
		tempCard->setCardType(tempString);
		deckCards.push_back(tempCard);
	}
}

Deck::~Deck()//destructor
{
	for (auto&& x : deckCards) {
		delete x;
	}
}

Deck& Deck::operator=(const Deck &orig) {//overloading the equals operator
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


Deck::Deck(const Deck& orig) {//copy constructor
	for (auto && x : orig.deckCards) {
		deckCards.push_back(new Card(*x));
	}
}

void Deck::Draw(Hand& handID)//draws a random card
{
	int currentDeckSize = deckCards.size();
	srand((unsigned)time(NULL));
	int temp = (int)rand() % currentDeckSize;
	handID.addCard(deckCards.at(temp));
	deckCards.erase(deckCards.begin() + temp);
}

void Deck::returnCard(Card* cardId)//currently allows returns of cards from else where
{
	deckCards.push_back(cardId);
}

void Deck::printDeck()//prints how many of each type the deck contains
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
void Deck::addCard()//adds a random card to the Deck
{
	std::string tempString;
	Card* tempCard;
	tempCard = new Card();
	deckCards.push_back(tempCard);
}
void Deck::addCard(std::string cardID)//adds a specific card to the Deck
{
	std::string tempString;
	Card* tempCard;
	tempCard = new Card(cardID);
	deckCards.push_back(tempCard);
}

//Hand functions-------------------------------------------------------------------------------
Hand::Hand()//default constructor
{
	//do nothing hand starts empty
}

Hand::~Hand()//destructor
{
	for (auto&& x : handCards) {
		delete x;
	}
}
Hand& Hand::operator=(const Hand &orig)//overloads the equals operator
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

Hand::Hand(const Hand& orig)//copy constructor
{
	for (auto && x : orig.handCards) {
		handCards.push_back(new Card(*x));
	}
}

void Hand::addCard(Card* cardID)//adds a card to the hands card vector
{
	handCards.push_back(cardID);
}

void Hand::removeCard(Card* cardID)//removes a card to the hands card vector
{
	int temp = 0;
	for (auto&& x : handCards) {
		if (x == cardID) { break; }
		temp++;
	}
	handCards.erase(handCards.begin() + temp);
}

std::string Hand::play(std::string cardType, Deck& deckId)
{
	if (isInHand(cardType))//check if the type card is in hand  
	{
		Card* tempCardP = nullptr;
		for (auto&& x : handCards) {
			if (x->getCardType().compare(cardType) == 0) { tempCardP = x; break; }
		}
		if (tempCardP != nullptr) {
			tempCardP->play();
			deckId.returnCard(tempCardP);
			removeCard(tempCardP);
		}
	}
	else {
		std::cout << cardType << " is not in this hand to play\n";
	}

	return cardType;
}
bool Hand::isInHand(std::string cardType)
{
	for (auto&& x : handCards) {
		if (x->getCardType().compare(cardType) == 0) { return true; }
	}
	return false;
}

void Hand::printHand()//prints the type of cards in the hand
{
	std::cout << "the hand contains the following cards:\n";
	int cardInHand[5] = { 0 };
	for (auto && x : handCards) {
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
	std::cout << "\nList of commands:\n";
	std::cout << "For Deck: \nDraw(Hand handID): draws a card and adds it to the Hand HandID,\nreturnCard(Card* cardId): returns a card to the deck, \nprintDeck(): prints the types of cards in the deck\naddCard(): adds a random card to the Deck\naddCard(string cardID);//adds the specified card type to the Deck\n";
	std::cout << "\nFor Hand: \naddCard(Card* cardID): adds card to hand,\nremoveCard(Card* cardID): removes card from Hand,\nplay(string cardType, Deck deck): plays card type and returns played card to deck,\nisInHand(string cardType): check if card type is in hand returns a boolean value,\n;printHand() prints the contents of the hand\n";
}