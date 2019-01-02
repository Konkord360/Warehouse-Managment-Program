#include <iostream>
#include "View.h"
#include "WarehouseSide.h"
#include "FileManagment.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

int main() {
	CommunicationManagement communicationManager;
	Warehouseman warehouseman;
	ProductList *listOfProductsAvailableInWarehouse = new ProductList, *listaTest = new ProductList;
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
				listOfProductsAvailableInWarehouse->addProduct();
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				fileManager.write(*listOfProductsAvailableInWarehouse);
				break;
			case removeProduct:
				fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
				if (listOfProductsAvailableInWarehouse->getSize() == 0)
					listOfProductsAvailableInWarehouse = fileManager.read();
				listOfProductsAvailableInWarehouse->removeProduct("ser");
				fileManager.rewrite(*listOfProductsAvailableInWarehouse);
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
	_CrtDumpMemoryLeaks();
	return 0;
}