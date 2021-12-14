#include "OrderItem.h"
#include <iostream>
using namespace std;

OrderItem::OrderItem()
{
	numofmeals=0;
	recipe=NULL;
}


void OrderItem::set_recipe(Recipe *re)
{
	if(recipe==NULL)
	recipe=re;
}

Recipe* OrderItem::get_recipe()
{
	if(recipe!=NULL)
	{
		return recipe;
	}
	return NULL;
}


void OrderItem:: set_numofmeals(int num)
{
	numofmeals=num>0?num:0;
}



int OrderItem:: get_numofmeals()
{
	return numofmeals;
}


void OrderItem::readinfo(Menu *a)
{
	int num,ID;
	cout<<"Recipe ID : ";
	cin>>ID;
	set_recipe(a->get_recipe(ID));
	cout<<"Number of meals : ";
	cin>>num;
	set_numofmeals(num);
}


OrderItem::~OrderItem(void)
{
}
