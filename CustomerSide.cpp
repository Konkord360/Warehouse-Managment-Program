#include "CustomerSide.h"
#include <iostream>

void Customer::addItemToOrder(ProductList& listOfOrderedItems, ProductList& listOfProductsAvailableInWarehouse)
{
	CommunicationManagement communicationManager;
	int nr, ilosc;

	communicationManager.displayList(listOfProductsAvailableInWarehouse);

	std::cout << "Podaj numer przedmiotu do zamowienia, wcisnij 'o' aby wyjsc" << std::endl;
	std::cin >> nr;
	std::cout << " Podaj ilosc: " << std::endl;
	std::cin >> ilosc;

	if (!listOfOrderedItems.containsProduct(listOfProductsAvailableInWarehouse.getItem(nr))) {
		listOfOrderedItems.addProduct(listOfProductsAvailableInWarehouse.getItem(nr)->productName);
		listOfOrderedItems.getItem(listOfOrderedItems.getSize() - 1)->productType = listOfProductsAvailableInWarehouse.getItem(nr)->productType;
		listOfOrderedItems.getItem(listOfOrderedItems.getSize() - 1)->numberOfItemsInStock += ilosc;
		listOfOrderedItems.getItem(listOfOrderedItems.getSize() - 1)->expirationDate = listOfProductsAvailableInWarehouse.getItem(nr)->expirationDate;
		listOfOrderedItems.getItem(listOfOrderedItems.getSize() - 1)->productId = listOfProductsAvailableInWarehouse.getItem(nr)->productId;
	}
	else 
		listOfOrderedItems.getItem(listOfProductsAvailableInWarehouse.getItem(nr)->productName)->numberOfItemsInStock += ilosc;
}

void Customer::finalizeOrder(CustomerOrder& customerOrder)
{
	std::cout << "Podaj imie" << std::endl;
	std::cin >> this->name;
	std::cout << "Podaj imie" << std::endl;
	std::cin >> this->surname;
	std::cout << "podaj pesel" << std::endl;
	std::cin >> this->pesel;

	customerOrder.getCustomer().name = this->name;
	customerOrder.getCustomer().surname = this->surname;
	customerOrder.getCustomer().pesel = this->pesel;
}

void Customer::makeOrder(ProductList& listOfProductsAvailableInWarehouse, CustomerOrder& customerOrder)
{
	ProductList listOfOrderedItems;
	CommunicationManagement communicationManager;
	int nr, ilosc; 
	char customerChoice = ' ';

	do {
		communicationManager.displayOrderedItems(customerOrder.getOrderedItems());
		std::cout << "1.Dodaj przedmiot do zamowienia" << std::endl;
		std::cout << "2.Sfinalizuj zamowienie" << std::endl;
		std::cout << "3.Anuluj" << std::endl;
		std::cin >> customerChoice;
		switch (customerChoice) {
		case '1' :
			this->addItemToOrder(customerOrder.getOrderedItems(), listOfProductsAvailableInWarehouse);
			break;
		case '2' :
			this->finalizeOrder(customerOrder);
			customerChoice = '3';
			break;
		case '3' :
			break;
		}

	} while (customerChoice != '3');
}

void Customer::cancelOrder()
{
}

void Customer::reciveOrder(ProductList& listOfProductsAvailableInWarehouse, CustomerOrderList& orderList)
{
	std::string name, surname, pesel;
	std::cout << "Podaj imie:" << std::endl;
	std::cin >> name;
	std::cout << "Podaj nazwisko" << std::endl;
	std::cin >> surname;
	std::cout << "Podaj pesel" << std::endl;
	std::cin >> pesel;

	CustomerOrder *orderToBeRecived  = orderList.getOrder(pesel);
	if (orderToBeRecived != nullptr) {
		for (int i = 0; i < orderToBeRecived->getOrderedItems().getSize(); i++)
			if (listOfProductsAvailableInWarehouse.getItem(orderToBeRecived->getOrderedItems().getItem(i)->productName)->numberOfItemsInStock <
				orderToBeRecived->getOrderedItems().getItem(i)->numberOfItemsInStock) {
				std::cout << "Nie mozna zrealizowac zamowienia! Za mala ilosc " << orderToBeRecived->getOrderedItems().getItem(i)->productName <<
					"w magazynie. Poczekaj na dostawe." << std::endl;
				orderList.addOrder(orderToBeRecived);
				return;
			}

		for (int j = 0; j < orderToBeRecived->getOrderedItems().getSize(); j++)
			listOfProductsAvailableInWarehouse.getItem(orderToBeRecived->getOrderedItems().getItem(j)->productName)->numberOfItemsInStock -=
			orderToBeRecived->getOrderedItems().getItem(j)->numberOfItemsInStock;

		delete orderToBeRecived;
	}
	else
		std::cout << "Nie znaleziono zamowienia na taka osobe" << std::endl;
	//wyszukaæ zamówienei w order List -> odj¹c produkty od listOffProductsAvailableInWarehouse -> usun¹æ zamówienie z orderList i nadpisaæ plik(w mainie) :)
}


Customer & Customer::operator=(Customer && customer)
{
	this->name = std::move(customer.name);
	this->surname = std::move(customer.surname);
	this->pesel = std::move(customer.pesel);
	return *this;
}

Customer & Customer::operator=(Customer & customer)
{
	this->name = customer.name;
	this->surname = customer.surname;
	this->pesel = customer.pesel;
	return *this;
}

std::string Customer::getCustomerName()
{
	return this->name;
}

std::string Customer::getCustomerSurname()
{
	return this->surname;
}

std::string Customer::getCustomerPesel()
{
	return this->pesel;
}

ProductList& CustomerOrder::getOrderedItems()
{
	return this->orderedItems;
}

Customer& CustomerOrder::getCustomer()
{
	return this->customer;
}

void CustomerOrder::setProductList(ProductList & productList)
{
	this->orderedItems = productList;
}

void CustomerOrder::setCustomer(Customer & customer)
{
	this->customer = customer;
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder && order)
{
	this->customer = std::move(order.customer);
	this->orderedItems = std::move(order.orderedItems);
	return *this;
}

void CustomerOrderList::addOrder(CustomerOrder* customerOrder)
{
	if (this->head == nullptr)
		this->head = customerOrder;
	else {
		CustomerOrder *listHead = this->head;

		while (listHead->nextOrder != nullptr)
			listHead = listHead->nextOrder;
	
		listHead->nextOrder = customerOrder;
		listHead->nextOrder->nextOrder = nullptr;
	}
	//this->size++;
}

CustomerOrder* CustomerOrderList::getOrder(std::string pesel)
{
	if (this->head == nullptr) 
		return nullptr;
	
	else {
		CustomerOrder * pom = this->head;
		CustomerOrder * orderToReturn = pom;
		if (pom->getCustomer().getCustomerPesel() == pesel) {
			this->head = this->head->nextOrder;
			orderToReturn->nextOrder = nullptr;
			return orderToReturn;
		}

		else {
			while (pom->nextOrder != nullptr) {
				if (pom->nextOrder->getCustomer().getCustomerName() == pesel) {
					orderToReturn = pom->nextOrder;
					pom->nextOrder = pom->nextOrder->nextOrder;
					orderToReturn->nextOrder = nullptr;
					return orderToReturn;
				}

				else
					pom = pom->nextOrder;
			}
			return nullptr;
		}
	}
}

CustomerOrder * CustomerOrderList::getHead()
{
	return this->head;
}

CustomerOrderList::~CustomerOrderList()
{
	CustomerOrder* pom = this->head;
	CustomerOrder* pom2 = pom;
	ProductList *productList = &pom->getOrderedItems();
	while (pom != nullptr) {
		pom->getOrderedItems().clearList();
		pom = pom->nextOrder;
		delete pom2;
		pom2 = pom;
	}
}
