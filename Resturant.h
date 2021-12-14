#include "Order.h"
#include "Menu.h"
#pragma once
class Resturant
{
	Menu *menu;
	Order **orders;
	int num_oforders;
public:
	Resturant(Menu *men);

	void addorder();
	
	void viewmenu();

	void vieworders();

	void serveorder();

	void select_event();

	~Resturant(void);
};

