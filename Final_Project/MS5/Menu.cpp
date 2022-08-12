/*
*****************************************************************************
                              Menu.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 15 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Menu.h"
#include "Utils.h"
#include <cstring>

namespace sdds {
    // --------------------
    // MenuItem Class
    // --------------------

    MenuItem::MenuItem() {
        setEmpty();
    }

    MenuItem::MenuItem(const char* textContent) {
        if (textContent && textContent[0]) {
            menuContent = new char[strlen(textContent) + 1];
            strcpy(menuContent, textContent);
        }
        else {
            setEmpty();
        }
    }

    MenuItem::~MenuItem() {
        delete[] menuContent;
    }

    // Sets a MenuItem object to safe empty
    void MenuItem::setEmpty() {
        menuContent = nullptr;
    }

    // Return true, if it is not empty and it should return false if it is empty
    MenuItem::operator bool() const {
        return (menuContent && menuContent[0]);
    };

    // Should return the address of the content Cstring.
    MenuItem::operator const char* () const {
        return menuContent;
    }

    // Display the content of the MenuItem on ostream
    std::ostream& MenuItem::display(std::ostream& os) {
        if (*this) {
            os << menuContent;
        }

        return os;
    }

    // --------------------
    // Menu Class
    // --------------------

    Menu::Menu() {
        pointerCount = 0;
    };

    Menu::Menu(const char* title) : menuTitle(title) {};

    Menu::~Menu() {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete menuItems[i];
        }
    };

    // Function to display the title of the menu
    std::ostream& Menu::displayMenuTitle(std::ostream& os) {
        if (menuTitle) {
            menuTitle.display();
        }

        return os;
    }

    // Display the content of Menu on ostream
    std::ostream& Menu::displayMenu(std::ostream& os) {
        if (menuTitle)
        {
            menuTitle.display();
            os << std::endl;
        }

        unsigned int i;
        for (i = 0; i < pointerCount; i++)
        {
            os.width(2);
            os.setf(std::ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(std::ios::right);
            menuItems[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";

        return os;
    }

    // Return the number of MenuItems on the Menu.
    Menu::operator int() {
        return pointerCount;
    }

    // Return the number of MenuItems on the Menu.
    Menu::operator unsigned int() {
        return pointerCount;
    }

    // Return true if the Menu has one or more MenuItems otherwise, false;
    Menu::operator bool() {
        return (pointerCount > 0);
    }

    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, Menu& menu) {
        return (menu.displayMenuTitle(os));
    }

    // Displays the Menu and gets the user selection.
    int Menu::run() {
        int user_input;
        displayMenu();
        user_input = getIntegerInput(0, pointerCount);
        return user_input;
    }

    // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
    int Menu::operator~() {
        return run();
    }

    // Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
    Menu& Menu::operator<<(const char* menuitemContent) {
        if (pointerCount < MAX_MENU_ITEMS)
        {
            MenuItem* newMenuItem = new MenuItem(menuitemContent);
            menuItems[pointerCount] = newMenuItem;
            pointerCount++;
        }

        return *this;
    }

    // If the index passes the number of MenuItems in the Menu, loop back to the beginning.
    const char* Menu::operator[](unsigned int index) const {
        if (index > pointerCount)
        {
            return menuItems[index %= pointerCount]->menuContent;
        }
        else
        {
            return menuItems[index]->menuContent;
        }
    }
};