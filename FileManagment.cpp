#include "FileManagment.h"

void FileManager::writeNamesOfProductsToFile(ProductList listOfProductsToWriteToFile)
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

void FileManager::rewriteNamesOfProductsToFile(ProductList listOfProductsToWriteToFile)
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

void FileManager::write(ProductList& listOfProductsToWriteToFile)
{
	std::ofstream fileToWriteTo(this->fileToWorkWith, std::ios::app);
	if(listOfProductsToWriteToFile.getSize() != 0)
		if (fileToWriteTo.is_open()) {
			for (int i = 0; i < listOfProductsToWriteToFile.getSize(); i++) {
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productName;
				fileToWriteTo << " ";						
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productType;
				fileToWriteTo << " ";						
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productId;
				fileToWriteTo << " ";						
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->numberOfItemsInStock;
				fileToWriteTo << " ";						
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->expirationDate;
				fileToWriteTo << std::endl;
			}
		}
	fileToWriteTo.close();
}

void FileManager::rewrite(ProductList& listOfProductsToWriteToFile)
{
	std::ofstream fileToWriteTo(this->fileToWorkWith);

	if (listOfProductsToWriteToFile.getSize() != 0)
		if (fileToWriteTo.is_open()) {
			for (int i = 0; i < listOfProductsToWriteToFile.getSize(); i++) {
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productName;
				fileToWriteTo << " ";								   
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productType;
				fileToWriteTo << " ";								   
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->productId;
				fileToWriteTo << " ";								   
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->numberOfItemsInStock;
				fileToWriteTo << " ";								   
				fileToWriteTo << listOfProductsToWriteToFile.getItem(i)->expirationDate;
				fileToWriteTo << std::endl;
			}
		}
	fileToWriteTo.close();
}

void FileManager::read(ProductList &productList)
{
	std::ifstream fileToReadFrom (this->fileToWorkWith);
	
	if (fileToReadFrom.is_open()) {
		while (!fileToReadFrom.eof()) {
			Product *product = new Product;
			fileToReadFrom >> product->productName;
			fileToReadFrom >> product->productType;
			fileToReadFrom >> product->productId;
			fileToReadFrom >> product->numberOfItemsInStock;
			fileToReadFrom >> product->expirationDate;
			if ("NA" != product->productName)
				productList.addProduct(product);
		}
	}
	fileToReadFrom.close();
}

void FileManager::setFileToWorkWith(std::string fileName)
{
	this->fileToWorkWith = fileName;
}

bool FileManager::checkIfProductIsInOffer(Product& product)
{
	ProductList productList;
	this->read(productList);


	return false;
}
