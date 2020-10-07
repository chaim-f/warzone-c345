using namespace std;
#include <list>

class Order {

public:
    Order();
    bool validate();
    bool execute();

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

    void move(Order order);

    Order Delete(Order order);

    void add(Order order);

};


