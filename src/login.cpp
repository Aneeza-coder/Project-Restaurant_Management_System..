#include<iostream>
#include<string>
#include "login.h"
using namespace std;
bool login(const string& role)

{
	string username,password;
	
	cout<<"\nEnter "<<role<<"Username: ";
	
	cin>>username;
	
	cout<<"Enter "<<role<<"Password: ";
	
	cin>>password;
	
	if(role=="Admin")
	{
		if(username=="Admin" && password=="1234")
		return true;
	}
	else if(role=="Customer")
	{
		if(username=="staff" && password=="abcd")
		return true;
	}
	
	return false;
}
