#include <iostream>
using namespace std;
#include <string>
#include "OrderItem.h"
#include "Menu.h"
#pragma once
class Order
{
	string customername;
	int orderID;
	int num_of_orderitems;
	OrderItem *items;
	Menu *menu;
	static int countorder;

public:
	Order(Menu *men);

	void set_numoforderit(int n);

	void add_orderitem(int i);

	void readinfo();

	void displayinfo();

	double calculateTotalCost();

	void set_orderid(int id);

	double prepationtime();

	int set_orderid();

	Menu* get_menu();

	string get_customername();

	~Order(void);
};

