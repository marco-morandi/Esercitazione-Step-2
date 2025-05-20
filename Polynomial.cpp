/// @file Polynomial.cpp
///	@brief Class Polynomial: implementations of the functions
/// @author Marco Morandi - Igor Coppola

#include <iostream>
#include <cmath>

#include "Polynomial.h"

using namespace std;

/// @brief default constructor
Polynomial::Polynomial() {

	cout << "*** Polynomial - Default Constructor ***\n\n";

	Init();
	
}

/// @brief constructor
/// @param coefficients array with the coefficients of the polynomial
/// @param size size of the array
Polynomial::Polynomial(const double* coefficients, int size) {

	cout << "*** Polynomial - Constructor ***\n\n";
	
	Init();

	SetNewParam(coefficients, size);

}

/// @brief copy constructor
/// @param p reference to the object to copy
Polynomial::Polynomial(const Polynomial& p) {

	cout << "*** Polynomial - Copy Constructor ***\n\n";

	Init();

	int size = p.degree + 1;

	SetNewParam(p.coeffs, size);

}

/// @brief destructor 
Polynomial::~Polynomial() {

	cout << "*** Polynomial - Destructor ***\n\n";

	Reset();

}

/// @brief overload of operator = 
/// @param p reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
Polynomial& Polynomial::operator=(const Polynomial& p) {

	cout << "*** Polynomial - operator= ***" << "\n\n";

	Reset();

	SetNewParam(p.coeffs, p.degree+1);

	return *this;
}

/// @brief overload of operator ==
/// @param p reference to the object on the right side of the operator
/// @return true if the two polynomials have the same degree and the same coefficients
bool Polynomial::operator==(const Polynomial& p) {

	if (p.degree != degree)
		return false;

	for (int i = 0; i <= degree; i++) {
		if (coeffs[i] != p.coeffs[i])
			return false;
	}

	return true;

}

/// @brief overload of operator +
/// @param p reference to the object on the right side of the operator
/// @return p_sum polynomial that is the sum of the two polynomials
Polynomial Polynomial::operator+(const Polynomial& p) {

	int MaxSize = max(degree, p.degree) + 1;

	double* new_coeffs = new double[MaxSize];

	if (new_coeffs == nullptr) {
		ErrorMessage("operator+ - The allocation didn't go as expected");
	}

	for (int k = 0; k < MaxSize; k++) {
		new_coeffs[k] = 0;
	}

	for (int i = 0; i <= degree; i++)
		new_coeffs[i] += coeffs[i];

	for (int j = 0; j <= p.degree; j++)
		new_coeffs[j] += p.coeffs[j];

	Polynomial p_sum(new_coeffs, MaxSize);

	if (new_coeffs) {
		delete[] new_coeffs;
		new_coeffs = 0;
	}

	return p_sum;
	
}


/*! @brief default initialization of the object

	A polynomial created by default is a polynommial with degree = 0 and the only coefficient being 1 

*/
void Polynomial::Init() {

	coeffs = 0;
	
	int size = 1; 
	
	double new_coeffs[1] = { 1. };

	SetNewParam(new_coeffs, size);
}

/// @brief initialization of an object as a copy of an object
/// @param p object to be copied
void Polynomial::Init(const Polynomial& p) {

	Init();

	int size = p.degree + 1;

	SetNewParam(p.coeffs, size);

}


/// @brief total reset of the object
void Polynomial::Reset() {

	if (coeffs) {
		delete[] coeffs;
		coeffs = 0;
	}
		
	degree = 0;

}


/// @brief modifying degree & coeffs of the polinomial 
/// @param new_coeffs array with the coefficients of the polynomial
/// @param size size of the array
void Polynomial::SetNewParam(const double* new_coeffs, int size) {

	if (size <= 0) {
		ErrorMessage("SetNewParam() - The size of the array should be a value greater than 0");
		return;
	}

	Reset();

	coeffs = new (nothrow) double[size];
	if (coeffs == 0) {
		ErrorMessage("SetNewParam() - The allocation didnt'go as expected: pointer to NULL");
		return;
	}

	degree = size - 1;
	for (int i = 0; i < size; i++) {
		coeffs[i] = new_coeffs[i];
	}

}

/// @brief function that returns the degree of the polynomial
/// @return degree the degree of the polynomial
int Polynomial::GetDegree() {

	return degree;

}

/// @brief function that returns the value of the polynomial given a specific value of the variable
/// @param x specific value of the variable
/// @return value the value of the polynomial given a specific value of the variable
double Polynomial::GetValue(double x) {

	double value = 0.;

	for (int i = 0; i <= degree; i++) {
		value += coeffs[i] * pow(x, i);
	}

	return value;

}

/// @brief print the dump of the object
void Polynomial::Dump() {

	cout << "*** Polynomial - Dump() ***\n\n";
	 
	if (degree == 0)
		cout << coeffs[0];
	else {
		for (int i = 0; i <= degree; i++) {
			if (coeffs[i] != 0) {
				cout << coeffs[i];
				cout << "(x^" << i << ")";
			}
			if (i != degree && coeffs[i+1] > 0)
				cout << "+";
		}
	}

	cout << "\n\n";
}

/// @brief write an error message 
/// @param string message to be printed
void Polynomial::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Polynomial -- ";
	cout << string << "\n\n";

}

/// @brief write a warning message 
/// @param string message to be printed
void Polynomial::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Polynomial -- ";
	cout << string << "\n\n";

}

