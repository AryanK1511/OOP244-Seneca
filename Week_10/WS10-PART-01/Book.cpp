// Workshop 10:
// Book.cpp
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Book.h"
namespace sdds {
    Book::Book() {
        set(0, "", "", 0.0);
    }
    Book::Book(int upc, const char* title, const char* author, double price) {
        set(upc, title, author, price);
    }
    void Book::set(int upc, const char* title, const char* author, double price) {
        m_upc = upc;
        strcpy(m_title, title);
        strcpy(m_author, author);
        m_price = price;
    }
    ostream& Book::display(ostream& os)const {
        return os << m_upc << " " << m_title << " (Author: " << m_author << ") Price: $" << setprecision(2) << fixed << m_price;
    }
    bool Book::operator==(int upc)const {
        return m_upc == upc;
    }
    bool Book::operator==(const char* title)const {
        return strcmp(m_title,title)==0;
    }

    std::ostream& operator<<(std::ostream& os,const Book& book) {
        book.display(os);
        return os;
    }
}
