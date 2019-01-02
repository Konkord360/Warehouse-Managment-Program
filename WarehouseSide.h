#pragma once
#include <iostream>
#include <string>
#include <exception>

struct Product {
	std::string productName;
	std::string productType;
	std::string productId;
	std::string expirationDate;
	Product *nextProduct;
public:
	Product() :  productName(""), productType(""), productId(""), expirationDate(""),nextProduct(nullptr) {};
	Product& operator=(Product&& object);
	void checkIfProductIsAllreadyInOffer();//move to product
};

class ProductList {
private:
	Product *productList;
	int size;

public:
	void viewProducts();
	void addProduct();
	void addProduct(std::string productName);
	void removeProduct();
	void setToNext();//
	int getSize();
	bool isNextElementAvailable();//
	bool isEmpty();//
	Product* getItem(int index);
	Product* getProductInfoFromUser();//
	ProductList() : productList(nullptr), size(0) {};
	//ProductList& operator=(ProductList&& object) = default;
};

class Shelf {
private:
	int numberOfSlotsLeft;
	int numberOfSlots;
public:
	void removeProduct();
	void addProduct();
	void checkQuantity();
};

class Shelfs {
private:
	Shelf *shelfs;
public:
	static int numberOfShelfs;
};

class Warehouseman {
private:

public:
	void replenishReserve();
	void checkStockOfProducts();
	void reciveDelivery();
};

/*?????
class Dostawa {
};
*/