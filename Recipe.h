#include <iostream>
using namespace std;
#include <string>
#pragma once
class Recipe
{
	string name ;
	int RecipeID;
	double preparation_time,costpermeal ;
	static int count;

public:
	Recipe(void);
	Recipe(string n,double p,double c);

	void set_costpermeal(double c);
	double Recipe::get_costpermeal();


	void set_preparationtime(double p);
	double get_preparationtime();


	void set_name(string n);
	string getname();


	void set_id(int id);
	int getID();


	void readinfo();


	void displayinfo();


	~Recipe(void);
};

