/// @file Polynomial.h
///	@brief Class Polynomial: declaration of the class Polynomial	
/// @author Marco Morandi - Igor Coppola

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "CFunction.h"

/// @class Polynomial
/// @brief Class that describes a polynomial
class Polynomial : public Function{

private:
	double* coeffs; // pointer to double that will point to the array of coefficients of the polynomial
	int degree; // degree of the polynomial 

public:

	/// @name CONSTRUCTORS / DESTRUCTOR
	/// @{
	Polynomial(); 
	Polynomial(const double* coefficients, int size);
	Polynomial(const Polynomial& p);
	~Polynomial();
	/// @}

	/// @name OPERATORS
	/// @{
	Polynomial& operator=(const Polynomial& p);
	bool operator==(const Polynomial& p);
	Polynomial operator+(const Polynomial& p); 
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Polynomial& p);
	void Reset();
	/// @}

	/// @name GETTERS / SETTERS
	/// @{
	void SetNewParam(const double* new_coeffs, int size); // changes coeffs and degree

	int GetDegree(); // returns the degree of the polynomial
	double GetValue(double x); // returns the value of the polynomail given a specific value of the variable
	/// @}

	/// @name DEBUG / SERIALIZATION
	/// @{
	void Dump();
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	/// @}

};


#endif