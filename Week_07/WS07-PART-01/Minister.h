/*
*****************************************************************************
                              Minister.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#define MAX_PM_NAME_LEN 50

#include "MemberParliament.h"
#include <iostream>

namespace sdds {
    class Minister : public MemberParliament {
    private:
        char PM_name[MAX_PM_NAME_LEN];
        double year;
    public:
        Minister();
        Minister(const char* id, int age, double year, const char* name_of_PM, const char* district);

        // A mutator that updates the PM the minister reports to.
        void changePM(const char* pm);

        // A mutator that updates the year the minister assumed office
        void assumeOffice(double year);

        // A query that inserts into os the content of the object in the format
        std::ostream& write(std::ostream& os = std::cout) const;

        // A mutator that reads from the stream in the data for the current object
        std::istream& read(std::istream& in = std::cin);

        // Sets all members to safe empty state;
        void setEmpty();

        // Setters
        void setName(const char* name);
        void setYear(double year);
    };
    // Overloading the insertion and extraction operators
    std::ostream& operator<<(std::ostream& os, const Minister& minister);
    std::istream& operator>>(std::istream& is, Minister& minister);
};

#endif //SDDS_MINISTER_H
