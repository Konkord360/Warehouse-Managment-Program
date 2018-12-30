#include <iostream>
#include "View.h"
#include "WarehouseSide.h"

int main() {
	CommunicationManagement communicationManager;
	Warehouseman warehouseman;
	ProductList productList;

	while (communicationManager.getUserInput() != end) {
		communicationManager.viewMainMenu();

		switch (communicationManager.getUserInput())
		{
		case '1': 
			communicationManager.viewWarehousemanMenu();

			switch (communicationManager.getUserInput()) {
			case replenishReserve:
				break;
			case checkStockOfProducts:
				break;
			case reciveDelivery:
				break;
			case cleanUpInWarehouse:
				break;
			case checkExpirationDatesOfProducts:
				break;
			case addProduct:
				productList.addProduct();
				break;
			case removeProduct:
				break;
			case closeWarehousemanEnum:
				break;
			}
					
			break;
		case '2': communicationManager.viewCustomerMenu();
			break;
		default:
			break;
		}
	}
	return 0;
}