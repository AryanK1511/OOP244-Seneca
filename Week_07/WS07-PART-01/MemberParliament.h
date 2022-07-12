/*
*****************************************************************************
                              MemberParliament.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>

#define MAX_ID_LENGTH 32
#define MAX_DISTRICT_LENGTH 64

namespace sdds {
    class MemberParliament {
    private:
        char parliament_id[MAX_ID_LENGTH];
        char district_represented[MAX_DISTRICT_LENGTH];
        int MP_age;
    public:
        MemberParliament();

        // A custom constructor that receives as parameters the MP Id and age. Set the district the MP represents as Unassigned.
        MemberParliament(const char* id, int age);

        // Assigns the MP to new district. Prints a message to the screen.
        void NewDistrict(const char* district);

        // A query that inserts into os the content of the object in the format
        std::ostream& write(std::ostream& os = std::cout) const;

        // A mutator that reads from the stream in the data for the current object
        std::istream& read(std::istream& in = std::cin);

        // Sets all members to safe empty state;
        void setEmpty();

        // Getters
        const char* getID() const;
        const char* getDistrict() const;
        int getAge() const;
    };
    // Overloading the insertion and extraction operators
    std::ostream& operator<<(std::ostream& os, const MemberParliament& member);
    std::istream& operator>>(std::istream& is, MemberParliament& member);
}

#endif // SDDS_MEMBERPARLIAMENT_H
