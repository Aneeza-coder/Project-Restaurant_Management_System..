#ifndef BILL_H
#define BILL_H

#include<iostream>
#include<vector>
#include "order.h"
#include "bill.h"
#include<string>

using namespace std;

struct Bill
{
    int billId;
    int orderId;
    double totalAmount;
};

void loadBill(vector<Bill>& bills);
void saveBill(const vector<Bill>& bills);
void addBill(vector<Bill>& bills);
void showBill(vector <Order>& order);
void updateBill(vector<Bill>& bills);
void deleteBill(vector<Bill>& bills);

#endif