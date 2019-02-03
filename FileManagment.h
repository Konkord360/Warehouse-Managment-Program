#pragma once
#include <iostream>
#include <fstream>
#include "WarehouseSide.h"
#include "CustomerSide.h"
class FileManager {
private:
	std::string fileToWorkWith;
public:
	FileManager(std::string fileName) : fileToWorkWith(fileName) {};
	FileManager() : fileToWorkWith("") {};

	void read(ProductList& productList);
	void writeNamesOfProductsToFile(ProductList listOfProductsToWriteToFile);
	void rewriteNamesOfProductsToFile(ProductList listOfProductsToWriteToFile);
	void write(ProductList& listOfProductsToWriteToFile);
	void writeOrderToFile(CustomerOrder& customerOrder);
	void rewriteOrdersToFile(CustomerOrderList& customerOrderList);
	void readOrdersFromFile(CustomerOrderList& customerOrderList);
	void rewrite(ProductList& listOfProductsToWriteToFile);
	void setFileToWorkWith(std::string fileName);
	bool checkIfProductIsInOffer(Product& product);
};