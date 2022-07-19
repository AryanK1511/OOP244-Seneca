/*
*****************************************************************************
                              Account.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

#include "iAccount.h"

namespace sdds {
    class Account : public iAccount {
    private:
        double currBalance;
    protected:
        //  Returns the current balance of the account
        double balance() const;

    public:
        // Initializes current bank balance
        Account(double);

        // Returns success of credit transaction
        virtual bool credit(double);

        // Returns success of the debit transaction
        virtual bool debit(double);
    };
}

#endif