/*
*****************************************************************************
                              LibApp.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 15 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "LibApp.h"
#include <iostream>

namespace sdds {
    LibApp::LibApp(): m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_changed = false;

        // Populating main menu items using operator overload in Menu class
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

        // Populating exit menu items using operator overload in Menu class
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        load();
    }

    // Instantiates a menu and initializes it with the message argument
    bool LibApp::confirm(const char* message) {
        bool result = false;
        Menu menu(message);
        menu << "Yes";

        int returnedValue = menu.run();
        if (returnedValue == 1) {
            result = true;
        }

        return result;
    }

    // Simple private functions
    void LibApp::load() {
        std::cout << "Loading Data" << std::endl;
    }

    void LibApp::save() {
        std::cout << "Saving Data" << std::endl;
    }

    void LibApp::search() {
        std::cout << "Searching for publication" << std::endl;
    }

    void LibApp::returnPub() {
        search();
        std::cout << "Returning publication" << std::endl;
        std::cout << "Publication returned" << std::endl;
        std::cout << std::endl;
        m_changed = true;
    }

    // Methods with confirmation
    void LibApp::newPublication() {
        std::cout << "Adding new publication to library" << std::endl;
        bool confirmed = confirm("Add this publication to library?");
        if (confirmed) {
            m_changed = true;
            std::cout << "Publication added" << std::endl;
        }
        std::cout << std::endl;
    }

    void LibApp::removePublication() {
        std::cout << "Removing publication from library" << std::endl;
        search();
        bool confirmed = confirm("Remove this publication from the library?");
        if (confirmed) {
            m_changed = true;
            std::cout << "Publication removed" << std::endl;
        }
        std::cout << std::endl;
    }

    void LibApp::checkOutPub() {
        search();
        bool confirmed = confirm("Check out publication?");
        if (confirmed) {
            m_changed = true;
            std::cout << "Publication checked out"<< std::endl;
        }
        std::cout << std::endl;
    }

    // Displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
    void LibApp::run() {
        int userInputMenu, userInputExit;

        do {
            userInputMenu = m_mainMenu.run();

            // Calling appropriate methods according to the choice of the user in the main menu
            switch (userInputMenu) {
                case 0:
                    if (m_changed == true) {
                        userInputExit = m_exitMenu.run();

                        // Carrying out options according to the choice of user in the exit menu
                        switch (userInputExit) {
                            case 0:
                                if (confirm("This will discard all the changes are you sure?")) {
                                    m_changed = false;
                                }
                                break;
                            case 1:
                                save();
                                break;
                            case 2:
                                userInputMenu = 1;
                                break;
                        }
                    }
                    std::cout << std::endl;
                    break;
                case 1:
                    newPublication();
                    break;
                case 2:
                    removePublication();
                    break;
                case 3:
                    checkOutPub();
                    break;
                case 4:
                    returnPub();
                    break;
            }
        }
        while (userInputMenu != 0); // If the user doesn't opt exit, ask for inputs again and again

        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Thanks for using Seneca Library Application" << std::endl;
    }
}