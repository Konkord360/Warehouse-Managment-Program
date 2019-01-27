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
	cleanUpInWarehouse = '4',
	checkExpirationDatesOfProducts = '5',
	addProduct = '6',
	removeProduct = '7',
	closeWarehousemanEnum = '8'
};

enum customerMenuEnum {
	makeOrder = '1',
	cancelOrder = '2',
	closeCustomerMenu = '3'
};

class CommunicationManagement {
	char userInput;
public:
	char getUserInput();
    void viewMainMenu();
	void viewWarehousemanMenu();
	void viewCustomerMenu();
	void handleWarehousemanMenuChoice();
	void handleCustomerMenuChoice();
	void viewWarehouseStock();
	void displayList(ProductList& productList);
	void getInfoAboutOrder(ProductList& productList);
};