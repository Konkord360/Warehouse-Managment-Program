#pragma once
#include <iostream>
#include "WarehouseSide.h"
enum mainMenuEnum {
	viewWarehousemanMenu = '1',
	viewCustomerMenu = '2',
	end = '3'
};

enum warehousemanEnum {
	replenishReserve = '1',
	checkStockOfProducts = '2',
	reciveDelivery = '3',
	addProduct = '4',
	removeProduct = '5',
	closeWarehousemanEnum = '6'
};

enum customerMenuEnum {
	makeOrder = '1',
	reciveOrder = '2',
	cancelOrder = '3',
	closeCustomerMenu = '4'
};

class CommunicationManagement {
	char userInput;
public:
	char getUserInput();
	void setUserInput(char input);
    void viewMainMenu();
	void viewWarehousemanMenu();
	void viewCustomerMenu();
	void displayList(ProductList& productList);
	void displayOrderedItems(ProductList& productList);
};