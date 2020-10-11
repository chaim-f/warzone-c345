#include "Order.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <list>

Order::Order() { setName("Order"); };

bool Order::validate() { return true; };
bool Order::execute() { return validate(); }
void Order::setName(string n) { name = n;}
string Order::getName() { return name; }

bool Order::operator== (Order o1)
{
    return (getName() == o1.getName() );
}


std::ostream& operator<<(std::ostream& strm, Order t)
{
	return strm << t.name;
};

Deploy::Deploy() { 
	setName("Deploy");
	cout << "Created a deploy order\n"; };

Advance::Advance() { 
	setName("Advance");
	cout << "Created an advance order\n"; };

Bomb::Bomb() { 
	setName("Bomb");
	cout << "Created a bomb order\n"; };

Blockade::Blockade() { 
	setName("Blockade");
	cout << "Created a blockade order\n"; };

Airlift::Airlift() { 
	setName("Airlift");
	cout << "Created an airlift order\n"; };

Negotiate::Negotiate() { 
	setName("Negotiate");
	cout << "Created a negotiate order\n"; };

Orderlist::Orderlist() { };

void Orderlist::add(Order order) {

	orderList.push_back(order);
		
}

Order Orderlist::remove(Order order) {
	//TODO

	for (auto it = orderList.begin(); it != orderList.end(); it++)
		if (*it == order) {
			orderList.erase(it);
			return order;
		}
	
	return order;

}


void Orderlist::move(Order insertOrder, Order destinationOrder) {
	//TODO

	auto insert = std::find(orderList.begin(), orderList.end(), insertOrder);
	
	auto destination = std::find(orderList.begin(), orderList.end(), destinationOrder);

	orderList.splice(destination, orderList, insert);

}

std::ostream& operator<<(std::ostream& strm, Orderlist t)
{	
	
	for (auto it = t.orderList.begin(); it != t.orderList.end(); it++)
		strm << *it << " ";
	
	return strm;
};

