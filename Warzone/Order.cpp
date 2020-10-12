/*COMP 345 A1
  Team 21
*/
#include "Order.h"
#include <iostream>
#include <list>


Order::Order() { setName("Order"); };

Order::Order(const Order& o) {
	name = o.name;
};

bool Order::validate() { return true; };
bool Order::execute() { return validate(); }
void Order::setName(string n) { name = n;}
string Order::getName() { return name; }

Order& Order::operator= (const Order& o) {
	name = o.name;
	return *this;
};


std::ostream& operator<<(std::ostream& strm, Order& o)
{
	return strm << o.getName();
};

//The subclasses have no attributes implemented yet
//As a result the validate and execute are just skeleton functions

//Deploy
Deploy::Deploy() { 
	setName("Deploy");
	cout << "Created a deploy order\n"; };

Deploy::Deploy(const Deploy& o) {
	name = o.name;
};

bool Deploy::validate() { return true; };
bool Deploy::execute() { return validate(); }

Deploy& Deploy::operator= (const Deploy& o) {
	name = o.name;
	return *this;
	};


//Advace
Advance::Advance() { 
	setName("Advance");
	cout << "Created an advance order\n"; };

Advance::Advance(const Advance& o) {
	name = o.name;
};

bool Advance::validate() { return true; };
bool Advance::execute() { return validate(); }

Advance& Advance::operator= (const Advance& o) {
	name = o.name;
	return *this;

};

//Bomb
Bomb::Bomb() { 
	setName("Bomb");
	cout << "Created a bomb order\n"; };

Bomb::Bomb(const Bomb& o) {
	name = o.name;

};


bool Bomb::validate() { return true; };
bool Bomb::execute() { return validate(); }

Bomb& Bomb::operator= (const Bomb& o) {
	name = o.name;
	return *this;

};


//Blockade
Blockade::Blockade() { 
	setName("Blockade");
	cout << "Created a blockade order\n"; };

Blockade::Blockade(const Blockade& o) {
	name = o.name;
};

bool Blockade::validate() { return true; };
bool Blockade::execute() { return validate(); }

Blockade& Blockade::operator= (const Blockade& o) {
	name = o.name;
	return *this;

};

//Airlift
Airlift::Airlift() { 
	setName("Airlift");
	cout << "Created an airlift order\n"; };

Airlift::Airlift(const Airlift& o) {
	name = o.name;
};

bool Airlift::validate() { return true; };
bool Airlift::execute() { return validate(); }

Airlift& Airlift::operator= (const Airlift& o) {
	name = o.name;
	return *this;

};


//Negotiate
Negotiate::Negotiate() { 
	setName("Negotiate");
	cout << "Created a negotiate order\n"; };

Negotiate::Negotiate(const Negotiate& o) {
	name = o.name;
};

bool Negotiate::validate() { return true; };
bool Negotiate::execute() { return validate(); }

Negotiate& Negotiate::operator= (const Negotiate& o) {
	name = o.name;
	return *this;

};


//Orderlist

Orderlist::Orderlist() { orderList = new std::list <Order*>(); };

Orderlist::Orderlist(const Orderlist& ol) {
	orderList = ol.orderList;

}

void Orderlist::add(Order* order) {

	orderList->push_back(order);
		
}

Order Orderlist::remove(Order* order) {
	
	for (auto it = orderList->begin(); it != orderList->end(); it++)
		if (*it == order) {
			orderList->erase(it);
			return *order;
		}
	
	return *order;

}


void Orderlist::move(Order* insertOrder, Order* destinationOrder) {


	auto insert = std::find(orderList->begin(), orderList->end(), insertOrder);
	
	auto destination = std::find(orderList->begin(), orderList->end(), destinationOrder);

	orderList->splice(destination, *orderList, insert);

}


std::ostream& operator<<(std::ostream& strm, const Orderlist& ol)
{	
	for (auto it = ol.orderList->begin(); it != ol.orderList->end(); it++)
		strm << *(*it) << " ";

	return strm;
};


