#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "menu.h"
#include "customer.h"

struct Order
{
	int orderId;
	int customerId;
	vector<int>itemIds;
};

void placeOrder(vector<Order>& oders);
void saveOrders(const vector<Menu>& menu);
void addOrder(vector<Customer>& customers);
void showOrders(const vector<Order>& order);
void deleteOrder(vector<Customer>& customers);

#endif
