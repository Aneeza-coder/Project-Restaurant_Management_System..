#include "Order.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

const string ORDER_FILE="C:\\Users\\Hp\\Desktop\\Filehandling\\Orders.csv";

void placeOrder(vector<Order>& orders)
{
	orders.clear();
	ifstream f(ORDER_FILE.c_str());
	if(!f)
	return;
	string line, a,b,c;
	while(getline(f,line))
	{
		Order o;
		stringstream ss(line);
		getline(ss,a,',');
		o.orderId=atoi(a.c_str());
		getline(ss,b,',');
		o.customerId=atoi(b.c_str());
		getline(ss,c);
		
		stringstream is(c);
		while (getline(is,a,'|'))
		o.itemIds.push_back(atoi(a.c_str()));
		orders.push_back(o);
    } 		
}

void saveOrders(const vector<Order>& orders)
{
    ofstream f(ORDER_FILE.c_str());
    for(int i=0; i<(int)orders.size(); i++)
    {
    	f<<orders[i].orderId<<","<<orders[i].customerId<<",";
    	for(int j=0; j<(int)orders[i].itemIds.size(); j++)
    	{
    		f<<orders[i].itemIds[j];
    		if(j+1<(int)orders[i].itemIds.size()) f<<"|";
		}
		f<<endl;
	}
}
	
void addOrder(vector<Order>& orders)
{
    Order o;
    int itemId;
    char more;
	cout<<"Enter Order ID: ";
	cin>>o.orderId;
	
	cout<<"Enter Customer ID: ";
	cin>>o.customerId;
	
	do
	{
		cout<<"Enter menu Item ID: ";
		cin>>itemId;
		o.itemIds.push_back(itemId);
		cout<<"Add more items?(y/n)";
		cin>>more;
	}
	while(more == 'y'|| more =='Y');
	orders.push_back(o);
}

void showOrders(const vector<Order>& orders)
{
    for (int i = 0; i < (int)orders.size(); i++)
    {
        cout << i + 1 << ") " << orders[i].orderId
             << " | " << orders[i].customerId << " | ";
        for (int j = 0; j < (int)orders[i].itemIds.size(); j++)
            cout << orders[i].itemIds[j] << " ";
        cout << endl;
    }
}

void deleteOrder(vector<Order>& orders)
{
    int c; 
	showOrders(orders);
    cout << "Delete "; 
	cin >> c;
    if (c > 0 && c <= (int)orders.size())
        orders.erase(orders.begin() + c - 1);
}    
