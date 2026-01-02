#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct Customer
{
    int id;
    string name;
    string phone;
    string address;

};

void loadCustomers(vector<Customer>& customers);
void saveCustomers(const vector<Customer>& customers);
void addCustomer(vector<Customer>& customers);
void showCustomers(const vector<Customer>& customers);
void updateCustomer(vector<Customer>& customers);
void deleteCustomer(vector<Customer>& customers);

#endif