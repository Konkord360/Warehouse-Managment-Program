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

void FileManager::writeOrderToFile(CustomerOrder & customerOrder)
{
	this->setFileToWorkWith("customerOrderList.txt");
	std::ofstream fileToWriteTo(this->fileToWorkWith, std::ios::app);
	if (customerOrder.getOrderedItems().getSize() != 0)
		if (fileToWriteTo.is_open()) {
			fileToWriteTo << customerOrder.getCustomer().getCustomerName() << " " << customerOrder.getCustomer().getCustomerSurname() << " "
				<< customerOrder.getCustomer().getCustomerPesel() << " " << customerOrder.getOrderedItems().getSize() << std::endl;

			for (int i = 0; i < customerOrder.getOrderedItems().getSize(); i++) {
				fileToWriteTo << customerOrder.getOrderedItems().getItem(i)->productName;
				fileToWriteTo << " ";
				fileToWriteTo << customerOrder.getOrderedItems().getItem(i)->productType;
				fileToWriteTo << " ";
				fileToWriteTo << customerOrder.getOrderedItems().getItem(i)->productId;
				fileToWriteTo << " ";
				fileToWriteTo << customerOrder.getOrderedItems().getItem(i)->numberOfItemsInStock;
				fileToWriteTo << " ";
				fileToWriteTo << std::endl;
			}
		}
	fileToWriteTo.close();
}

void FileManager::rewriteOrdersToFile(CustomerOrderList& customerOrderList)
{
	this->setFileToWorkWith("customerOrderList.txt");
	CustomerOrder* pom = customerOrderList.getHead();
	std::ofstream fileToWriteTo(this->fileToWorkWith);
	int i = 0;

	while (pom != nullptr) {

		if (fileToWriteTo.is_open()) {
			fileToWriteTo << pom->getCustomer().getCustomerName() << " " << pom->getCustomer().getCustomerSurname() << " "
				<< pom->getCustomer().getCustomerPesel() << " " << pom->getOrderedItems().getSize() << std::endl;

			for (int i = 0; i < pom->getOrderedItems().getSize(); i++) {
				fileToWriteTo << pom->getOrderedItems().getItem(i)->productName;
				fileToWriteTo << " ";
				fileToWriteTo << pom->getOrderedItems().getItem(i)->productType;
				fileToWriteTo << " ";
				fileToWriteTo << pom->getOrderedItems().getItem(i)->productId;
				fileToWriteTo << " ";
				fileToWriteTo << pom->getOrderedItems().getItem(i)->numberOfItemsInStock;
				fileToWriteTo << " ";
				fileToWriteTo << std::endl;
			}
			pom = pom->nextOrder;
		}
	}
		fileToWriteTo.close();
}

void FileManager::readOrdersFromFile(CustomerOrderList & customerOrderList)
{
	std::string customerName, customerSurname, customerPesel;
	int numberOfItems = 0;

	this->setFileToWorkWith("customerOrderList.txt");
	std::ifstream fileToReadFrom(this->fileToWorkWith);

	if (fileToReadFrom.is_open()) {
		while (!fileToReadFrom.eof()) {
			customerName = "";
			CustomerOrder *customerOrder = new CustomerOrder;
			fileToReadFrom >> customerName;
			fileToReadFrom >> customerSurname;
			fileToReadFrom >> customerPesel;
			fileToReadFrom >> numberOfItems;

			if (customerName != "") {
				//ProductList *orderedProductList = new ProductList;
				//orderedProductList.clearList();
				for (int i = 0; i < numberOfItems; i++) {
					Product* orderedProduct = new Product;
					fileToReadFrom >> orderedProduct->productName;
					fileToReadFrom >> orderedProduct->productType;
					fileToReadFrom >> orderedProduct->productId;
					fileToReadFrom >> orderedProduct->numberOfItemsInStock;
					if (orderedProduct->productName != "NA")
						customerOrder->getOrderedItems().addProduct(orderedProduct);

					else
						delete orderedProduct;
				}
				Customer* customer = new Customer(customerName, customerSurname, customerPesel);
				customerOrder->setCustomer(*customer);
				customerOrder->setProductList(customerOrder->getOrderedItems());
				customerOrderList.addOrder(customerOrder);
				delete customer;
			}
			if(customerName == "")
				delete customerOrder;
		}
	}
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
			else
				delete product;
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
