/// @file User_Interface.cpp
/// @brief Implementation of the menu for the user
/// @author Morandi Marco - Coppola Igor

#include <unistd.h>

#include "user_interface.h"
#include "safeInput.hpp"

/// @brief prints possible selections for the user
/// @return the user choice
int displayMenu()
{
    int choice;

    do
    {

        cout << "\n*****   MENU   ******" << "\n";
        cout << "0 - Exit" << "\n";
        cout << "1 - View all function in the list" << "\n";
        cout << "2 - Insert a function in the list" << "\n";
        cout << "3 - Delete a function from the list" << "\n";
        cout << "4 - Delete all function from the list" << "\n";
        cout << "5 - Select a function from the list" << "\n\n";

        while (true) {

            cout << "Please insert your choice: ";
            if (safeInput<int>(choice))
                break;

        }

        if (choice < 0 || choice > 5)
            ErrorMessage("Invalid input. Please insert a number from 0 to 5 included");

    } while (choice < 0 || choice > 5);

    return choice;
}

/// @brief print list of current function
/// @param list list of functions
void displayList(vector <Function*>& list)
{
    cout << "\n*** FUNCTION LIST ***\n\n";

    int dim = (int)list.size();
    if (list.empty())
    {
        cout << "WARNING: The list is empty" << "\n";
        return;
    }
    for (int i = 0; i < dim; i++)
    {
        cout << i << ". f(x) = ";
        list[i]->Dump();
        cout << "\n" << endl;
    }
}

/// @brief add an element at the end of the list
/// @param list list of current functions
void insertFunction(vector<Function*>& list) {

    int choice;

    // display available types of functions
    do {
        cout << "\n*** OPTIONS AVAILABLE ***\n\n";
        cout << "1 - Polynomial\n";
        cout << "2 - Power\n";
        cout << "3 - Exponential\n";
        cout << "0 - Exit\n\n";

        cout << "Insert an option: ";

        while (true) {

            cout << "Insert an option: ";
            if (safeInput<int>(choice))
                break;

        }

        if (choice < 0 || choice > 3)
            ErrorMessage("Enter a valid option.\n");

    } while (choice < 0 || choice > 3);

    if (choice == 0)
        return;

    int ans = 1; // answer of the user for confirmation at the end
    int option = 0; // get the user choice whether he wants to exit or not after he declined the confirmation

    switch (choice)
    {
    case 1: {
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
            while (true) {
                
                cout << "Enter the degree: ";
                if (safeInput<int>(degree)) 
                    break;
                
            }
            

            // create array of coefficients
            size = degree + 1;
            double* coeff = new double[size];

            if (coeff == NULL) {
                ErrorMessage("Allocation didn't go as expected.");
                exit(-1);
            }

            // enter coefficients
            for (int i = 0; i < size; i++) {

                while (true) {

                    cout << "\nEnter coefficient of term of grade " << i << ": ";
                    if (safeInput<double>(coeff[i]))
                        break;

                }
            }

            p->SetNewParam(coeff, size);

            // printing the function to the screen
            cout << "\nf(x) = ";
            p->Dump();

            do {

                while (true) {

                    cout << "Is this the function you want to enter?\n0 - Yes\n1 - No\n";
                    if (safeInput<int>(ans))
                        break;

                }

                if (ans != 0 && ans != 1)
                    cout << "Please, enter a valid option.\n";

            } while (ans != 0 && ans != 1);

            if (ans == 0)
                list.push_back(p);
            else {
                
                do {

                    while (true) {

                        cout << "\nChoose an option:\n0 - Get back to the menu\n1 - Enter new parameters\n";
                        if (safeInput<int>(option))
                            break;

                    }

                    if (option != 0 && option != 1)
                        cout << "Please, enter a valid option.\n";

                } while (option != 0 && option != 1);
            }

            delete[] coeff;

            if (option == 0)
                break;
        }

        break;
    }
    case 2: {
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
            while (true) {

                cout << "Enter the exponent: ";
                if (safeInput<double>(e_coeff))
                    break;

            }
           

            // enter coefficient
            while (true) {

                cout << "Enter the coefficient: ";
                if (safeInput<double>(k_coeff))
                    break;

            }

            pw->SetParam(k_coeff, e_coeff);

            // printing the function to the screen
            cout << "\nf(x) = ";
            pw->Dump();

            do {

                while (true) {

                    cout << "Is this the function you want to enter?\n0 - Yes\n1 - No\n";
                    if (safeInput<int>(ans))
                        break;

                }

                if (ans != 0 && ans != 1)
                    cout << "Please, enter a valid option.\n";

            } while (ans != 0 && ans != 1);

            if (ans == 0)
                list.push_back(pw);
            else {

                do {

                    while (true) {

                        cout << "\nChoose an option:\n0 - Get back to the menu\n1 - Enter new parameters\n";
                        if (safeInput<int>(option))
                            break;

                    }

                    if (option != 0 && option != 1)
                        cout << "Please, enter a valid option.\n";

                } while (option != 0 && option != 1);
            }

            if (option == 0)
                break;
        }

        break;
    }
    case 3: {
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
            
            while (true) {

                cout << "Enter the base of the exponential: ";
                if (safeInput<double>(b_coeff))
                    break;

            }


            // enter coefficient of the base
            while (true) {

                cout << "Enter the coefficient of the base: ";
                if (safeInput<double>(k_coeff_e))
                    break;

            }

            // enter coefficient of the independent variable
            while (true) {

                cout << "Enter the coefficient of the x: ";
                if (safeInput<double>(c_coeff))
                    break;

            }

            e->SetParam(b_coeff, k_coeff_e, c_coeff);

            // printing the function to the screen
            cout << "\nf(x) = ";
            e->Dump();

            do {

                while (true) {

                    cout << "Is this the function you want to enter?\n0 - Yes\n1 - No\n";
                    if (safeInput<int>(ans))
                        break;

                }

                if (ans != 0 && ans != 1)
                    cout << "Please, enter a valid option.\n";

            } while (ans != 0 && ans != 1);

            if (ans == 0)
                list.push_back(e);
            else {

                do {

                    while (true) {

                        cout << "\nChoose an option:\n0 - Get back to the menu\n1 - Enter new parameters\n";
                        if (safeInput<int>(option))
                            break;

                    }

                    if (option != 0 && option != 1)
                        cout << "Please, enter a valid option.\n";

                } while (option != 0 && option != 1);
            }

            if (option == 0)
                break;
 
        }

        break;
    }

    default:
        break;
    }

    return;
}

/// @brief delete an element of the list
/// @param list list of function 
/// @return 0 if insertion went smootly
void deleteFunction(vector <Function*>& list)
{
    int choice;

    //Controlling how many function are inside the list
    int dim = (int)list.size();

    cout << "\n*** DELETION MODE ***\n\n";

    //Controll if the list is empty
    if (list.empty())
    {
        cout << "WARNING: The list is empty" << "\n";
        return;
    }

    do
    {

        while (true) {

            cout << "ID of the function to be deleted (-1 to exit deletion mode): ";
            if (safeInput<int>(choice))
                break;

        }

        if (choice >= dim || choice < 0)
        {
            ErrorMessage("There is no function with the ID inserted");
            cout << "\nChoose from these possible IDs:" << "\n";
            //Print all element of the list, so that rhe user can see all the possible value ID

            displayList(list);

            cout << "Please insert a valid ID" << endl;
        }

    } while (choice >= dim || choice < -1);

    //check if the user wants to exit
    if (choice == -1)
        return;

    cout << "\nThe function with the inserted ID is: f(x) = ";
    list[choice]->Dump();

    int cancel; // get the answer of the user

    do {
        
        while (true) {

            cout << "Do you want to delete this function?\n0 - Yes\n1 - No\n";
            if (safeInput<int>(cancel))
                break;

        }

        if (cancel != 0 && cancel != 1)
            cout << "Invalid input. Please insert a valid option." << "\n";

    } while (cancel != 0 && cancel != 1);

    if (cancel == 0)
    {
        if ( list[choice] != NULL ) {
            delete list[choice];
            list[choice] = NULL;
        }
        list.erase(list.begin() + choice);
        cout << "Deletion completed.\n";
    }

    return;

}

/// @brief delete all function from the list
/// @param list list of functions
/// @return 0 if insertion went smootly
void flushList(vector <Function*>& list)
{
    int dim = (int)list.size();
    //Controlling if the list is empty
    if (list.empty())
    {
        cout << "WARNING: The list is empty" << "\n";
        return;
    }

    cout << "FLUSHING LIST";
    sleep(750);
    cout << ".";
    sleep(750);
    cout << ".";
    sleep(750);
    cout << ".";
    sleep(750);
    cout << "\n";

    // deallocation of all the elements of the list
    for (int i = 0; i < dim; i++)
    {
        if (list[i] != NULL)
        {
            delete list[i];
            list[i] = NULL;
        }
    }

    list.clear();
    cout << "List cleared!\n";
}

void selectFunction(vector <Function*>& list)
{
    int choice;

    //Controlling how many function are inside the list
    int dim = (int)list.size();

    cout << "\n*** SELECT FUNCTION ***" << "\n\n";
    //Controll if the list is empty
    if (list.empty())
    {
        cout << "Select Function - The list is empty" << "\n";
        return;
    }

    do
    {

        while (true) {

            cout << "ID of the function to get the resulting value (-1 to exit): ";
            if (safeInput<int>(choice))
                break;

        }

        if (choice >= dim || choice < 0)
        {
            ErrorMessage("There is no function with the ID inserted");
            cout << "Choose from these possible IDs:" << "\n";
            //Print all element of the list, so that the user can see all the possible value ID

            displayList(list);

            cout << "Please insert a valid ID: \n";
        }
    } while (choice >= dim || choice < -1);

    //Function of interest
    cout << "\nThe function with the inserted ID is: f(x) = ";
    list[choice]->Dump();

    
    int ans; // answer of the user

    do {

        while (true) {

            cout << "Do you want to calculate the value of this function?\n0 - Yes \n1 - No " << "\n";
            if (safeInput<int>(ans))
                break;

        }

        if (ans != 0 && ans != 1)
            cout << "Invalid input. Please insert a valid option." << "\n";

    } while (ans != 0 && ans != 1);


    if (ans == 0)
    {
        //Setting the value of the free variable
        double x;
        
        while (true) {

            cout << "\nInsert the value of x: ";
            if (safeInput<double>(x))
                break;

        }

        cout << "CALCULATING";
        sleep(750);
        cout << ".";
        sleep(750);
        cout << ".";
        sleep(750);
        cout << ".";
        sleep(750);
        cout << "\n";
        cout << "f(" << x << ") = " << list[choice]->GetValue(x) << "\n";
    }
    else 
        return;
}



void ErrorMessage(const char* string) {

	cout << "User_Interface - ERROR: " << string << "\n";

}