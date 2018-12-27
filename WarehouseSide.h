#pragma once
#include <iostream>

struct Product {
	std::string productName;
	std::string productType;
	std::string productId;
	std::string expirationDate;
};

class ProductList {
private:
	Product* productList;
public:
	void viewProducts();
	void addProduct();
	void removeProduct();
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