/*
*****************************************************************************
                              Account.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Account.h"
#include <iostream>

namespace sdds {
    //  Returns the current balance of the account
    double Account::balance() const {
        return currBalance;
    }

    // Initializes current bank balance
    Account::Account(double amount) {
        if (amount < 0) {
            currBalance = 0.0;
        }
        else {
            currBalance = amount;
        }
    }

    // Returns success of credit transaction
    bool Account::credit(double amount) {
        bool success = false;
        if (amount > 0) {
            currBalance += amount;
            success = true;
        }

        return success;
    }

    // Returns success of the debit transaction
    bool Account::debit(double amount) {
        bool success = false;
        if (amount > 0) {
            currBalance -= amount;
            success = true;
        }

        return success;
    }
}