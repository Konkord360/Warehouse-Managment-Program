#pragma once
#include "FileManagment.h"
#include "WarehouseSide.h"
#include "View.h"
class Warehouseman {
private:

public:
	void replenishReserve();
	void checkStockOfProducts();
	void reciveDelivery();
	void addProduct(ProductList& listOfProductsAvailableInWarehouse);
	void removeProduct(ProductList& listOfProductsAvailableInWarehouse);
};