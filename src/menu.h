#ifndef MENU_H
#define MENU_H
#include<string>
#include<vector>

using namespace std;
struct Menu
{
    int id;  
	int price;         
    string name;       
    double prize;      
};

void loadMenu(vector<Menu>& menu); 
void readMenu(const vector<Menu>& menu);   
void displayMenu(const vector<Menu>& menu);
void deleteItem(vector<Menu>& menu);
void updateMenu(vector<Menu>& menu);
void addItem(vector<Menu>& menu);   
void saveMenu(const vector<Menu>& menu); 

#endif
