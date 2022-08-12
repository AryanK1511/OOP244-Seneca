/*
*****************************************************************************
                              Publication.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 20 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Publication.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds {
    Publication::Publication() {
        setDefault();
    }

    // Copying is allowed
    Publication::Publication(const Publication& publication) {
        *this = publication;
    }

    Publication& Publication::operator=(const Publication& publication) {
        set(publication.m_membership);
        setRef(publication.m_libRef);
        strcpy(m_shelfId, publication.m_shelfId);
        m_date = publication.m_date;

        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }

        // Deep Copying
        if (publication.m_title != nullptr) {
            m_title = new char[strlen(publication.m_title) + 1];
            strcpy(m_title, publication.m_title);
        }
        else {
            m_title = nullptr;
        }

        return *this;
    }

    // Destructor
    Publication::~Publication() {
        delete[] m_title;
    }

    // Modifiers / Setters
    // Sets to default values
    void Publication::setDefault() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    // Sets the membership attribute to either zero or a five-digit integer.
    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    // Sets the **libRef** attribute value
    void Publication::setRef(int value) {
        m_libRef = value;
    }

    // Sets the date to the current date of the system.
    void Publication::resetDate() {
        m_date = Date();
    }

    // Queries / Getters
    // Returns the character 'P' to identify this object as a "Publication object"
    char Publication::type() const {
        return 'P';
    }

    // Returns true if the publication is checkout (membership is non-zero)
    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    // Returns the date attribute
    Date Publication::checkoutDate() const {
        return m_date;
    }

    // Returns true if the argument title appears anywhere in the title of the publication
    bool Publication::operator==(const char* title) const {
        return strstr(m_title, title) != nullptr;
    }

    // Returns the title attribute
    Publication::operator const char* () const {
        return m_title;
    }

    // Returns the libRef attribute.
    int Publication::getRef() const {
        return m_libRef;
    }

    // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
    bool Publication::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    // Write into an ostream object
    std::ostream& Publication::write(std::ostream& os) const {
        char title[SDDS_TITLE_WIDTH + 1] = { 0 };
        std::strncpy(title, m_title, SDDS_TITLE_WIDTH);

        if (conIO(os)) {
            os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << title << " | " ;
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else {
            os << type();
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            os << m_membership;
            os << "\t" << m_date;
        }

        return os;
    }

    // Read from an istream object.
    std::istream& Publication::read(std::istream& is) {
        // Temporary variables
        char t_title[256]{}, t_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int t_libRef = -1, t_membership = 0;
        Date t_date;

        // Clearing the memory if it is allocated and setting the values to default
        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }
        setDefault();

        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1);

            if (strlen(t_shelfId) != SDDS_SHELF_ID_LEN) {
                is.setstate(std::ios::failbit);
            }

            std::cout << "Title: ";
            is.getline(t_title, 256);

            std::cout << "Date: ";
            is >> t_date;
        }

        else {
            is >> t_libRef;
            is.ignore();
            is.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(t_title, 256, '\t');
            is >> t_membership;
            is.ignore();
            is >> t_date;
        }

        if (!t_date) {
            is.setstate(std::ios::failbit);
        }

        if (is) {
            m_title = new char[strlen(t_title) + 1];
            strcpy(m_title, t_title);
            strcpy(m_shelfId, t_shelfId);
            m_membership = t_membership;
            m_date = t_date;
            m_libRef = t_libRef;
        }

        return is;
    }

    // Overloads of this method will return if the Streamable object is in a valid state or not
    Publication::operator bool() const {
        bool result = false;
        if (m_title != nullptr && m_shelfId[0] != '\0') {
            result = true;
        }

        return result;
    }
}