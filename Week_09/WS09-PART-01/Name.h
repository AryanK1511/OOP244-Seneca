/*
*****************************************************************************
                              Name.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 29 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include <iostream>

namespace sdds {
    class Name {
    private:
        char* m_name;
    public:
        // Constructors
        Name();
        Name(const char* name);

        // Rule of three goes here:
        virtual ~Name();
        Name(const Name& name);
        Name& operator=(const Name& name);

        // Returns the address of the dynamic Cstring
        virtual operator const char* () const;

        // Return true if name is not empty, otherwise, it returns false.
        virtual operator bool() const;

        // Inserts the Cstring value into ostr without going to new line if the Name is valid and then returns the ostr
        virtual std::ostream& display(std::ostream& ostr = std::cout) const;

        // Dynamically reads the Cstring from istr without any spaces (stops at space) and keeps the address in the m_value pointer
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    // Insertion and Extraction operator overloads
    std::ostream& operator<<(std::ostream& os, const Name& name);
    std::istream& operator>>(std::istream& is, Name& name);
};

#endif