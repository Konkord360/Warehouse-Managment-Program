#include "FileManagment.h"

void FileManager::write(ProductList listOfProductsToWriteToFile)
{
	std::ofstream fileToWriteTo (this->fileToWorkWith, std::ios::app);
	if (fileToWriteTo.is_open()) {
		for (int i = 0; i < listOfProductsToWriteToFile.getSize(); i++) {
			fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productName;
			fileToWriteTo << std::endl;
		}
	}
	fileToWriteTo.close();
}

void FileManager::rewrite(ProductList listOfProductsToWriteToFile)
{
	std::ofstream fileToWriteTo(this->fileToWorkWith);
	if (fileToWriteTo.is_open()) {
		for (int i = 0; i < listOfProductsToWriteToFile.getSize(); i++) {
			fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productName;
			fileToWriteTo << std::endl;
		}
	}
	fileToWriteTo.close();
}

ProductList* FileManager::read()
{
	ProductList* productList = new ProductList;
	std::string nameOfProduct;
	std::ifstream fileToReadFrom (this->fileToWorkWith, std::ios::app);
	if (fileToReadFrom.is_open()) {
		while (!fileToReadFrom.eof()) {
			nameOfProduct = "";
			fileToReadFrom >> nameOfProduct;
			if(nameOfProduct != "")
				productList->addProduct(nameOfProduct);
		}
	}
	fileToReadFrom.close();
	return productList;
}

void FileManager::setFileToWorkWith(std::string fileName)
{
	this->fileToWorkWith = fileName;
}
