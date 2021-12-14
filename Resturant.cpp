#include "Resturant.h"


Resturant::Resturant(Menu *men)
{
	menu=men;
	orders=new Order*[100000];
	num_oforders=0;

}


void Resturant::select_event()
{
	int i;
	while(true)
	{
		cout<<"Do you want to ... "<<endl;
		cout <<"         <1> View the menu?"<<endl;
		cout <<"         <2> Make an order?"<<endl;
		cout <<"         <3> View orders?"<<endl;
		cout <<"         <4> Serve an order?"<<endl;
		cout <<"         <5> Exit?"<<endl;	
		cout<<"Enter your choice : ";
		cin>>i;
		if(i==1)
			viewmenu();
		if(i==2)
			addorder();
		if(i==3)
			vieworders();
		if(i==4)
			serveorder();
		if(i==5)
		{
			cout <<"________________________________________________________________"<<endl<<endl;
			cout<<"Ending the program ......."<<endl;
			cout <<"________________________________________________________________"<<endl<<endl;
			break;
		}
	}
}


void Resturant::addorder()
{
	orders[num_oforders]=new Order(menu);
	orders[num_oforders]->readinfo();
	orders[num_oforders]->displayinfo();
	num_oforders++;
}


void Resturant::vieworders()
{
	bool check=false;
	for(int i=0;i<num_oforders;i++)
	{
		if(orders[i]!=NULL)
		{
			orders[i]->displayinfo();
			check=true;
		}
	}
	if(!check)
	{
		cout <<"________________________________________________________________"<<endl<<endl;
		cout<<"You don't have bending orders"<<endl;
		cout <<"________________________________________________________________"<<endl<<endl;
	}
}

void Resturant::serveorder()
{
	int id;bool check=false;
	cout <<"________________________________________________________________"<<endl<<endl;
	cout<<"Please enter the order ID : ";
	cin>>id;
	if(orders[id-1]!=NULL)
	{
	cout<<"Serving Order #"<<id<<" for Customer "<<orders[id-1]->get_customername()<<endl;
	cout <<"________________________________________________________________"<<endl<<endl;
	check=true;
	delete orders[id-1];
	orders[id-1]=NULL;
	}
	if(!check)
		cout<<"You don't have bending orders"<<endl;
}


void Resturant::viewmenu()
{
	menu->displayinfo();
}






Resturant::~Resturant(void)
{
	for(int i=0;i<num_oforders;i++)
	{
		delete orders[i];
	}
	delete[]orders;
}
