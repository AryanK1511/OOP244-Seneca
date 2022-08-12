/*
*****************************************************************************
                              Book.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 20 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Book.h"
#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {
    Book::Book() : Publication() {
        setBookEmpty();
    }

    Book::~Book() {
        delete[] authorName;
    }

    // Copying is allowed
    Book::Book(const Book& book) : Publication(book) {
        if (authorName) {
            delete[] authorName;
            authorName = nullptr;
        }

        authorName = new char[strlen(book.authorName) + 1];
        strcpy(authorName, book.authorName);
    }

    Book& Book::operator=(const Book& book) {
        Publication::operator=(book);

        if (authorName) {
            delete[] authorName;
            authorName = nullptr;
        }

        if (book.authorName) {
            authorName = new char[strlen(book.authorName) + 1];
            strcpy(authorName, book.authorName);
        }

        return *this;
    }

    // Sets book to empty state
    void Book::setBookEmpty() {
        authorName = nullptr;
    }

    // Returns the character 'B' to identify this object as a "Book object"
    char Book::type() const {
        return 'B';
    };

    // Write into an ostream object
    std::ostream& Book::write(std::ostream& os) const {
        Publication::write(os);
        if (conIO(os)) {
            char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
            std::strncpy(author, authorName, SDDS_AUTHOR_WIDTH);
            os << " ";
            os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ')<<  author << " |";
        }
        else {
            os << "\t" << authorName;
        }

        return os;
    }

    // Read from an istream object.
    std::istream& Book::read(std::istream& is) {
        char authName[256] = { 0 }; // temporary variable

        Publication::read(is);

        if (authorName) {
            delete[] authorName;
            authorName = nullptr;
        }

        if (conIO(is)) {
            is.ignore(); //ignore '\n'
            std::cout << "Author: ";
        }
        else {
            is.ignore(1000, '\t');
        }

        is.get(authName, 256);

        if (is) {
            authorName = new char[strlen(authName) + 1];
            strcpy(authorName, authName);
        }

        return is;
    }

    // Sets the membership attribute to either zero or a five-digit integer.
    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }

    // Overloads of this method will return if the Streamable object is in a valid state or not
    Book::operator bool() const {
        return authorName && Publication::operator bool();
    }
}