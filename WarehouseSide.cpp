#include "WarehouseSide.h"


void ProductList::addProduct()
{
	Product* newProduct = getProductInfoFromUser();

		this->size++;

		if (this->productList == nullptr)
			this->productList = newProduct;

		else {
			Product *listHead = this->productList;

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

	if (this->productList == nullptr)
		this->productList = newProduct;

	else {
		Product *listHead = this->productList;

		while (listHead->nextProduct != nullptr)
			listHead = listHead->nextProduct;

		listHead->nextProduct = newProduct;
		listHead->nextProduct->nextProduct = nullptr;
	}
}

void ProductList::addProduct(Product *product)
{
	if (this->productList == nullptr)
		this->productList = product;
	else {
		Product *listHead = this->productList;

		while (listHead->nextProduct != nullptr)
			listHead = listHead->nextProduct;

		listHead->nextProduct = product;
		listHead->nextProduct->nextProduct = nullptr;
	}
	this->size++;
}

void ProductList::removeProduct(std::string productName)
{
	if (this->productList == nullptr)
		std::cout << "Lista jest pusta" << std::endl;

	else if (this->productList->productName == productName)
	{
		//usuwanie produktu z poczatku listy
		delete productList;
		this->productList = nullptr;
		this->size--;
	}

	else
	{
		Product *temp = this->productList;
		Product *toBeDeleted = this->productList;
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
	if (this->productList == nullptr)
		std::cout << "Lista jest pusta" << std::endl;

	else if (this->getSize() - 1 < index)
		std::cout << "nieistniej¹cy index" << std::endl;

	else if (index >= 0)
	{
		Product *temp = this->productList;

		if (index == 0) {
			delete temp;
			this->productList = nullptr;
		}

		else 
		{
			for (int i = 0; i < index; i++)
				this->productList = this->productList->nextProduct;

			delete temp;
		}
		this->size--;
	}
}

void ProductList::setToNext()
{
	if(this->productList->nextProduct != nullptr)
		this->productList = this->productList->nextProduct;
	
	else {
		std::cout << "Index out of range. Function cannot be called" << std::endl;
	}
}

void ProductList::clearList()
{
	if (this->productList != nullptr) {
		Product *deleter = this->productList;

		if (deleter->nextProduct == nullptr)
			delete deleter;

		else
			while (deleter != nullptr) {
				deleter = deleter->nextProduct;
				delete this->productList;
				this->productList = deleter;
			}
	}
	this->size = 0;
}

int ProductList::getSize()
{
	return this->size;
}

bool ProductList::isNextElementAvailable()
{
	if (this->productList->nextProduct == nullptr)
		return false;
	else
		return true;
}

bool ProductList::containsProduct(const Product* product)
{
	Product *temp = this->productList;

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
		Product *itemToReturn = this->productList;
		int i = 0;
		while (i < index)
		{
			itemToReturn = itemToReturn->nextProduct;
			i++;
		}
	
		return itemToReturn;
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
	this->productList = productList.productList;
	this->size = productList.size;
	
	return *this;
}

ProductList & ProductList::operator+=(const ProductList & productList)
{
	ProductList temp1, temp2, temp3;
	Product *productOnListToBeAdded = productList.productList;
	Product *productOnCurrentWarehouseList = this->productList;

	while (productOnListToBeAdded != nullptr) {

		if (this->containsProduct(productOnListToBeAdded)) {
			while (productOnListToBeAdded->productName != productOnCurrentWarehouseList->productName) 
				productOnCurrentWarehouseList = productOnCurrentWarehouseList->nextProduct;
			
			productOnCurrentWarehouseList->numberOfItemsInStock += productOnListToBeAdded->numberOfItemsInStock;
			productOnCurrentWarehouseList = this->productList;
			productOnListToBeAdded = productOnListToBeAdded->nextProduct;
		}

	}
	return *this;
}

ProductList::~ProductList()
{
	if (this->productList != nullptr) {
		Product *deleter = this->productList;

		if (deleter->nextProduct == nullptr)
			delete deleter;

		else
			while (deleter->nextProduct != nullptr) {
				deleter = deleter->nextProduct;
				delete this->productList;
				this->productList = deleter;
			}
	}
}

ProductList & ProductList::operator=(ProductList && productList)
{
	this->productList = std::move(productList.productList);
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