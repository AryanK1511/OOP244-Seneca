/*
*****************************************************************************
                              ChequingAccount.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sdds {
    class ChequingAccount : public Account {
    private:
        double transactionFee;
        double monthlyFee;
    public:
        // This function stores the fee
        ChequingAccount(double, double, double);

        // This modifier credits the balance by the amount received and if successful debits the transaction fee from the balance
        bool credit(double);

        // This modifier debits the balance by the amount received and if successful debits the transaction fee from the balance
        bool debit(double);

        // This modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit
        void monthEnd();

        // Receives a reference to an ostream object and inserts the following output on separate lines to the object
        void display(std::ostream&) const;
    };
}

#endif