#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "menu.h"
using namespace std;
const string MENU_FILE="C://Users//Hp//Desktop//Filehandling//Menu.csv";

void loadMenu(vector<Menu>& menu)
{
	menu.clear();
	ifstream file(MENU_FILE.c_str()); 
	if(!file)
	return;
	string line;
	while(getline(file,line))
	{
		if(line.empty())
		continue;
		string name,price;
		stringstream ss(line);
		if(!getline(ss,name,','))
		continue;
		if (!getline(ss,price))
		continue;
		{
			Menu item;
			item.name=name;
			item.price=atof(price.c_str());
			if(item.price>0)
			menu.push_back(item);
		}
	}
}
void saveMenu(const vector<Menu>& menu)
{
    ofstream file(MENU_FILE.c_str());  

	for(int i=0; i<menu.size(); i++)
	{
    file << menu[i].name << "," << menu[i].price<<"\n";
    }
}
void addItem(vector<Menu>& menu)
{
	Menu item;
	cin.clear();
	cin.ignore(1000,'\n');
	cout<<"Enter item name: ";
	getline(cin,item.name);
	cout<<"Enter price: ";
	cin>>item.price;
	menu.push_back(item);
	cout<<"Item added!\n";
}
void displayMenu(const vector<Menu>& menu)
{
	if(menu.empty())
	{
		cout<<"Menu is empty\n";
		return;
	}
	cout<<"\n-----Menu----\n";
	int i=1;
    for (int j = 0; j < menu.size(); j++)
    {
    cout << i << " . " << menu[j].name<< " - " << menu[j].price << "\n";
    i++;
    }

}
void updateMenu(vector<Menu>& menu)
{
	if(menu.empty())
	{
		cout<<"Menu is empty\n:";
		return;
	}

	displayMenu(menu);
	int i;
	cout<<"Enter Item number to update: ";
	cin>>i;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1000,'\n');
		cout<<"Invalid Input\n";
		return;
	}
	if(i<1 || i > (int)(menu.size()))
	{
		cout<<"Invalid number item!\n";
		return;
	}
	cin.ignore();
	cout<<"Enter new name: ";
	getline(cin, menu[i-1].name);
	cout<<"Enter new price:";
	cin>>menu[i-1].price;
	cout<<"item updated successfully\n";
}
void deleteItem(vector<Menu>& menu)
{
	displayMenu(menu);
	int i;
	cout<<"Enter Item number to delete: "; cin>>i;
	if(i<1 || i>(int)(menu.size()))
	{
		cout<<"Invalid!\n";
		return;		
	}
	menu.erase(menu.begin()+i-1);
	cout<<"Deleted!\n";
}
void readMenu(const vector<Menu>& menu)
{
	ifstream file(MENU_FILE.c_str());  

	if(!file)
	{
		cout<<"No such file!\n";
		return;
	}
	string line;
	int i=1;
	cout<<"\n-----Menu----\n";
	while(getline(file,line))
	{
		string name,price;stringstream ss(line);
		if(getline(ss,name,',')&& getline(ss,price))
		cout<<i++<<". "<<name<<" - "<<price<<"\n";	
	}
}
