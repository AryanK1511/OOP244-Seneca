/*
*****************************************************************************
                              Minister.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Minister.h"
#include <iomanip>
#include <cstring>

namespace sdds {
    Minister::Minister() {
        setEmpty();
    }

    Minister::Minister(const char* id, int age, double year, const char* name_of_PM, const char* district) : MemberParliament(id, age) {
        MemberParliament::NewDistrict(district);
        strcpy(PM_name, name_of_PM);
        this->year = year;
    }

    // A mutator that updates the PM the minister reports to.
    void Minister::changePM(const char* pm) {
        strcpy(PM_name, pm);
    }

    // A mutator that updates the year the minister assumed office
    void Minister::assumeOffice(double year) {
        this->year = year;
    }

    // A query that inserts into os the content of the object in the format
    std::ostream& Minister::write(std::ostream& os) const {
        os << "| " << getID() << " | " << getAge() << " | " << getDistrict() << " | " << PM_name << "/" << year;
        return os;
    }

    // A mutator that reads from the stream in the data for the current object
    std::istream& Minister::read(std::istream& in) {
        char reports_to[MAX_PM_NAME_LEN];
        double office_year;

        MemberParliament::read(in);
        std::cout << "Reports TO: ";
        in >> reports_to;
        std::cout << "Year Assumed Office: ";
        in >> office_year;
        setName(reports_to);
        setYear(office_year);

        return in;
    }

    // Overloading the insertion and extraction operators
    std::ostream& operator<<(std::ostream& os, const Minister& minister) {
        return minister.write(os);
    }
    std::istream& operator>>(std::istream& is, Minister& minister) {
        return minister.read(is);
    }

    // Sets all members to safe empty state;
    void Minister::setEmpty() {
        MemberParliament::setEmpty();
        PM_name[0] = '\0';
        year = 0;
    }

    // Setters
    void Minister::setName(const char* name) {
        strcpy(PM_name, name);
    }
    void Minister::setYear(double year) {
        this->year = year;
    }
}