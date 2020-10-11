using namespace std;
#include <vector>
#include <iostream>
#include <list>


class Order {
    
    string name;

public:    
    Order();
    bool validate();
    bool execute();
    void setName(string n);
    string getName();
    friend std::ostream& operator<<(std::ostream&, const Order);
    bool operator== (Order o1);

};



//Subclasses deploy, advance, bomb, blockade, airlift, and negotiate.
class Deploy : public Order {

public:
    Deploy();
   
};
class Advance : public Order {
  
public:
    Advance();

};
class Bomb : public Order {

public:
    Bomb();
};
class Blockade : public Order {
    
public:
    Blockade();
};
class Airlift : public Order {
    
public:
    Airlift();
};
class Negotiate : public Order {
    
public:
    Negotiate();
};



class Orderlist {

    list <Order> orderList;

public:
    
    Orderlist();

    void move(Order insertOrder, Order destinationOrder);

    Order remove(Order order);

    void add(Order order);

    friend std::ostream& operator<<(std::ostream&, const Orderlist);


};


