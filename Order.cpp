#include "Order.h"

int Order:: countorder=0;
Order::Order(Menu *men)
{
	countorder++;
	set_orderid(countorder);
	items=NULL;
	menu=men;
}


string Order::get_customername()
{
	return customername;
}

void Order::set_orderid(int id)
{
	orderID=id;
}


int Order::set_orderid()
{
	return orderID;
}

void Order::set_numoforderit(int n)
{
	num_of_orderitems=n>0?n:0;
	items=new OrderItem[num_of_orderitems];
}

void Order::add_orderitem(int i)
{
	items[i].readinfo(menu);
}


void Order::readinfo()
{
	string name;
	int num;
	cout <<"________________________________________________________________"<<endl<<endl;
	cout<<"Please enter the Customer name : ";
	cin>>name;
	customername=name;

	cout<<"please enter num of order items : ";
	cin>>num;
	set_numoforderit(num);
	for(int i=0;i<num_of_orderitems;i++)
	{
		add_orderitem(i);
	}
	cout <<"________________________________________________________________"<<endl<<endl;
}


double Order:: calculateTotalCost()
{
	double total=0;
	for(int i=0;i<num_of_orderitems;i++)
	{
		total+=items[i].get_recipe()->get_costpermeal()*items[i].get_numofmeals();
	}
	return total;
}



double Order::prepationtime()
{
	double max=items[0].get_recipe()->get_preparationtime();
	for(int i=0;i<num_of_orderitems-1;i++)
	{
		if(items[i].get_recipe()->get_preparationtime()<items[i+1].get_recipe()->get_preparationtime())
			max=items[i+1].get_recipe()->get_preparationtime();
	}
	return max;

}
void Order::displayinfo()
{
	cout<<"__________________________________________________________________"<<endl;
	cout<<"order #"<<orderID<<" for Customer "<<customername<<endl;
	cout<<"Prepation time : " <<prepationtime()<<" Minutes"<<endl<<endl;
	for(int i=0;i<num_of_orderitems;i++)
	{
		cout<<items[i].get_numofmeals()<<" "<<items[i].get_recipe()->getname()<<"    $"<<items[i].get_recipe()->get_costpermeal()<<"    $"<<items[i].get_recipe()->get_costpermeal()*items[i].get_numofmeals()<<endl;
	}
	cout<<"___________________________________________________________________"<<endl;
	cout<<"Total  $"<<calculateTotalCost()<<endl;
	cout<<"____________________________________________________________________"<<endl;
}


Menu* Order::get_menu()
{
	return menu;
}
Order::~Order(void)
{
}
