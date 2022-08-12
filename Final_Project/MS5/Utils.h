/***********************************************************************
// OOP244 Utils Module
// File  utils.h
// Version
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>

namespace sdds {
    // Gets an integer as input and validates the range as well. It prints a message if the range isn't valid and prompts again
    int getIntegerInput(int minRange, int maxRange, const char* message = "Invalid Selection, try again: ");
}

#endif
