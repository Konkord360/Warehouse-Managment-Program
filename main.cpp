#include <iostream>
#include "View.h"

int main() {
	CommunicationManagement communicationManager;
	
	while (communicationManager.getUserInput() != mainMenuEnum(end)) {
		communicationManager.viewMainMenu();

		switch (communicationManager.getUserInput())
		{
		case '1': communicationManager.viewWarehousemanMenu();
			break;
		case '2': communicationManager.viewCustomerMenu();
			break;
		default:
			break;
		}
	}

	return 0;
}