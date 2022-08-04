// Workshop 10:
// Card.cpp
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Card.h"
using namespace std;
namespace sdds {
    Card::Card(const char* suit, const int value) {
        set(suit, value);
    }
    void Card::set(const char* suit, const int value) {
        strncpy(m_suit, suit, 10);
        m_suit[8] = 0;
        m_value = value;
    }
    std::ostream& Card::display(std::ostream& os)const {
        char value[7]; 
        switch (m_value){
        case 1:
            strncpy(value, "Ace", 4);
            break;
        case 11:
            strncpy(value, "Jack", 5);
            break;
        case 12:
            strncpy(value, "Queen", 6);
            break;
        case 13:
            strncpy(value, "King", 5);
            break;
        default:
            strncpy(value, std::to_string(m_value).c_str(), 3);
        }
        return os << value << " of " << m_suit;
    }
    bool Card::operator==(const char* mmStr)const {
        return strcmp(m_suit, mmStr) == 0;
    }
    bool Card::operator==(const int mmVal)const {
        return m_value == mmVal;
    }
    std::ostream& operator<<(std::ostream& os, const Card& card) {
        card.display(os);
        return os;
    }
}