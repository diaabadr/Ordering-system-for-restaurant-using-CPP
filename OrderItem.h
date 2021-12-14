#include "Recipe.h"
#include "Menu.h"
#pragma once
class OrderItem
{
	Recipe *recipe;
	int numofmeals;
public:
	OrderItem();

	void set_recipe(Recipe *re);

	Recipe* get_recipe();

	void set_numofmeals(int num);

	int get_numofmeals();

	void readinfo(Menu *a);

	~OrderItem(void);
};

