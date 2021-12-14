#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Recipe.h"
class Menu
{
	string chefName;
	int numberofRecipes,curr_num;
	Recipe **RecipeList;

public:
	Menu(void);


	void set_chefname(string n);

	string get_chefname ();

	void set_numofrecipes(int n);

	int get_numofrecipes();

	bool addRecipe();

	void readinfo();

	void displayinfo();

	Recipe* get_recipe(int id);

	~Menu(void);
};

