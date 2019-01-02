#include <iostream>
#include "View.h"
#include "WarehouseSide.h"
#include "FileManagment.h"

int main() {
	CommunicationManagement communicationManager;
	Warehouseman warehouseman;
	ProductList listOfProductsAvailableInWarehouse, *listaTest = new ProductList;
	FileManager fileManager;
	std::string produktTest;
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
				//listOfProductsAvailableInWarehouse.addProduct();
				//listOfProductsAvailableInWarehouse.addProduct();
				//listOfProductsAvailableInWarehouse.addProduct();
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				fileManager.write(listOfProductsAvailableInWarehouse);
				listaTest = fileManager.read();
				//fileManager.write(listOfProductsAvailableInWarehouse);
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