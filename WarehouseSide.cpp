#include "WarehouseSide.h"
#include "Generators.h"

void ProductList::addProduct()
{
	IDGenerator idGenerator;
	ExpirationDateGenerator dateGenerator;
	Product* newProduct = getProductInfoFromUser();

	if (!this->containsProduct(newProduct)) {
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
	else {
		std::cout << "Produkt znajduje sie juz w ofercie!" << std::endl;
		delete newProduct;
	}
}

void ProductList::addProduct(std::string productName)
{
	Product *newProduct = new Product;
	newProduct->productName = productName;

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
		delete head;
		this->head = nullptr;
		this->size--;
	}

	else
	{
		Product *temp = this->head;
		Product *toBeDeleted = this->head;

		while (temp->nextProduct != nullptr && temp->nextProduct->productName != productName) 
			temp = temp->nextProduct;
		
		if (temp->nextProduct == nullptr)
			std::cout << "nie znaleziono produktu w ofercie" << std::endl;

		else if (temp->nextProduct->productName == productName) 
		{	
			if (temp->nextProduct->nextProduct != nullptr) {
				toBeDeleted = temp->nextProduct;
				temp->nextProduct = temp->nextProduct->nextProduct;
				delete toBeDeleted;
			}
			else {
				delete temp->nextProduct;
				temp->nextProduct = nullptr;
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
	return nullptr;
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

Product* ProductList::getProductInfoFromUser()
{
	IDGenerator idGenerator;
	ExpirationDateGenerator dateGenerator;
	Product* newProduct = new Product;
	char userChoice;

	newProduct->productId = idGenerator.generate();

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
		newProduct->expirationDate = dateGenerator.generate();
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
		}
		else {
			Product* newProduct = new Product;

			newProduct->expirationDate = productOnListToBeAdded->expirationDate;
			newProduct->numberOfItemsInStock = productOnListToBeAdded->numberOfItemsInStock;
			newProduct->productId = productOnListToBeAdded->productId;
			newProduct->productName = productOnListToBeAdded->productName;
			newProduct->productType = productOnListToBeAdded->productType;

			this->addProduct(newProduct);
		}

		productOnListToBeAdded = productOnListToBeAdded->nextProduct;
		productOnCurrentWarehouseList = this->head;
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

Product & Product::operator=(Product && product)
{
	this->expirationDate = std::move(product.expirationDate);
	this->productId = std::move(product.productId);
	this->productName = std::move(product.productName);
	this->productType = std::move(product.productType);

	return *this;
}

std::ifstream & operator>>(std::ifstream& in, Product* product)
{
	in >> product->productName;
	in >> product->productType;
	in >> product->productId;
	in >> product->numberOfItemsInStock;
	in >> product->expirationDate;

	return in;
}

std::ofstream & operator<<(std::ofstream & out, Product * product)
{
	out << product->productName;
	out << " ";
	out << product->productType;
	out << " ";
	out << product->productId;
	out << " ";
	out << product->numberOfItemsInStock;
	out << " ";
	out << product->expirationDate;
	out << std::endl;
	
	return out;
}
