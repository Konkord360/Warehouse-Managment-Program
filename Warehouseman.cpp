#include "Warehouseman.h"

void Warehouseman::replenishReserve()
{
	CommunicationManagement communicationManager;
	FileManager fileManager;
	ProductList listOfCurrentStockOfItemsInWarehouse,listOfItemsToOrder, finalOrderList;
	char choice;
	int nr;
	int ilosc;
	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfCurrentStockOfItemsInWarehouse);
	do {
		communicationManager.displayList(finalOrderList);
		std::cout << "1.Dodaj przedmiot do zamowienia" << std::endl;
		std::cout << "2.Sfinalizuj zamowienie" << std::endl;
		std::cout << "3.Anuluj" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case '1': {
			listOfItemsToOrder.clearList();
			communicationManager.displayList(listOfCurrentStockOfItemsInWarehouse);
			std::cout << "Podaj numer produktu do zamowienia" << std::endl;
			std::cin >> nr;
			std::cout << "Podaj ilosc" << std::endl;
			std::cin >> ilosc;

			Product *newProduct = new Product;

			newProduct->expirationDate = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->expirationDate;
			newProduct->numberOfItemsInStock = ilosc;
			newProduct->productId = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->productId;
			newProduct->productName = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->productName;
			newProduct->productType = listOfCurrentStockOfItemsInWarehouse.getItem(nr)->productType;

			listOfItemsToOrder.addProduct(newProduct);
			listOfItemsToOrder.getItem(0)->nextProduct = nullptr;
			listOfItemsToOrder.getItem(0)->numberOfItemsInStock = ilosc;
			finalOrderList += listOfItemsToOrder;
			break;
		}
		case '2':
			fileManager.setFileToWorkWith("orderedItems.txt");
			fileManager.write(finalOrderList);
			choice = '3';
			break;
		case '3':
			break;
		}

	} while (choice != '3');
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
	if (listOfProductsToBeAdded.getSize() != 0) {
		listOfProductsAvailableInWarehouse += listOfProductsToBeAdded;

		fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
		fileManager.rewrite(listOfProductsAvailableInWarehouse);

		listOfProductsToBeAdded.clearList();
		fileManager.setFileToWorkWith("orderedItems.txt");
		fileManager.rewrite(listOfProductsToBeAdded);
	}
	else
		std::cout << "Brak dostawy do odebrania" << std::endl;
}

void Warehouseman::addProduct(ProductList& listOfProductsAvailableInWarehouse)
{
	FileManager fileManager;
	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfProductsAvailableInWarehouse);
	listOfProductsAvailableInWarehouse.addProduct();
	fileManager.rewrite(listOfProductsAvailableInWarehouse);
}

void Warehouseman::removeProduct(ProductList & listOfProductsAvailableInWarehouse)
{
	std::string nazwa;
	CommunicationManagement communicationManager;
	FileManager fileManager;

	listOfProductsAvailableInWarehouse.clearList();
	fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	fileManager.read(listOfProductsAvailableInWarehouse);

	communicationManager.displayList(listOfProductsAvailableInWarehouse);
	std::cout << "Podaj nazwe produktu do usuniecia z magazynu" << std::endl;
	std::cin >> nazwa;
	Product *productToDelete = new Product();
	productToDelete->productName = nazwa;
	if (listOfProductsAvailableInWarehouse.containsProduct(productToDelete)) {
		listOfProductsAvailableInWarehouse.removeProduct(nazwa);
	}
	else
		std::cout << "nie znaleziono takiego produktu w ofercie!" << std::endl;
	delete productToDelete;

	fileManager.rewrite(listOfProductsAvailableInWarehouse);
}
