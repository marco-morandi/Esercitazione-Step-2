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


int displayMenu();

void displayList(vector<Function*>& list);

void insertFunction(vector<Function*>& list);

void deleteFunction(vector<Function*>& list);

void flushList(vector<Function*>& list);

void selectFunction(vector<Function*>& list);

void ErrorMessage(const char* string);



#endif // USER_INTERFACE_H