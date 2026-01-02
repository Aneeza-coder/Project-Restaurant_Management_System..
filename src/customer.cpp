#include <iostream>
#include "customer.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

const string CUSTOMER_FILE="C:\\Users\\Hp\\Desktop\\Filehandling\\Customer.csv";

void loadCustomers(vector<Customer>&customers)
{
    customers.clear();
    ifstream file(CUSTOMER_FILE.c_str());
    
    if(!file)
        return;
        
    string line;
    while(getline(file,line))
    {
        string id, name, phone, address;
        stringstream ss(line);
        
        getline(ss,id, ',');
        getline(ss,name,',');
        getline(ss,phone,',');
        getline(ss,address,',');
        
        Customer c;
        c.id = atoi(id.c_str());
        c.name = name;
        c.phone = phone;
        c.address = address;
        
        customers.push_back(c);
        
    }
    
    file.close();
    
}

void saveCustomers(const vector<Customer>&customers)
{
    ofstream file(CUSTOMER_FILE.c_str());
    
    for(size_t i=0; i<customers.size(); i++)
    {
       const Customer& c=customers[i];
	   file << c.id << "," 
         << c.name << ","
         << c.phone << ","
         << c.address << endl;
    }
    
    file.close();
    }
    
    void addCustomer(vector<Customer>&customers)
    {
        Customer c;
        
        cout << "Enter Customer ID: ";
        cin >> c.id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, c.name);
        
        cout << "Enter Phone: ";
        getline(cin, c.phone);
        
        cout << "Enter Address: ";
        getline(cin, c.address);
        
        customers.push_back(c);
        cout << "Customer added successfully!\n";
    }
    
    void showCustomers(const vector<Customer>& customers)
    {
    if (customers.empty())
    {
        cout << "No customers found!\n";
        return;
    }

    cout << "\n--- CUSTOMER LIST ---\n";
    for (int i = 0; i < customers.size(); i++)
    {
        cout << i+1 << ". ID: " << customers[i].id
             << " | Name: " << customers[i].name
             << " | Phone: " << customers[i].phone
             << " | Address: " << customers[i].address
             << endl;
    }
}

void updateCustomer(vector<Customer>& customers)
{
    showCustomers(customers);
    
    int choice;
    cout << "Select customer number to update: ";
    cin >> choice;

    if (choice < 1 || choice > customers.size())
    {
        cout << "Invalid choice!\n";
        return;
    }
    
    cin.ignore();
    cout << "Enter new name: ";
    getline(cin, customers[choice - 1].name);

    cout << "Enter new phone: ";
    getline(cin, customers[choice - 1].phone);

    cout << "Enter new address: ";
    getline(cin, customers[choice - 1].address);
    
    cout << "Customer updated successfully!\n";
}

void deleteCustomer(vector<Customer>& customers)
{
    showCustomers(customers);
    
    int choice;
    cout << "Select customer number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > customers.size())
    {
        cout << "Invalid choice!\n";
        return;
    }
    
    customers.erase(customers.begin() + choice - 1);
    cout << "Customer deleted successfully!\n";

}