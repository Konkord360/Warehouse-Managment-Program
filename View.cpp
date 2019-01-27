#include "View.h"


char CommunicationManagement::getUserInput()
{
	return this->userInput;
}

void CommunicationManagement::viewMainMenu()
{   
	std::cout << "1. Menu magazyniera" << std::endl;
	std::cout << "2. Menu klienta" << std::endl;
	std::cout << "3. Zamknij" << std::endl;
	std::cin >> this->userInput;
}

void CommunicationManagement::viewWarehousemanMenu()
{
	std::cout << "1. Uzupelnij zapasy" << std::endl;
	std::cout << "2. Sprawdz stan magazynu" << std::endl;
	std::cout << "3. Przyjmij dostawe" << std::endl;
	std::cout << "4. Zrob porzadek w magazynie" << std::endl;
	std::cout << "5. Sprawdz daty waznosci produktow" << std::endl;
	std::cout << "6. Dodaj produkt do oferty magazynu" << std::endl;
	std::cout << "7. Usu� produkt z oferty magazynu" << std::endl;
	std::cout << "8. Zakoncz" << std::endl;
	std::cin >> this->userInput;
}

void CommunicationManagement::viewCustomerMenu()
{
	std::cout << "1. Zloz zamowienie" << std::endl;
	std::cout << "2. Anuluj zamowienie" << std::endl;
	std::cout << "3. Zakoncz" << std::endl;
	std::cin >> this->userInput;

	handleCustomerMenuChoice();
}

void CommunicationManagement::handleWarehousemanMenuChoice()
{
	switch (this->userInput) {
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
		break;
	case removeProduct:
		break;
	case closeWarehousemanEnum:
		break;
	}
}

void CommunicationManagement::handleCustomerMenuChoice()
{
}

void CommunicationManagement::viewWarehouseStock()
{
}

void CommunicationManagement::displayList(ProductList & productList)
{
	if (productList.getSize() == 0)
		std::cout << "Lista jest pusta" << std::endl;
	else
		std::cout << "Nazwa produktu: \t Typ produktu: \t ID produktu: \t Ilo�c produktow w magazynie: \t Data waznosci:" << std::endl;
		for (int i = 0; i < productList.getSize(); i++) {
			std::cout << i << ". " << productList.getItem(i)->productName << "\t \t \t \t" << productList.getItem(i)->productType << "\t \t"
				<< productList.getItem(i)->productId << "\t \t \t" << productList.getItem(i)->numberOfItemsInStock << "\t \t \t"
				<< productList.getItem(i)->expirationDate << std::endl;
		}
}

void CommunicationManagement::getInfoAboutOrder(ProductList & productList)
{

}
