#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <string>
#include <fstream>
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
	friend std::ifstream& operator >> (std::ifstream& in, Product* product);
	friend std::ofstream& operator << (std::ofstream& out, Product* product);
};

class ProductList {
private:
	Product *head;
	int size;

public:
	void addProduct();
	void addProduct(std::string productName);
	void addProduct(Product* product);
	void removeProduct(std::string productName);
	void removeProduct(int index);
	void clearList();
	int getSize();
	bool containsProduct(const Product* product);
	Product* getItem(int index);
	Product* getItem(std::string productName);
	Product* getProductInfoFromUser();
	ProductList() : head(nullptr), size(0) {};
	ProductList(const ProductList &productList) : head(productList.head), size(productList.size) {};
	~ProductList();
	ProductList& operator=(ProductList &&productList);
	ProductList& operator=(ProductList &productList);
	ProductList& operator+=(const ProductList &productList);
};
