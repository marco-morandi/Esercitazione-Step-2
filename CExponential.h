/*! @file CExponential.h
	@brief Class Exponential: class to represent exponential function
	@author Igor Coppola - Marco Morandi 

	Details.
*/ 


#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CFunction.h"

using namespace std;

/// @brief  class that describe the exponential function

class Exponential : public Function  {
private:
    double b_coeff; //base of the exponential
    double k_coeff; //coefficient of the base
    double c_coeff; //coefficient of the variable

public:
    
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
        Exponential();
        Exponential(const Exponential &E);
        Exponential(double b, double k, double c);
        ~Exponential();
   
	/// @}

	/// @name OPERATORS 
	/// @{
        Exponential& operator=(const Exponential& p);
        bool operator==(const Exponential& p);
        Exponential operator+(const Exponential& e1);
	/// @}

    /// @name SETTER / GETTERS
    /// @{
        void SetParam(double b, double k, double c);
        void SetBase(double b);
        void SetCoefficient(double k);
        void SetEx(double c);

        double GetValue(double in);
    ///}

    /// @name BASIC HANDLERS
    /// @{
        void Reset();
    ///}

	/// @name DEBUG / SERIALIZATION
    /// @{
	void Dump();
    void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	/// @}


};

#endif