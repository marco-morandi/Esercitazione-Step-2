/// @file CExponential.cpp
///	@brief Class Exponential: implementations of the exponential function
/// @author Marco Morandi - Igor Coppola

#include <iostream> 
#include <cmath>

using namespace std;

#include "CExponential.h"

/// @brief default constructor
Exponential::Exponential() {

	SetParam(1,0,0);
	
}

/// @brief costructor
/// @param b base of the exponential function
/// @param k coefficient that moltiply the base
/// @param c coefficient that moltiply the free variable of the exponential function
Exponential::Exponential(double b, double k, double c)
{

    SetParam(b, k, c);
}

/// @brief copy costructor 
Exponential::Exponential(const Exponential &E)
{

    SetParam(E.b_coeff, E.k_coeff, E.c_coeff);
}

/// @brief destructor 
Exponential::~Exponential()
{
    
}

/// @brief operator =
/// @param p reference to the exponential function on the right side of the operator
/// @return reference to the exponential function on the left side of the operator
Exponential& Exponential::operator=(const Exponential& p)
{
    
    SetParam(p.b_coeff, p.k_coeff, p.c_coeff);

    return *this;
}

/// @brief operator == 
/// @param p reference to the exponential function on the right side of the operator
/// @return true if every param of the exponential function on the left is equal to the right exponential function param

bool Exponential::operator==(const Exponential& p)
{
    if(b_coeff == p.b_coeff && k_coeff == p.k_coeff && c_coeff == p.c_coeff)
    {
        return true;
    }
    return false;
}


/// @brief Reset
void Exponential :: Reset()
{
    SetParam(1, 0, 0);
}

/// @brief Set all essential parameters of an exponential function
/// @param b base of the exponential function
/// @param k coefficient that moltiply the base 
/// @param c coefficient that moltiply the free variable of the exponential function
void Exponential::SetParam(double b, double k, double c)
{
    if(b > 0)
    {
        b_coeff = b;
        k_coeff = k;
        c_coeff = c;
    }
    else {
        ErrorMessage("Invalid base value. Base value must be > 0, setting base to 1 by default");
        SetParam(1,0,0);

    }
}

/// @brief Set ONLY the base of the exponential function
/// @param b base of the exponential function
void Exponential::SetBase(double b)
{
    b_coeff = b;
}

/// @brief Set ONLY the coefficient that moltiply the base of the exponential function
/// @param k coefficient that moltiply the base
void Exponential::SetCoefficient(double k)
{
   k_coeff = k;
}

/// @brief Set ONLY the coefficient that moltiply the exponent of the exponential function
/// @param c coefficient that moltiply the free variable of the exponential function
void Exponential::SetEx(double c)
{
    c_coeff = c;
}

/// @brief GetValue of the exponential function 
/// @param in value of the free variable
/// @return the value of the entire exponential function (k*b^(c*x))
double Exponential::GetValue(double in)
{
    double x = in;
    double exponent = c_coeff * x;
    double result = k_coeff * (pow(b_coeff,exponent));
    return result;
}

/// @brief prints the dump of the object
void Exponential::Dump()
{

    cout << k_coeff << "*" << b_coeff << "^(" << c_coeff << "x)" << "\n\n"; 

}

/// @brief write an error message 
/// @param string message to be printed
void Exponential::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Exponential --";
	cout << string << endl;

}

/// @brief write an warning message 
/// @param string message to be printed
void Exponential::WarningMessage(const char *string)
{
    cout << endl << "Error -- Exponential --";
    cout << string << endl;
}

/// @brief do sum of the exponential
/// @param p reference to the exponential function on the right side of the operator
/// @return return the exponential function that was obtained by the sum of two exponential function
Exponential Exponential :: operator+(const Exponential& e1)
{
    if (c_coeff != e1.c_coeff || b_coeff != e1.b_coeff)
    {
        ErrorMessage("Operator = : Impossible to execute the sum, because exponent coeffs are different (or base coeff). By defaut it will be returned the first exponent that was summed.");
        return *this;
    }
    Exponential e_res;
    double new_k_coeff = k_coeff + e1.k_coeff;
    e_res.SetParam(b_coeff, new_k_coeff, c_coeff);
    return e_res;
}