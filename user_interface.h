/// @file User_Interface.h
/// @brief declaration of functions used for the user interface
/// @author Morandi Marco - Coppola Igor


#ifndef USER_INTERFACE_H
#define USER_INtERFACE_H
 
#include <stdio.h>
#include <vector>

#include "CExponential.h"
#include "CFunction.h"
#include "Power.h"
#include "Polynomial.h"

/// @brief prints possible selections for the user
/// @return the user choice
int displayMenu();

/// @brief prints list of current functions
/// @param list list of current functions
void displayList(vector<Function*> list);

/// @brief add an element at the end of the list
/// @param list list of current functions
void insertFunction(vector<Function*> list);

/// @brief delete an element from the list
/// @param list list of current functions
void deleteFunction(vector<Function*> list);

/// @brief delete all functions from the list
/// @param list list of current 
void flushList(vector<Function*> list);

/// @brief Select a function. Can print the value of the function given a specific input
/// @param list list of current functions
void selectFunction(vector<Function*> list);

/// @brief print an error message
/// @param string message to be printed
void ErrorMessage(const char* string);



#endif // USER_INTERFACE_H