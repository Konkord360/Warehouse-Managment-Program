#include "Warehouseman.h"

void Warehouseman::replenishReserve()
{
	CommunicationManagement communicationManager;
	FileManager fileManager;
	ProductList listOfCurrentStockOfItemsInWarehouse,listOfItemsToOrder;
	int nr;
	int ilosc;

	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfCurrentStockOfItemsInWarehouse);
	communicationManager.displayList(listOfCurrentStockOfItemsInWarehouse);
	fileManager.setFileToWorkWith("orderedItems.txt");

	std::cout << "Podaj numer przedmiotu do zamowienia wciœniej o aby wyjsc" << std::endl;
	std::cin >> nr;
	std::cout << " Podaj ilosc: " << std::endl;
	std::cin >> ilosc;

	listOfItemsToOrder.addProduct(listOfCurrentStockOfItemsInWarehouse.getItem(nr)->productName);
	listOfItemsToOrder.getItem(0)->productType = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->productType;
	listOfItemsToOrder.getItem(0)->numberOfItemsInStock += ilosc;
	listOfItemsToOrder.getItem(0)->expirationDate = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->expirationDate;
	listOfItemsToOrder.getItem(0)->productId = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->productId;

	fileManager.write(listOfItemsToOrder);
}

void Warehouseman::checkStockOfProducts()
{
	FileManager fileManager;
	ProductList listOfProductsAvailableInWarehouse;
	CommunicationManagement communicationManager;

	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfProductsAvailableInWarehouse);
	communicationManager.displayList(listOfProductsAvailableInWarehouse);
}

void Warehouseman::reciveDelivery()
{
	FileManager fileManager;
	ProductList listOfProductsAvailableInWarehouse, listOfProductsToBeAdded;

	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfProductsAvailableInWarehouse);
	fileManager.setFileToWorkWith("orderedItems.txt");
	fileManager.read(listOfProductsToBeAdded);

	listOfProductsAvailableInWarehouse += listOfProductsToBeAdded;

	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.rewrite(listOfProductsAvailableInWarehouse);

	listOfProductsToBeAdded.clearList();
	fileManager.setFileToWorkWith("orderedItems.txt");
	fileManager.rewrite(listOfProductsToBeAdded);
}
