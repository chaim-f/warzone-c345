/*
#include "Order.h"
#include <iostream>

using namespace std;


//COMP 345 A1
//Team 21

int main() {
	
	Orderlist *olist = new Orderlist();

	Airlift *airlift1 = new Airlift();
	Bomb *bomb1 = new Bomb();
	Deploy *deploy1 = new Deploy();
	Advance *adv1 = new Advance();
	Blockade *block1 = new Blockade();
	Negotiate *nego1 = new Negotiate();

	cout << *airlift1 <<"\n";
	
	olist->add(airlift1);
	olist->add(bomb1);
	olist->add(block1);
	olist->add(adv1);
	olist->add(nego1);
	olist->add(deploy1);
	

	cout << *olist << "\n";

	
	olist->move(nego1, block1);

	cout << *olist << "\n";

	Airlift* airlift2 = airlift1;

	olist->add(airlift2);

	cout << *olist << "\n";

	olist->remove(airlift1);

	cout << *olist << "\n";

	
*/
	
