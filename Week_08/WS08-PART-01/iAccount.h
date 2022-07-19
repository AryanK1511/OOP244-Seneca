/*
*****************************************************************************
                              iAccount.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H

#include <iostream>

namespace sdds {
    class iAccount {
    public:
        // Public empty virtual destructor
        virtual ~iAccount(){};

        // Adds a positive amount to the account balance
        virtual bool credit(double) = 0;

        // Subtracts a positive amount from the account balance
        virtual bool debit(double) = 0;

        // Applies month-end transactions to the account
        virtual void monthEnd() = 0;

        // Inserts account information into an ostream object
        virtual void display(std::ostream&) const = 0;
    };
    // Creates the account with the starting balance and returns its address.
    iAccount* CreateAccount(const char*, double);
}

#endif