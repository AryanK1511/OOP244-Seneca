/*
*****************************************************************************
                              Publication.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 20 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {
    class Publication : public Streamable {
    private:
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;
    public:
        Publication();
        ~Publication();

        // Copying is allowed
        Publication(const Publication& publication);
        Publication& operator=(const Publication& publication);

        // Modifiers / Setters
        // Sets to default values
        void setDefault();

        // Sets the membership attribute to either zero or a five-digit integer.
        virtual void set(int member_id);

        // Sets the **libRef** attribute value
        void setRef(int value);

        // Sets the date to the current date of the system.
        void resetDate();

        // Queries / Getters
        // Returns the character 'P' to identify this object as a "Publication object"
        virtual char type() const;

        // Returns true if the publication is checkout (membership is non-zero)
        bool onLoan() const;

        // Returns the date attribute
        Date checkoutDate() const;

        // Returns true if the argument title appears anywhere in the title of the publication
        bool operator==(const char* title) const;

        // Returns the title attribute
        operator const char* () const;

        // Returns the libRef attribute.
        int getRef() const;

        // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
        bool conIO(std::ios& io) const;

        // Write into an ostream object
        std::ostream& write(std::ostream& os) const;

        // Read from an istream object.
        std::istream& read(std::istream& is);

        // Overloads of this method will return if the Streamable object is in a valid state or not
        operator bool() const;
    };
}

#endif //SDDS_PUBLICATION_H