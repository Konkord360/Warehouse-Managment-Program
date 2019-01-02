#pragma once
#include <iostream>
#include <fstream>
#include "WarehouseSide.h"

class FileManager {
private:
	std::string fileToWorkWith;
public:
	FileManager(std::string fileName) : fileToWorkWith(fileName) {};
	FileManager() : fileToWorkWith("") {};

	ProductList* read();
	void write(ProductList listOfProductsToWriteToFile);
	void setFileToWorkWith(std::string fileName);
};