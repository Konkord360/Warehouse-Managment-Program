#pragma once
#include <iostream>
#include <string>
#include <exception>

struct Product {
	std::string productName;
	std::string productType;
	std::string productId;
	std::string expirationDate;
	int numberOfItemsInStock;
	Product *nextProduct;
public:
	Product() :  productName("NA"), productType("NA"), productId("NA"), expirationDate("NA"),numberOfItemsInStock(0),nextProduct(nullptr) {};
	Product(const Product &product) :  productName(product.productName), productType(product.productName), productId(product.productId),
		expirationDate(product.expirationDate),numberOfItemsInStock(product.numberOfItemsInStock),nextProduct(product.nextProduct) {};
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
	void addProduct(Product* product);
	void removeProduct(std::string productName);
	void removeProduct(int index);
	void setToNext();//
	void clearList();
	int getSize();
	bool isNextElementAvailable();//
	bool isEmpty();//
	bool containsProduct(const Product* product);
	Product* getItem(int index);
	Product* getProductInfoFromUser();//
	ProductList() : productList(nullptr), size(0) {};
	ProductList(const ProductList &productList) : productList(productList.productList), size(productList.size) {};
	~ProductList();
	ProductList& operator=(ProductList &&productList);
	ProductList& operator=(ProductList &productList);
	ProductList& operator+=(const ProductList &productList);
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



/*?????
class Dostawa {
};
*/