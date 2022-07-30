/*
*****************************************************************************
                              Name.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 29 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Name.h"
#include <cstring>

namespace sdds {
    // Constructors
    Name::Name() {
        m_name = nullptr;
    }

    Name::Name(const char* name) {
        if (name != nullptr) {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        else {
            m_name = nullptr;
        }
    }

    // Rule of three goes here:
    Name::~Name() {
        delete[] m_name;
        m_name = nullptr;
    }

    // Copy constructor
    Name::Name(const Name& name) {
        m_name = new char[strlen(name.m_name) + 1];
        strcpy(m_name, name.m_name);
    }

    // Overloading the assignment operator
    Name& Name::operator=(const Name& name) {
        if (m_name) {
            delete[] m_name;
            m_name = nullptr;
        }
        m_name = new char[strlen(name.m_name) + 1];
        strcpy(m_name, name.m_name);
        return *this;
    }

    // Returns the address of the dynamic Cstring
    Name::operator const char* () const {
        return m_name;
    }

    // Return true if name is not empty, otherwise, it returns false.
    Name::operator bool() const {
        return (m_name != nullptr);
    }

    // Inserts the Cstring value into ostr without going to new line if the Name is valid and then returns the ostr
    std::ostream& Name::display(std::ostream& ostr) const {
        if (m_name != nullptr) {
            ostr << m_name;
        }
        return ostr;
    }

    // Dynamically reads the Cstring from istr without any spaces (stops at space) and keeps the address in the m_value pointer
    std::istream& Name::read(std::istream& istr) {
        char temp[1024];
        istr.getline(temp, 1024, ' ');

        if (m_name) {
            delete[] m_name;
            m_name = nullptr;
        }

        if (istr) {
            m_name = new char[strlen(temp) + 1];
            strcpy(m_name, temp);
        }

        return istr;
    }

    // Insertion and Extraction operator overloads
    std::ostream& operator<<(std::ostream& os, const Name& name) {
        name.display(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Name& name) {
        name.read(is);
        return is;
    }
}