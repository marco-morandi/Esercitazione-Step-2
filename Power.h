/// @file Power.h
/// @brief Class Power: declaration of a class for power function inherited from CFuntion.h
/// @author Marco Morandi

#ifndef POWER_H
#define POWER_H

#include "CFunction.h"

/// @class Power
/// @brief Class that describes the power function 
class Power : public Function {

private: 

    double k_coeff; // describes the coefficient of independent variable
    double e_coeff; // describes the exponent of the independent variable

public: 
    
    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    Power();
    Power(double k, double e);
    Power(const Power& p);
    ~Power();
    /// @}

    /// @name OPERATORS
    /// @{
    Power& operator=(const Power& p);
    bool operator==(const Power& p);
    Power operator+(const Power& p);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Reset();
    /// @}

    /// @name GETTERS / SETTERS
    /// @{
    double GetValue(double in);
    
    void SetParam(double k, double e);
    void SetCoeff(double k);
    void SetExp(double e);
    /// @}

    /// @name DEBUG / SERIALIZATION
    /// @{
    void Dump();
    void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
    /// @}

};

#endif // POWER_H