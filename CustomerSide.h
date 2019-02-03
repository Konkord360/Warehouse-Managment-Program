#pragma once
#include "WarehouseSide.h"
#include "View.h"

class CustomerOrder;
class CustomerOrderList;
class Customer {
private:
	std::string name;
	std::string surname;
	std::string pesel;

	void addItemToOrder(ProductList &listOfOrderedItems, ProductList& listOfProductsAvailableInWarehouse);
	void finalizeOrder(CustomerOrder& customerOrder);
public:
	Customer() : name(""), surname(""), pesel("") {};
	Customer(const Customer &customer) : name(customer.name), surname(customer.surname), pesel(customer.pesel) {};
	Customer(std::string customerName, std::string customerSurname, std::string pesel) : 
		name(customerName), surname(customerSurname), pesel(pesel) {};
	void makeOrder(ProductList& listOfProductsAvailableInWarehouse, CustomerOrder& customerOrder);
	void cancelOrder();
	void reciveOrder(ProductList& listOfProductsAvailableInWarehouse, CustomerOrderList& orderList);

	Customer& operator=(Customer&& customer);
	Customer& operator=(Customer& customer);
	std::string getCustomerName();
	std::string getCustomerSurname();
	std::string getCustomerPesel();
};

class CustomerOrder {
private:
	Customer customer;
	ProductList orderedItems;
public:
	CustomerOrder *nextOrder;
	CustomerOrder() :customer(), orderedItems(), nextOrder(nullptr) {};
	CustomerOrder(Customer customer, ProductList orderedItems) : customer(customer), orderedItems(orderedItems), nextOrder(nullptr) {};
	ProductList& getOrderedItems();
	Customer& getCustomer();

	void setProductList(ProductList& productList);
	void setCustomer(Customer& customer);

	CustomerOrder& operator=(CustomerOrder&& order);
};

class CustomerOrderList {
private: 
	CustomerOrder* head;
public:
	CustomerOrderList() : head(nullptr) {};
	void addOrder(CustomerOrder* customerOrder);
	void removeOrder();
	CustomerOrder* getOrder(std::string pesel);
	CustomerOrder* getHead();
	~CustomerOrderList();
};