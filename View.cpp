#include "View.h"

char CommunicationManagement::getUserInput()
{
	return this->userInput;
}

void CommunicationManagement::setUserInput(char input)
{
	this->userInput = input;
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
	std::cout << "4. Dodaj produkt do oferty magazynu" << std::endl;
	std::cout << "5. Usuñ produkt z oferty magazynu" << std::endl;
	std::cout << "6. Zakoncz" << std::endl;
	std::cin >> this->userInput;
}

void CommunicationManagement::viewCustomerMenu()
{
	std::cout << "1. Zloz zamowienie" << std::endl;
	std::cout << "2. Odbierz zamowienie" << std::endl;
	std::cout << "3. Anuluj zamowienie" << std::endl;
	std::cout << "4. Zakoncz" << std::endl;
	std::cin >> this->userInput;
}

void CommunicationManagement::displayList(ProductList & productList)
{
	if (productList.getSize() == 0)
		std::cout << "Lista jest pusta" << std::endl;
	else
		std::cout << "Nazwa produktu: \t Typ produktu: \t ID produktu: \t Ilosc produktow w magazynie: \t Data waznosci:" << std::endl;
		for (int i = 0; i < productList.getSize(); i++) {
			std::cout << i << ". " << productList.getItem(i)->productName << "\t\t" << productList.getItem(i)->productType << "\t\t"
				<< productList.getItem(i)->productId << "\t\t" << productList.getItem(i)->numberOfItemsInStock << "\t\t"
				<< productList.getItem(i)->expirationDate << std::endl;
		}
}

void CommunicationManagement::displayOrderedItems(ProductList & productList)
{
	if (productList.getSize() == 0)
		std::cout << "Koszyk jest pusty" << std::endl;
	else
		std::cout << "Nazwa produktu: \t Typ produktu: \t ilosc: " << std::endl;
	for (int i = 0; i < productList.getSize(); i++) {
		std::cout << i << ". " << productList.getItem(i)->productName << "\t \t \t" << productList.getItem(i)->productType << "\t \t"
			<< productList.getItem(i)->numberOfItemsInStock << std::endl;
	}
}