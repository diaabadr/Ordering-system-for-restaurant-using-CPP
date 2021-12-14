#include "Recipe.h"
#include <iostream>
using namespace std;
int Recipe:: count = 0;
Recipe::Recipe(void)
{
	count++;
	set_id(count);
	costpermeal=0;
	preparation_time=0;
		
	
}


void Recipe::set_costpermeal(double c)
{
	costpermeal=c>0?c:0;

}


void Recipe::set_id(int id)
{
	RecipeID=id>0?id:0;
}

double Recipe::get_costpermeal()
{
	return costpermeal;
}


Recipe::Recipe(string n,double p,double c)
{
	name=n;
	set_preparationtime(p);
	set_costpermeal(c);
}


void Recipe::set_preparationtime(double p)
{
	preparation_time=p>0?p:0;
}


double Recipe::get_preparationtime()
{
	return preparation_time;
}


void Recipe::set_name(string n)
{
	name=n;
}


string Recipe::getname()
{
	return name;
}


int Recipe::getID()
{
	return RecipeID;
}


void Recipe::readinfo()
{
	double cost,time;
	char n[20];

	cout<<"Name : ";
	cin>>n;
	set_name(n);

	cout<<"Preparation time (Minutes) : ";
	cin>>time;
	set_preparationtime(time);

	cout<<"Cost : $";
	cin>>cost;
	set_costpermeal(cost);
}


void Recipe::displayinfo()
{
	cout<<"Recipe : "<<name<<endl;
	cout<<"ID : "<<RecipeID;
	cout<<",  Preparation time : "<<preparation_time<<" Minute";
	cout<<",  Cost per meal : $"<<costpermeal<<endl;
}

Recipe::~Recipe(void)
{
}
