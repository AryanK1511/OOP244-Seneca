/*
*****************************************************************************
                              SavingsAccount.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H

#include "Account.h"

namespace sdds {
    class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        // This function stores the rate
        SavingsAccount(double, double);

        // This modifier calculates the interest earned on the current balance and credits the account with that interest
        void monthEnd();

        // Receives a reference to an ostream object and inserts the following output on separate lines to the object.
        void display(std::ostream&) const;
    };
}

#endif