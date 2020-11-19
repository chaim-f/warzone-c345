/*COMP 345 A1
  Team 21
*/

class Player;
/*COMP 345 A1
  Team 21
*/

#pragma once
using namespace std;
#include <iostream>
#include <list>

class Player;
class Territory;

//Parents class Order
//Currently has no attributes implemented
class Order {

    string name;

    //Included Copy, Assignment, Outstream
public:
    Order();
    Order(const Order& o);
    bool validate();
    bool execute();
    void setName(string n);
    string getName();
    friend std::ostream& operator<<(std::ostream& strm, Order& o);
    Order& operator= (const Order& o);

    Player* player;
};



//Deploy
class Deploy : public Order {

    string name;

public:
    Deploy();
    Deploy(Player* player, Territory* territory, int army);

    Deploy(const Deploy& o);
    bool validate();
    bool execute();

    Deploy& operator= (const Deploy& o);

    Territory* territory;
    int army;

};

//Advance
class Advance : public Order {

    string name;

public:
    Advance();
    Advance(Player* player,Player* playerB, Territory* myTerritory, Territory* otherTerritory, int army);
    Advance(const Advance& o);

    bool validate();
    bool execute();

    Advance& operator= (const Advance& o);

    Territory* myTerritory;
    Territory* otherTerritory;
    Player* playerB;
    int army;
};

//Bomb
class Bomb : public Order {

    string name;

public:
    Bomb();
    Bomb(const Bomb& o);
    Bomb(Player* player, Territory* otherTerritory);

    bool validate();
    bool execute();

    Bomb& operator= (const Bomb& o);

    Territory* otherTerritory;
};

//Blockade
class Blockade : public Order {

    string name;

public:
    Blockade();
    Blockade(Player* player, Territory* myTerritory);
    Blockade(const Blockade& o);

    bool validate();
    bool execute();

    Blockade& operator= (const Blockade& o);

    Territory* myTerritory;
};

//Airlift
class Airlift : public Order {

    string name;

public:
    Airlift();
    Airlift(Player* player, Territory* fromTerritory, Territory* toTerritory, int army);
    Airlift(const Airlift& o);

    bool validate();
    bool execute();

    Airlift& operator= (const Airlift& o);

    Territory* fromTerritory;
    Territory* toTerritory;
    int army;

};

//Negotiate
class Negotiate : public Order {

    string name;

public:
    Negotiate();
    Negotiate(Player* player, Player* otherPlayer);
    Negotiate(const Negotiate& o);

    bool validate();
    bool execute();

    Negotiate& operator= (const Negotiate& o);

    Player* otherPlayer;
};



//Orderlist points to a <list> of Order pointers
class Orderlist {

    list <Order*> orderList;

public:
    
    Orderlist();

    Orderlist(const Orderlist& ol);

    void move(Order* insertOrder, Order* destinationOrder);

    bool remove(Order* order);

    void add(Order* order);

   friend std::ostream& operator<<(std::ostream& strm, const Orderlist& ol);

   list <Order*> getOrderList();
   ~Orderlist();
   bool OrderListIsEmpty();
};


