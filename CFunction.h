/*! @file CFunction.h
	@brief A virtual base class for functions of a single variable
	@author Marco Morandi - Igor Coppola

*/ 

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Function {
	
		
public:
    
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Function(){};
    virtual ~Function(){};
	/// @}

	/// @name GETTERS
	/// @{
	virtual double GetValue(double in)=0;
	/// @}

	/// @name DEBUG / SERIALIZATION
	/// @{
	virtual void Dump()=0;
	virtual void ErrorMessage(const char* string) = 0;
	virtual void WarningMessage(const char* string) = 0;
	/// @}

};

#endif