/*
*****************************************************************************
                              FullName.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 29 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "FullName.h"
#include "Name.h"
#include <cstring>

namespace sdds {
    // Constructors
    FullName::FullName() {
        m_surname = nullptr;
    }

    FullName::FullName(const char* name, const char* lastName) : Name(name) {
        if (lastName) {
            m_surname = new char[strlen(name) + 1];
            strcpy(m_surname, name);
        }
        else {
            m_surname = nullptr;
        }
    }

    // Rule of three goes here:
    FullName::~FullName() {
        delete[] m_surname;
        m_surname = nullptr;
    }

    // Copy constructor
    FullName::FullName(const FullName& fullname): Name(fullname) {
        m_surname = new char[strlen(fullname.m_surname) + 1];
        strcpy(m_surname, fullname.m_surname);
    }

    // Overloading the Assignment Operator
    FullName& FullName::operator=(const FullName& fullname) {
        Name::operator=(fullname);
        if (m_surname) {
            delete[] m_surname;
            m_surname = nullptr;
        }
        m_surname = new char[strlen(fullname.m_surname) + 1];
        strcpy(m_surname, fullname.m_surname);
        return *this;
    }

    // Returns the address in the m_value of the FullName
    FullName::operator const char* () const {
        return m_surname;
    }

    // Returns true only if both FullName and Name are not empty
    FullName::operator bool() const {
        return (m_surname != nullptr && Name::operator bool());
    }

    // It will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line
    std::ostream& FullName::display(std::ostream& ostr) const {
        if (*this) {
            Name::display(ostr) << " " << m_surname;
        }
        return ostr;
    }

    // Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character
    std::istream& FullName::read(std::istream& istr) {
        char temp[1024];
        Name::read(istr);
        istr.getline(temp, 1024, '\n');

        if (m_surname) {
            delete[] m_surname;
            m_surname = nullptr;
        }

        if (istr) {
            m_surname = new char[strlen(temp) + 1];
            strcpy(m_surname, temp);
        }


        return istr;
    }
}