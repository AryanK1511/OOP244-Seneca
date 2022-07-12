/*
*****************************************************************************
                              MemberParliament.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "MemberParliament.h"
#include <iomanip>
#include <cstring>

namespace sdds {
    MemberParliament::MemberParliament() {
        setEmpty();
    }

    // A custom constructor that receives as parameters the MP Id and age. Set the district the MP represents as Unassigned.
    MemberParliament::MemberParliament(const char* id, int age) {
        strcpy(parliament_id, id);
        MP_age = age;
        strcpy(district_represented, "Unassigned");
    }

    // Assigns the MP to new district. Prints a message to the screen.
    void MemberParliament::NewDistrict(const char* district) {
        std::cout << "|  " << parliament_id << "| |" << std::setw(20) << std::right << district_represented << " ---> " << std::setw(23) << std::left << district << "|" << std::endl;
        strcpy(district_represented, district);
    }

    // A query that inserts into os the content of the object in the format
    std::ostream& MemberParliament::write(std::ostream& os) const {
        os << "| " << parliament_id << " | " << MP_age << " | " << district_represented;
        return os;
    }

    // A mutator that reads from the stream in the data for the current object
    std::istream& MemberParliament::read(std::istream& in) {
        std::cout << "Age: ";
        in >> MP_age;
        std::cout << "Id: ";
        in >> parliament_id;
        std::cout << "District: ";
        in >> district_represented;

        return in;
    }

    // Sets all members to safe empty state;
    void MemberParliament::setEmpty() {
        parliament_id[0] = '\0';
        district_represented[0] = '\0';
        MP_age = 0;
    }

    // Getters
    const char* MemberParliament::getID() const {
        return parliament_id;
    }

    const char* MemberParliament::getDistrict() const {
        return district_represented;
    }

    int MemberParliament::getAge() const {
        return MP_age;
    }

    // Overloading the insertion and extraction operators
    std::ostream& operator<<(std::ostream& os, const MemberParliament& member) {
        return member.write(os);
    }

    std::istream& operator>>(std::istream& is, MemberParliament& member) {
        return member.read(is);
    }
}