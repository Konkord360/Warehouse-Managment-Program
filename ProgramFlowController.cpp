#include "ProgramFlowController.h"
#include "CustomerSide.h"
#include "FileManagment.h"
#include "Generators.h"
#include "View.h"
#include "Warehouseman.h"

bool FlowControll::runProgram()
{
	CommunicationManagement communicationManager;

	while (communicationManager.getUserInput() != end) {
		communicationManager.viewMainMenu();

		switch (communicationManager.getUserInput())
		{
		case '1':
			this->handleWarehousemanMenu();
			communicationManager.setUserInput('0');
			break;
		case '2':
			this->handleCustomerMenu();
			communicationManager.setUserInput('0');
			break;
		}
	}
	return false;
}

void FlowControll::handleWarehousemanMenu()
{
	CommunicationManagement communicationManager;
	FileManager fileManager;
	ProductList listOfProductsAvailableInWarehouse;
	Warehouseman warehouseman;

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
	
}

void FlowControll::handleCustomerMenu()
{
	CommunicationManagement communicationManager;
	CustomerOrderList customerOrderList;
	Customer customer;
	ProductList listOfProductsAvailableInWarehouse;
	CustomerOrder customerOrder;
	FileManager fileManager;

	communicationManager.viewCustomerMenu();
	switch (communicationManager.getUserInput()) {
	case makeOrder:
		fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
		fileManager.read(listOfProductsAvailableInWarehouse);
		customerOrderList.~CustomerOrderList();
		customer.makeOrder(listOfProductsAvailableInWarehouse, customerOrder);
		fileManager.writeOrderToFile(customerOrder);
		customerOrderList.~CustomerOrderList();
		listOfProductsAvailableInWarehouse.clearList();
		break;
	case reciveOrder:
		fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
		fileManager.read(listOfProductsAvailableInWarehouse);
		customerOrderList.~CustomerOrderList();
		fileManager.readOrdersFromFile(customerOrderList);
		customer.reciveOrder(listOfProductsAvailableInWarehouse, customerOrderList);
		fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
		fileManager.rewrite(listOfProductsAvailableInWarehouse);
		fileManager.rewriteOrdersToFile(customerOrderList);
		listOfProductsAvailableInWarehouse.clearList();
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
}
