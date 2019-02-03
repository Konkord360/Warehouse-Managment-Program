#include "WarehouseSide.h"


void ProductList::addProduct()
{
	Product* newProduct = getProductInfoFromUser();

		this->size++;

		if (this->head == nullptr)
			this->head = newProduct;

		else {
			Product *listHead = this->head;

			while (listHead->nextProduct != nullptr)
				listHead = listHead->nextProduct;

			listHead->nextProduct = newProduct;
			listHead->nextProduct->nextProduct = nullptr;
		}
}

void ProductList::addProduct(std::string productName)
{
	Product *newProduct = new Product;
	newProduct->productName = productName;

	//Product *newProduct2 = newProduct;
	this->size++;

	if (this->head == nullptr)
		this->head = newProduct;

	else {
		Product *listHead = this->head;

		while (listHead->nextProduct != nullptr)
			listHead = listHead->nextProduct;

		listHead->nextProduct = newProduct;
		listHead->nextProduct->nextProduct = nullptr;
	}
}

void ProductList::addProduct(Product *product)
{
	if (this->head == nullptr)
		this->head = product;
	else {
		Product *listHead = this->head;

		while (listHead->nextProduct != nullptr)
			listHead = listHead->nextProduct;

		listHead->nextProduct = product;
		listHead->nextProduct->nextProduct = nullptr;
	}
	this->size++;
}

void ProductList::removeProduct(std::string productName)
{
	if (this->head == nullptr)
		std::cout << "Lista jest pusta" << std::endl;

	else if (this->head->productName == productName)
	{
		//usuwanie produktu z poczatku listy
		delete head;
		this->head = nullptr;
		this->size--;
	}

	else
	{
		Product *temp = this->head;
		Product *toBeDeleted = this->head;
		//znalezienie produktu do usuniecia
		while (temp->nextProduct != nullptr && temp->nextProduct->productName != productName) 
			temp = temp->nextProduct;
		
		if (temp->nextProduct == nullptr)
			std::cout << "nie znaleziono produktu w ofercie" << std::endl;

		else if (temp->nextProduct->productName == productName) 
		{	
			//Usuwanie produktu ze œrodka listy
			if (temp->nextProduct->nextProduct != nullptr) {
				toBeDeleted = temp->nextProduct;
				temp->nextProduct = temp->nextProduct->nextProduct;
				delete toBeDeleted;
			}
			//usuwanie produktu z konca listy
			else {
				delete temp->nextProduct;
				temp->nextProduct == nullptr;
			}
			this->size--;
		}
	}
}

void ProductList::removeProduct(int index)
{
	if (this->head == nullptr)
		std::cout << "Lista jest pusta" << std::endl;

	else if (this->getSize() - 1 < index)
		std::cout << "nieistniej¹cy index" << std::endl;

	else if (index >= 0)
	{
		Product *temp = this->head;

		if (index == 0) {
			delete temp;
			this->head = nullptr;
		}

		else 
		{
			for (int i = 0; i < index; i++)
				this->head = this->head->nextProduct;

			delete temp;
		}
		this->size--;
	}
}

void ProductList::setToNext()
{
	if(this->head->nextProduct != nullptr)
		this->head = this->head->nextProduct;
	
	else {
		std::cout << "Index out of range. Function cannot be called" << std::endl;
	}
}

void ProductList::clearList()
{
	if (this->head != nullptr) {
		Product *deleter = this->head;

		if (deleter->nextProduct == nullptr)
			delete deleter;

		else
			while (deleter != nullptr) {
				deleter = deleter->nextProduct;
				delete this->head;
				this->head = deleter;
			}
	}
	this->size = 0;
	this->head = nullptr;
}

int ProductList::getSize()
{
	return this->size;
}

bool ProductList::isNextElementAvailable()
{
	if (this->head->nextProduct == nullptr)
		return false;
	else
		return true;
}

bool ProductList::containsProduct(const Product* product)
{
	Product *temp = this->head;

	while (temp != nullptr) {
		if (temp->productName == product->productName)
			return true;
		temp = temp->nextProduct;
	}

	return false;
}

Product * ProductList::getItem(int index)
{
	if (index > this->getSize() - 1)
		std::cout << "Index out of range" << std::endl;
	else {
		Product *itemToReturn = this->head;
		int i = 0;
		while (i < index)
		{
			itemToReturn = itemToReturn->nextProduct;
			i++;
		}
	
		return itemToReturn;
	}
}
Product * ProductList::getItem(std::string productName)
{	
	Product *itemToReturn = this->head;
	Product *product = new Product;
	product->productName = productName;

	if (this->containsProduct(product)) {
		delete product;
		itemToReturn = this->head;

		while (itemToReturn->productName != productName)
			itemToReturn = itemToReturn->nextProduct;

		return itemToReturn;
	}
	else {
		delete product;
		std::cout << "Nie znaleziono takiego produktu" << std::endl;
		return nullptr;
	}
}

//TODO: Poprawiæ tê metodê. dziala ale jest brzydka
Product* ProductList::getProductInfoFromUser()
{
	Product* newProduct = new Product;
	char userChoice;

	std::cout << " Podaje nazwe produktu" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, newProduct->productName);

	std::cout << "Podaj typ produktu" << std::endl;
	std::cout << "1. Zywnosc" << std::endl;
	std::cout << "2. Przedmiot" << std::endl;
	std::cin >> userChoice;

	switch (userChoice)
	{
	case '1':
		newProduct->productType = "Food";
		break;
	case '2':
		newProduct->productType = "Object";
		break;
	default:
		std::cout << "Bledny ty zywnosci" << std::endl;
		break;
	}
	
	return newProduct;
}

ProductList & ProductList::operator=(ProductList & productList)
{
	this->head = productList.head;
	this->size = productList.size;
	
	return *this;
}

ProductList & ProductList::operator+=(const ProductList & productList)
{
	ProductList temp1, temp2, temp3;
	Product *productOnListToBeAdded = productList.head;
	Product *productOnCurrentWarehouseList = this->head;

	while (productOnListToBeAdded != nullptr) {

		if (this->containsProduct(productOnListToBeAdded)) {
			while (productOnListToBeAdded->productName != productOnCurrentWarehouseList->productName) 
				productOnCurrentWarehouseList = productOnCurrentWarehouseList->nextProduct;
			
			productOnCurrentWarehouseList->numberOfItemsInStock += productOnListToBeAdded->numberOfItemsInStock;
			productOnCurrentWarehouseList = this->head;
			productOnListToBeAdded = productOnListToBeAdded->nextProduct;
		}

	}
	return *this;
}

ProductList::~ProductList()
{
	if (this->head != nullptr) {
		Product *deleter = this->head;

		if (deleter->nextProduct == nullptr)
			delete deleter;

		else {
			while (deleter->nextProduct != nullptr) {
				deleter = deleter->nextProduct;
				delete this->head;
				this->head = deleter;
			}
			delete deleter;
		}
	}
}

ProductList & ProductList::operator=(ProductList && productList)
{
	this->head = std::move(productList.head);
	this->size = std::move(productList.size);

	return *this;
}

//ProductList & ProductList::operator=(ProductList && productList)
//{
//	this->productList = std::move(productList.productList);
//
//	return *this;
//}


Product & Product::operator=(Product && product)
{
	this->expirationDate = std::move(product.expirationDate);
	this->productId = std::move(product.productId);
	this->productName = std::move(product.productName);
	this->productType = std::move(product.productType);

	return *this;
}

void Product::checkIfProductIsAllreadyInOffer()
{
	//FileManager fileManager;
	//fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	////productList = fileManager.read();
	//productList.getItem(0);
}