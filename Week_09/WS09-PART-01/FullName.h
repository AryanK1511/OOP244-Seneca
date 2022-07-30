/*
*****************************************************************************
                              FullName.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 29 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H

#include "Name.h"
#include <iostream>

namespace sdds {
    class FullName : public Name {
        char* m_surname;
    public:
        // Constructors
        FullName();
        FullName(const char* name, const char* lastName);

        // Rule of three goes here:
        ~FullName();
        FullName(const FullName& fullname);
        FullName& operator=(const FullName& fullname);

        // Returns the address in the m_value of the FullName
        operator const char* () const;

        // Returns true only if both FullName and Name are not empty
        virtual operator bool() const;

        // It will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line
        virtual std::ostream& display(std::ostream& ostr = std::cout) const;

        // Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character
        virtual std::istream& read(std::istream& istr = std::cin);
    };

};

#endif