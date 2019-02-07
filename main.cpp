#include <iostream>
#include <vld.h>
#include "View.h"
#include "WarehouseSide.h"
#include "FileManagment.h"
#include "CustomerSide.h"
#include "Warehouseman.h"
#include "Generators.h"
int main() {
	CommunicationManagement communicationManager;
	Warehouseman warehouseman;
	Customer customer;
	CustomerOrder customerOrder;
	CustomerOrderList customerOrderList;
	ProductList listOfProductsAvailableInWarehouse;
	FileManager fileManager;
	IDGenerator idGenerator;
	ExpirationDateGenerator dateGen;
	std::string produktTest, id, date;

	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfProductsAvailableInWarehouse);

	while (communicationManager.getUserInput() != end) {
		communicationManager.viewMainMenu();

		switch (communicationManager.getUserInput())
		{
		case '1': 
			communicationManager.viewWarehousemanMenu();

			switch (communicationManager.getUserInput()) {
			case replenishReserve:
				warehouseman.replenishReserve();
				break;
			case checkStockOfProducts:
				warehouseman.checkStockOfProducts();
				break;
			case reciveDelivery:
				warehouseman.reciveDelivery();
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				fileManager.read(listOfProductsAvailableInWarehouse);
				break;
			case addProduct:
				warehouseman.addProduct(listOfProductsAvailableInWarehouse);
				break;
			case removeProduct:
				warehouseman.removeProduct(listOfProductsAvailableInWarehouse);
				break;
			case closeWarehousemanEnum:
				break;
			default:
				break;
			}
			communicationManager.setUserInput('0');
			break;
		case '2': 
			communicationManager.viewCustomerMenu();
			switch (communicationManager.getUserInput()) {
			case makeOrder:
				customerOrderList.~CustomerOrderList();
				customer.makeOrder(listOfProductsAvailableInWarehouse, customerOrder);
				fileManager.writeOrderToFile(customerOrder);
				customerOrderList.~CustomerOrderList();
				break;
			case reciveOrder:
				customerOrderList.~CustomerOrderList();
				fileManager.readOrdersFromFile(customerOrderList);
				customer.reciveOrder(listOfProductsAvailableInWarehouse, customerOrderList);
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				fileManager.rewrite(listOfProductsAvailableInWarehouse);
				fileManager.rewriteOrdersToFile(customerOrderList);
				break;
			case cancelOrder:
				customerOrderList.~CustomerOrderList();
				fileManager.readOrdersFromFile(customerOrderList);
				customer.cancelOrder(customerOrderList);
				fileManager.rewriteOrdersToFile(customerOrderList);
				break;
			case closeCustomerMenu:
				break;
			default:
				break;
			}
			communicationManager.setUserInput('0');
			break;
		}
	}
	return 0;
}