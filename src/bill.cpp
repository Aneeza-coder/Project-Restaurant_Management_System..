#include <iostream>
#include "bill.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

const string BILL_FILE = "C:\\Users\\Hp\\Desktop\\Filehandling\\Bill.csv";

void loadBills(vector<Bill>& bills)
{
    bills.clear();
    ifstream file(BILL_FILE.c_str());

    if (!file)
        return;

    string line;
    while (getline(file, line))
    {
        string billId, orderId, totalAmount;
        stringstream ss(line);

        getline(ss, billId, ',');
        getline(ss, orderId, ',');
        getline(ss, totalAmount, ',');

        Bill b;
        b.billId = atoi(billId.c_str());
        b.orderId = atoi(orderId.c_str());
        b.totalAmount = atof(totalAmount.c_str());

        bills.push_back(b);
    }

    file.close();
}

void saveBills(const vector<Bill>& bills)
{
    ofstream file(BILL_FILE.c_str());

    for (size_t i = 0; i < bills.size(); i++)
    {
        const Bill& b = bills[i];
        file << b.billId << ","
             << b.orderId << ","
             << b.totalAmount << endl;
    }

    file.close();
}

void addBill(vector<Bill>& bills)
{
    Bill b;

    cout << "Enter Bill ID: ";
    cin >> b.billId;

    cout << "Enter Order ID: ";
    cin >> b.orderId;

    cout << "Enter Total Amount: ";
    cin >> b.totalAmount;

    bills.push_back(b);
    cout << "Bill added successfully!\n";
}

void showBills(const vector<Bill>& bills)
{
    if (bills.empty())
    {
        cout << "No bills found!\n";
        return;
    }

    cout << "\n--- BILL LIST ---\n";
    for (int i = 0; i < bills.size(); i++)
    {
        cout << i + 1
             << ". Bill ID: " << bills[i].billId
             << " | Order ID: " << bills[i].orderId
             << " | Total Amount: " << bills[i].totalAmount
             << endl;
    }
}

void updateBill(vector<Bill>& bills)
{
    showBills(bills);

    int choice;
    cout << "Select bill number to update: ";
    cin >> choice;

    if (choice < 1 || choice > bills.size())
    {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "Enter new Order ID: ";
    cin >> bills[choice - 1].orderId;

    cout << "Enter new Total Amount: ";
    cin >> bills[choice - 1].totalAmount;

    cout << "Bill updated successfully!\n";
}

void deleteBill(vector<Bill>& bills)
{
    showBills(bills);

    int choice;
    cout << "Select bill number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > bills.size())
    {
        cout << "Invalid choice!\n";
        return;
    }

    bills.erase(bills.begin() + choice - 1);
    cout << "Bill deleted successfully!\n";
}

double calculateBill(const Order& order, const vector<Menu>& menu)
{
    double total = 0.0;
    for(int i = 0; i < (int)order.itemIds.size(); i++)
    {
        int id = order.itemIds[i];
        for(int j = 0; j < (int)menu.size(); j++)
        {
            if(menu[j].id == id)
            {
                total += menu[j].price;
                break;
            }
        }
    }
    return total;
}