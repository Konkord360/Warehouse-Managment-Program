#include <iostream>
#include "View.h"
#include "WarehouseSide.h"
#include "FileManagment.h"
#include <vld.h>
#include "Warehouseman.h"

int main() {
	CommunicationManagement communicationManager;
	Warehouseman warehouseman;
	ProductList listOfProductsAvailableInWarehouse, listaTest;
	FileManager fileManager;
	std::string produktTest;
	char choice;
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
			case addProduct:
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				listOfProductsAvailableInWarehouse.addProduct();
				fileManager.write(listOfProductsAvailableInWarehouse);
				listOfProductsAvailableInWarehouse.removeProduct(0);
				break;
			case removeProduct:
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
		case '2': communicationManager.viewCustomerMenu();
			break;
		default:
			break;
		}
	}
	listOfProductsAvailableInWarehouse.clearList();
	return 0;
}