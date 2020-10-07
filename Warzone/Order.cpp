#include "Order.h"
#include <iostream>
#include <fstream>

Order::Order() {};

bool Order::validate() { return true; };
bool Order::execute() { return validate(); };

Deploy::Deploy() { cout << "Created a deploy order\n"; };

Advance::Advance() { cout << "Created an advance order\n"; };

Bomb::Bomb() { cout << "Created a bomb order\n"; };

Blockade::Blockade() { cout << "Created a blockade order\n"; };

Airlift::Airlift() { cout << "Created an airlift order\n"; };

Negotiate::Negotiate() { cout << "Created a negotiate order\n"; };

Orderlist::Orderlist() { };

void Orderlist::add(Order order) {

	orderList.push_back(order);
		
}

Order Orderlist::Delete(Order order) {
	//TODO
	//Find order in list and delete then return
	return order;
}

void Orderlist::move(Order order) {
	//TODO
}
