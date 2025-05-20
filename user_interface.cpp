/// @file User_Interface.cpp
/// @brief Implementation of the menu for the user
/// @author Morandi Marco - Coppola Igor

#include "user_interface.h"

/// @brief prints possible selections for the user
/// @return the user choice
int displayMenu()
{
    int choice;
    do
    {
        cout << "*****   MENU   ******" << "\n";
        cout << "0 - Exit" << "\n";
        cout << "1 - View all function in the list" << "\n";
        cout << "2 - Insert a function in the list" << "\n";
        cout << "3 - Delete a function from the list" << "\n";
        cout << "4 - Delete all function from the list" << "\n";
        cout << "5 - Select a function from the list" << "\n\n";

        cout << "Please insert your choice: " << "\n";
        cin >> choice;
        if (choice < 0 || choice > 5)
        {
            ErrorMessage("Invalid input. Please insert a number from 0 to 5 included");
        }
    } while (choice < 0 || choice > 5);

    return choice;
}

/// @brief print list of current function
/// @param list list of functions
void displayList(vector <Function*> list)
{
    int dim = list.size();
    if (list.empty())
    {
        cout << "Display List - The list is empty" << "\n";
        return;
    }
    for (int i = 0; i < dim; i++)
    {
        cout << " << i << -   ";
        list[i]->Dump();
        cout << "\n" << endl;
    }
}

/// @brief add an element at the end of the list
/// @param list list of current functions
void insertFunction(vector<Function*> list) {

    int choice = 0;

    // display available types of functions
    do {
        cout << "*** FUNCTIONS MENU ***\n\n";
        cout << "1 - Polynomial\n";
        cout << "2 - Power\n";
        cout << "3 - Exponential\n\n";

        cout << "Insert an option: ";
        cin >> choice;

        if (choice < 1 || choice > 3)
            ErrorMessage("Enter a valid option.\n");

    } while (choice < 1 || choice > 3);

    int ans = 1; // answer of the user for confirmation at the end

    switch (choice)
    {
    case 1:
    {
        int degree; // degree of the polynomial
        int size; // size of the array of coefficients


        // instatiation of pointer to polynomial
        Polynomial* p = new Polynomial;

        if (p == NULL) {
            ErrorMessage("Allocation didn't go as expected.");
            exit(-1);
        }

        while (ans != 0) {
            // enter the degree of the polynomial
            cout << "Enter the degree: ";
            cin >> degree;

            // create array of coefficients
            int size = degree + 1;
            double* coeff = new double[size];

            if (coeff == NULL) {
                ErrorMessage("Allocation didn't go as expected.");
                exit(-1);
            }

            // enter coefficients
            for (int i = 0; i < size; i++) {
                cout << "Enter coefficient of term of grade " << i;
                cin >> coeff[i];
            }

            p->SetNewParam(coeff, size);

            p->Dump();

            cout << "Is this the function you want to enter?\n0 - Yes\n1 - No\n";
            cin >> ans;

            if (ans == 0)
                list.push_back(p);
            else
                cout << "Enter the parameters another time\n\n";

            delete[] coeff;
        }

        break;
    }
    case 2:
    {
        // creating new exponent and new coefficient
        double e_coeff;
        double k_coeff;

        // instatiation of pointer to power
        Power* pw = new Power;

        if (pw == NULL) {
            ErrorMessage("Allocation didn't go as expected.");
            exit(-1);
        }


        while (ans != 0) {

            // enter exponent
            cout << "Enter the exponent: ";
            cin >> e_coeff;

            // enter coefficient
            cout << "Enter the coefficient: ";
            cin >> k_coeff;

            pw->SetParam(k_coeff, e_coeff);

            pw->Dump();

            cout << "Is this the function you want to enter?\n0 - Yes\n1 - No\n";
            cin >> ans;

            if (ans == 0) 
                list.push_back(pw);
            else
                cout << "Enter the parameters another time\n\n";
        }

        break;
    }
    case 3:
    {
        // creating new coefficients
        double b_coeff;
        double k_coeff_e;
        double c_coeff;

        // instatiation of pointer to exponential
        Exponential* e = new Exponential;

        if (e == NULL) {
            ErrorMessage("Allocation didn't go as expected.");
            exit(-1);
        }

        while (ans != 0) {

            // enter base of the exponential
            cout << "Enter the base of the exponential: ";
            cin >> b_coeff;

            // enter coefficient of the base
            cout << "Enter the coefficient of the base: ";
            cin >> k_coeff_e;

            // enter coefficient of the independent variable
            cout << "Enter the coefficient of the exponent: ";
            cin >> c_coeff;

            e->SetParam(b_coeff, k_coeff_e, c_coeff);

            cout << "Is this the function you want to enter?\n0 - Yes\n1 - No\n";
            cin >> ans;

            if (ans == 0)
                list.push_back(e);
            else
                cout << "Enter the parameters another time\n\n";

        }

        break;
    }

    default:
        break;
    }

    return;
}


void ErrorMessage(const char* string) {

	cout << "User_Interface - " << string << "\n";

}