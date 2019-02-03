#include <iostream>
#include <vld.h>
#include "View.h"
#include "WarehouseSide.h"
#include "FileManagment.h"
#include "CustomerSide.h"
#include "Warehouseman.h"

int main() {
	CommunicationManagement communicationManager;
	Warehouseman warehouseman;
	Customer customer;
	CustomerOrder customerOrder;
	CustomerOrderList customerOrderList;
	ProductList listOfProductsAvailableInWarehouse;
	FileManager fileManager;
	std::string produktTest;
	char choice;

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
				break;
			case cleanUpInWarehouse:
				break;
			case checkExpirationDatesOfProducts:
				break;
			case addProduct://wyniesc:)
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				listOfProductsAvailableInWarehouse.addProduct();
				fileManager.write(listOfProductsAvailableInWarehouse);
				listOfProductsAvailableInWarehouse.removeProduct(0);
				break;
			case removeProduct://poprawic i wyniesc
				listOfProductsAvailableInWarehouse.clearList();
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				//if (listOfProductsAvailableInWarehouse.getSize() == 0)
					fileManager.read(listOfProductsAvailableInWarehouse);
				listOfProductsAvailableInWarehouse.removeProduct("gruszka");
				fileManager.rewrite(listOfProductsAvailableInWarehouse);
				break;
			case closeWarehousemanEnum:
				break;
			default:
				break;
			}
			break;
		case '2': 
			communicationManager.viewCustomerMenu();
			switch (communicationManager.getUserInput()) {
			case makeOrder:
				customer.makeOrder(listOfProductsAvailableInWarehouse, customerOrder);
				fileManager.writeOrderToFile(customerOrder);
				customerOrder.getOrderedItems().clearList();
				break;
			case reciveOrder:
				fileManager.readOrdersFromFile(customerOrderList);
				customer.reciveOrder(listOfProductsAvailableInWarehouse, customerOrderList);
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				fileManager.rewrite(listOfProductsAvailableInWarehouse);
				fileManager.rewriteOrdersToFile(customerOrderList);
				break;
			case cancelOrder:
				customer.cancelOrder();
				break;
			case closeCustomerMenu:
				break;
			default:
				break;
			}
			
			break;
		default:
			break;
		}
	}
	return 0;
}