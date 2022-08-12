/*
*****************************************************************************
                              Menu.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 15 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
    const unsigned int  MAX_MENU_ITEMS = 20;

    class MenuItem {
    private:
        // Holds only one Cstring of characters for the content of the menu item dynamically.
        char* menuContent{};

        MenuItem();
        MenuItem(const char* textContent);
        ~MenuItem();

        // Copying is not allowed
        MenuItem(const MenuItem& menuItem) = delete;
        void operator=(const MenuItem& MI) = delete;

        // Sets a MenuItem object to safe empty
        void setEmpty();

        // Return true, if it is not empty and it should return false if it is empty
        operator bool() const;

        // Should return the address of the content Cstring.
        operator const char* () const;

        // Display the content of the MenuItem on ostream
        std::ostream& display(std::ostream& os = std::cout);

        friend class Menu;
    };

    class Menu {
    private:
        MenuItem menuTitle{};
        MenuItem* menuItems[MAX_MENU_ITEMS]{};
        unsigned int pointerCount = 0;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();

        // Copying is not allowed
        Menu(const Menu& M) = delete;
        void operator=(const Menu& M) = delete;

        // Function to display the title of the menu
        std::ostream& displayMenuTitle(std::ostream& os);

        // Display the content of Menu on ostream
        std::ostream& displayMenu(std::ostream& os = std::cout);

        // Return the number of MenuItems on the Menu.
        operator int();

        // Return the number of MenuItems on the Menu.
        operator unsigned int();

        // Return true if the Menu has one or more MenuItems otherwise, false;
        operator bool();

        // Displays the Menu and gets the user selection.
        int run();

        // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
        int operator~();

        // Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
        Menu& operator<<(const char* menuitemContent);

        // If the index passes the number of MenuItems in the Menu, loop back to the beginning.
        const char* operator[](unsigned int index) const;
    };
    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, Menu& menu);
}

#endif