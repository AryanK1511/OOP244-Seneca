/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "Utils.h"

namespace sdds {
    // Gets an integer as input and validates the range as well. It prints a message if the range isn't valid and prompts again
    int getIntegerInput(int minRange, int maxRange, const char* message) {
        int input;
        bool validInt = false;
        while (validInt == false)
        {
            cin >> input;
            if (!cin || input < minRange || input > maxRange)
            {
                std::cout << message;
                cin.clear();
                cin.ignore(1000, '\n');
                validInt = false;
            }
            else
            {
                validInt = true;
            }

        }
        return input;
    }
}