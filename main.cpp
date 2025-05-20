/// @file main.cpp
/// @brief main program running
/// @author Morandi Marco - Coppola Igor

#include <stdio.h>
#include <vector>

#include "CExponential.h"
#include "CFunction.h"
#include "Power.h"
#include "Polynomial.h"
#include "user_interface.h"


int main() {

	// creating empty list of functions
	vector<Function*> List;

	// creating variable for user choice
	int choice = -1;

	// program loop
	while (choice != 0) {

		// get the user choice
		choice = displayMenu();
		
		// call the function corresponding to the user choice
		switch (choice)
		{
		case 0:
			break;

		case 1:
			displayList(List);
			break;

		case 2:
			insertFunction(List);
			break;
		
		case 3:
			deleteFunction(List);
			break;

		case 4:
			flushList(List);
			break;
		
		case 5:
			selectFunction(List);
			break;
		
		default:
			cout << "Please, enter a valid option";
			break;
		}
		 
	}

	
	return 0;
}