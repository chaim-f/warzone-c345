/*COMP 345 A1
  Team 21
*/
using namespace std;
#include <iostream>
#include <list>

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

};



//Deploy
class Deploy : public Order {

    string name;

public:
    Deploy();
    Deploy(const Deploy& o);

    bool validate();
    bool execute();

    Deploy& operator= (const Deploy& o);
   
};

//Advance
class Advance : public Order {
    
    string name;
  
public:
    Advance();
    Advance(const Advance& o);

    bool validate();
    bool execute();

    Advance& operator= (const Advance& o);

};

//Bomb
class Bomb : public Order {

    string name;

public:
    Bomb();
    Bomb(const Bomb& o);

    bool validate();
    bool execute();

    Bomb& operator= (const Bomb& o);
};

//Blockade
class Blockade : public Order {

    string name;
    
public:
    Blockade();
    Blockade(const Blockade& o);

    bool validate();
    bool execute();

    Blockade& operator= (const Blockade& o);
};

//Airlift
class Airlift : public Order {

    string name;
    
public:
    Airlift();
    Airlift(const Airlift& o);

    bool validate();
    bool execute();

    Airlift& operator= (const Airlift& o);
};

//Negotiate
class Negotiate : public Order {

    string name;
    
public:
    Negotiate();
    Negotiate(const Negotiate& o);

    bool validate();
    bool execute();

    Negotiate& operator= (const Negotiate& o);
};


//Orderlist points to a <list> of Order pointers
class Orderlist {

    list <Order*>* orderList;

public:
    
    Orderlist();

    Orderlist(const Orderlist& ol);

    void move(Order* insertOrder, Order* destinationOrder);

    Order remove(Order* order);

    void add(Order* order);

   friend std::ostream& operator<<(std::ostream& strm, const Orderlist& ol);


};


