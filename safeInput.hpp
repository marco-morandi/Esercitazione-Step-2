/// @file safeInput.hpp
/// @brief template of the function that checks if the input type is the same as the one requested
/// @author Morandi Marco - Coppola Igor


#ifndef SAFEINPUT_HPP
#define SAFEINPUT_HPP

#include <iostream>

using namespace std;

template <class T>
bool safeInput(T& choice) {

	cin >> choice;

    if (cin.fail() == true) { // check if the input is an integer
        ErrorMessage("Enter the right type of input.\n");
        cin.clear();
        cin.ignore(256, '\n'); // ignore all the characters in the buffer
        return false;
    }

    return true;
}


#endif