#include <iostream>
using namespace std;
#include "Menu.h"
#include "Recipe.h"
#include "Order.h"
#include"OrderItem.h"
#include "Resturant.h"


int main()
{
	Menu me;
	me.readinfo();
	Resturant res1(&me);
	res1.select_event();

}