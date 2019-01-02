#include "WarehouseSide.h"


void ProductList::addProduct()
{
	Product *newProduct = getProductInfoFromUser();
	newProduct->checkIfProductIsAllreadyInOffer();

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
	//}
	//else
	//	std::cout << "Produk znajduje siê ju¿ w ofercie magazyni" << std::endl;
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

void ProductList::setToNext()
{
	if(this->productList->nextProduct != nullptr)
		this->productList = this->productList->nextProduct;
	
	else {
		std::cout << "Index out of range. Function cannot be called" << std::endl;
	}
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

Product * ProductList::getItem(int index)
{
	if (index > this->getSize() - 1)
		std::cout << "Index out of range" << std::endl;
	else {
		Product *listHead = this->productList;
		int i = 0;
		while (i < index)
		{
			listHead = listHead->nextProduct;
			i++;
		}
	
		return listHead;
	}
}
//TODO: Poprawiæ tê metodê. dziala ale jest brzydka
Product* ProductList::getProductInfoFromUser()
{
	Product *newProduct = new Product;
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
	//ProductList productList;
	//FileManager fileManager;
	//fileManager.setFileToWorkWith("listOfProductsAvailableInWarehouse.txt");
	////productList = fileManager.read();
	//productList.getItem(0);
}
