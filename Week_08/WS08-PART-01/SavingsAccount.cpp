/*
*****************************************************************************
                              SavingsAccount.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

namespace sdds {
    // This function stores the rate
    SavingsAccount::SavingsAccount(double initialBalance, double interestRate) : Account(initialBalance) {
        if (interestRate > 0) {
            this->interestRate = interestRate;
        }
        else {
            this->interestRate = 0.0;
        }
    }

    // This modifier calculates the interest earned on the current balance and credits the account with that interest
    void SavingsAccount::monthEnd() {
        double interestEarned = 0;

        // Calculating the interest earned
        interestEarned = (Account::balance() * interestRate);
        Account::credit(interestEarned);
    }

    // Receives a reference to an ostream object and inserts the following output on separate lines to the object.
    void SavingsAccount::display(std::ostream& os) const {
        os << "Account type: Savings" << std::endl;
        os << "Balance: $" << std::setprecision(2) << std::fixed <<  Account::balance() << std::endl;
        os << "Interest Rate (%): " << std::setprecision(2) << std::fixed << interestRate * 100 << std::endl;
    }
}