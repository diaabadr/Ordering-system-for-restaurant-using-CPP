#include "Menu.h"


Menu::Menu(void)
{
	chefName=" ";
	curr_num=0;
	numberofRecipes=0;
	RecipeList=NULL;
}


void Menu :: set_chefname(string n)
{
	chefName=n;
}


string Menu::get_chefname ()
{
	return chefName;
}


void Menu::set_numofrecipes(int n)
{
	numberofRecipes=n>0?n:0;
	if(n!=0&&RecipeList==NULL)
	{
		RecipeList=new Recipe*[numberofRecipes];
	}
}


int Menu:: get_numofrecipes()
{
	return numberofRecipes;
}


bool Menu:: addRecipe()
{
	if(curr_num!=numberofRecipes)
	{
		RecipeList[curr_num]=new Recipe;
		RecipeList[curr_num]->readinfo();
		curr_num++;
		return true;
	}
	return false;
}


void Menu::readinfo()
{
	string n;
	int num;
	cout <<"Time to prepare the Menu !!"<<endl<<endl;
	cout<<"Please Enter the Chef's Name :  ";
	cin>>n;
	set_chefname(n);

	cout<<"Please Enter the Number of Recipes :  ";
	cin>>num;
	set_numofrecipes(num);
	cout <<"________________________________________________________________"<<endl<<endl;
	cout<<"Let's add the Recipes ...."<<endl;
	cout <<"________________________________________________________________"<<endl<<endl;
	for(int i=0;i<numberofRecipes;i++)
	{
		cout<<"For Recipe #"<<i+1<<" Please Enter the following : "<<endl;
		addRecipe();
		cout<<endl;
	}
	cout <<"________________________________________________________________"<<endl<<endl;
}


void Menu::displayinfo()
{
	cout <<"_______________________________________________________________"<<endl<<endl;
	cout<<"------"<<" Chef "<<chefName<<"'s Menu ------"<<endl;
	cout <<"________________________________________________________________"<<endl<<endl;
	for(int i=0;i<numberofRecipes;i++)
	{
		RecipeList[i]->displayinfo();
	}
	cout <<"________________________________________________________________"<<endl<<endl;
}


Recipe* Menu::get_recipe(int id)
{	
	for(int i=0;i<numberofRecipes;i++)
	{
		if(id==RecipeList[i]->getID())
		{
			return RecipeList[i];
		}
	}
	return NULL;
}


Menu::~Menu(void)
{
		delete []RecipeList;
}
