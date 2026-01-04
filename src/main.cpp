#include<iostream>
#include <vector>
#include "menu.h"
#include <cstdlib>
#include "customer.h"
#include "login.h"
#include "Order.h"
using namespace std;

int main()
{
	vector<Menu> menu;
	vector<Customer> customers;
	vector<Order> orders;
	
	int loginChoice;
	
	cout<<"Please select your role to login:\n";
	cout<<"2.Administator\n ";
	cout<<"2.Staff Member\n ";
	cout<<"Enter your choice: ";
	cin>>loginChoice;
	
	bool success=false;
	if (loginChoice==1)
	   success=login("Admin");
	else if (loginChoice==2)
	    success=login("Staff");
	    
	if(!success)
	{
		cout<<"Login failed!";
		return 0;
	}
	
	cout<<"Login successfully!\n ";
	loadMenu(menu);
	loadCustomers(customers);
	
	if(loginChoice==1)
	{
		cout<<"Welcome Admin\n";
		cout<<"You have full acccess to system.\n ";
		cout<<"(Add,Update,Delete menu items and customers)\n\n";
		
	}
	
	else
	{
		cout<<"Welcome Staff!\n";
		cout<<"You have limited access: \n ";
		cout<<"View menu and place order only:\n";
	}
	
	int choice;
	do
	{
		cout<<"\n-----Restaurant Management System----\n";
		cout<<"1.Add Item\n";
		cout<<"2.Show Menu(from menu)\n";
		cout<<"3.Update Item\n";
		cout<<"4.Delete Item\n";
		cout<<"5.Read Menu\n";
		cout<<"6.Add Customer\n";
		cout<<"7.Show Customer\n";
	    cout<<"8.Update Customer\n";
	    cout<<"9.Delete Customer\n";
	    cout<<"10.Place Order\n";
	    cout<<"11.Generate Bill\n";
	    cout<<"12.Exit";
		cout<<"Enter choice:";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				addItem(menu);
				saveMenu(menu);
				break;
			case 2:
				displayMenu(menu);
				saveMenu(menu);
				break;
			case 3:
				updateMenu(menu);
				saveMenu(menu);
				break;
			case 4:
				deleteItem(menu);
				saveMenu(menu);
				break;
			case 5:
				readMenu(menu);
				break;
				
			case 6:
			    addCustomer(customers);
			    saveCustomers(customers);
			    break;
			    
			case 7:
				showCustomers(customers);
				break;
				
		    case 8:
		    	updateCustomer(customers);
		    	saveCustomers(customers);
		    	break;
		    case 9:
			    deleteCustomer(customers);
				saveCustomers(customers);
				break;
				
			case 10:
				placeOrder(orders,menu,customers);
				break;
				
			case 11:
				showBill(orders,menu,customers);
				break;
				
			case 12:
				cout<<"Exiting program";
				break;
			default:
				cout<<"Invalid choice!\n";			
		}	
	}
	while(choice!=12);
	saveMenu(menu);
	saveCustomers(customers);
	return 0;
}

