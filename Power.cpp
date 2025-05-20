/// @file Power.cpp
///	@brief Class Power: implementations of the functions
/// @author Marco Morandi

#include <iostream>
#include <cmath>

#include "Power.h"

using namespace std;

/// @brief default constructor
Power::Power() {

    cout << "*** Power - Default Constructor ***\n\n";

    SetParam(0, 0);

}

/// @brief constructor
/// @param k coefficient of independent variable
/// @param e exponent of independent variable
Power::Power(double k, double e) {

    cout << "*** Power - Constructor ***\n\n";

    SetParam(k, e);

}

/// @brief copy constructor
/// @param p reference to object to be copied
Power::Power(const Power& p) {

    cout << "*** Power - Copy Constructor ***\n\n";

    SetParam(p.k_coeff, p.e_coeff);

}

/// @brief destructor
Power::~Power() {

    cout << "*** Power - Destructor ***\n\n";

}

/// @brief overload of operator =
/// @param p reference to object on the right side of the eoperator
/// @return reference to the object on the left side of the operator
Power& Power::operator=(const Power& p) {

    cout << "*** Power - operator = ***\n\n";

    SetParam(p.k_coeff, p.e_coeff);

    return *this;

}

/// @brief overload of operator ==
/// @param p reference to the object on the right side of the operator
/// @return true if the coefficient of the independent variable and the exponent are the same
bool Power::operator==(const Power& p) {

    if (k_coeff == p.k_coeff) {
        if (e_coeff == p.e_coeff)
            return true;
    }

    return false;

}

/// @brief overload of operator +
/// @param p reference to the object on the right side of the operator
/// @return p_sum that is the sum of the two power functions
Power Power::operator+(const Power& p) {

    if (e_coeff != p.e_coeff) { 
        ErrorMessage("operator+() - The power functions must have the same exponent in order to be summed; returning the starting power function (adding 0).");
        return *this;
    }

    double new_kcoeff = k_coeff + p.k_coeff;

    Power p_sum(new_kcoeff, e_coeff);

    return p_sum;

}


/// @brief total reset of the object
void Power::Reset() {

    SetParam(0, 0);

}

/// @brief returns the value of the power function given a specific value of the variable
/// @param in specific value of the independent variable
/// @return res result of the function calculated with that specific value
double Power::GetValue(double in) {

    double res = 0.;

    if ( in == 0 && e_coeff == 0) {
        ErrorMessage("GetValue() - 0^0 is undeterminate, returning -1 by defualt");
        res = -1;
    }
    else {
        
        res = k_coeff * pow(in, e_coeff);

    }

    return res;
}

/// @brief function that changes the parameters of the power function
/// @param k new coefficient
/// @param e new exponent
void Power::SetParam(double k, double e) {

    k_coeff = k;

    if ((e <= -1) || (e >= 1) || (e == 0)) 
        e_coeff = e;
    else { // can't manage even roots with possible negative base
        ErrorMessage("SetParam() - This function can't be a root, setting exponent to 1 by default");
        e_coeff = 1;
    }

}

/// @brief function that changes the coefficient of the independent variable
/// @param k new coefficient
void Power::SetCoeff(double k) {

    k_coeff = k;

}

/// @brief function that changes the exponent of the power function
/// @param e new exponent
void Power::SetExp(double e) {

    e_coeff = e;

}

/// @brief prints the dump of the object
void Power::Dump() {

    cout << "*** Power - Dump() ***\n\n";

    cout << k_coeff << " * x^" << e_coeff << "\n\n";

}

/// @brief write an error message 
/// @param string message to be printed
void Power::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Power -- ";
	cout << string << "\n\n";

}

/// @brief write a warning message 
/// @param string message to be printed
void Power::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Power -- ";
	cout << string << "\n\n";

}

