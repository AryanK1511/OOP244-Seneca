/*
*****************************************************************************
                              LibApp.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 05 August 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

namespace sdds {
    LibApp::LibApp(const char* filename): m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationType("Choose the type of publication:") {
        // Setting the filename attribute to the incoming argument
        if (filename)
        {
            strcpy(m_filename, filename);
        }

        // Setting the bool value to false by default
        m_changed = false;

        // Setting the NOLP to 0
        m_NOLP = 0;

        // Populating main menu items using operator overload in Menu class
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

        // Populating exit menu items using operator overload in Menu class
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        // Populating publication type menu items using operator overload in menu class
        m_publicationType << "Book" << "Publication";

        load();
    }

    LibApp::~LibApp() {
        // Deleting the dynamically allocated memory
        for (int i = 0; i < m_NOLP; i++) {
            delete m_PPA[i];
        }
    }

    // Return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
    Publication* LibApp::getPub(int libRef) {
        Publication* result = nullptr;
        for (int i = 0; i < m_NOLP; i++)
        {
            if (m_PPA[i]->getRef() == libRef) {
                result = m_PPA[i];
            }
        }

        return result;
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
        std::ifstream infile(m_filename);

        char type{};
        int i;

        // Iterating over the file
        for (i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
            // Reading the first character to determine the type of publication
            infile >> type;

            // Ignoring the white space character
            infile.ignore();

            // Dynamically allocating space for the m_PPA array based on the type of publication
            if (infile) {
                if (type == 'P')
                    m_PPA[i] = new Publication;

                else if (type == 'B')
                    m_PPA[i] = new Book;

                if (m_PPA[i]) {
                    // Extracting the object from the file stream
                    infile >> *m_PPA[i];
                    m_NOLP++;
                    // Setting the LLRN to the reference number of the last publication read
                    m_LLRN = m_PPA[i]->getRef();
                }
            }
        }
    };

    void LibApp::save() {
        std::cout << "Saving Data" << std::endl;
        std::ofstream out_file(m_filename);
        int i;
        for (i = 0; i < m_NOLP; i++) {
            if (m_PPA[i]->getRef() != 0)
            {
                out_file << *m_PPA[i] << std::endl;
            }
        }

        out_file.close();
    }

    int LibApp::search(int searchType) {
        // selectionType:
        // 1: Search all publications
        // 2: Search only those publications which are on loan by library members
        // 3: Search only those publications which are not on loan

        char title[256]{};
        int selectedType = 0, i = 0, libRef = 0;
        char typeChar;
        PublicationSelector pubSel("Select one of the following found matches:", 15);

        // Getting the type of publication to search for from the user
        selectedType = m_publicationType.run();
        if (selectedType == 1) {
            typeChar = 'B';
        }
        else if (selectedType == 2) {
            typeChar = 'P';
        }

        // Getting the title to search the PPA for
        std::cin.ignore(1000, '\n');
        std::cout << "Publication Title: ";
        std::cin.getline(title, 256);

        if (searchType == 1) {
            for (i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->operator==(title) && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
                    // Insert object into pubSel object so that we can generate a selector to choose an element from
                    pubSel << m_PPA[i];
                }
            }
        }

        else if (searchType == 2) {
            for (i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->operator==(title) && m_PPA[i]->onLoan() && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
                    // Insert object into pubSel object so that we can generate a selector to choose an element from
                    pubSel << m_PPA[i];
                }
            }
        }

        else if (searchType == 3) {
            for (i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->operator==(title) && !m_PPA[i]->onLoan() && typeChar == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) {
                    // Insert object into pubSel object so that we can generate a selector to choose an element from
                    pubSel << m_PPA[i];
                }
            }
        }

        // If matches are found, sort the result and get the user's selection and return the library reference number.
        if (pubSel) {
            pubSel.sort();
            libRef = pubSel.run();

            if (libRef > 0)
            {
                std::cout << *getPub(libRef) << std::endl;
            }
            else {
                std::cout << "Aborted!" << std::endl;
            }
        }
        else {
            std::cout << "No matches found!" << std::endl;
        }

        return libRef;
    }

    void LibApp::returnPub() {
        bool aborted = false;
        std::cout << "Return publication to the library" << std::endl;
        int libRef = search(2); // Search only those publications which are on loan by library members
        if (!(libRef > 0)) {
            aborted = true;
        }

        if (!aborted) {
            bool confirmed = confirm("Return Publication?");

            if (confirmed) {
                int daysLoaned = Date() - getPub(libRef)->checkoutDate();

                // Apply penalty if the maximum number of loan days are exceeded
                if (daysLoaned > SDDS_MAX_LOAN_DAYS) {
                    double penalty = (daysLoaned - SDDS_MAX_LOAN_DAYS) * 0.5;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << "Please pay $" << penalty << " penalty for being " << (daysLoaned - SDDS_MAX_LOAN_DAYS) << " days late!" << std::endl;
                }

                // Set the member id to 0
                getPub(libRef)->set(0);
                m_changed = true;
            }

            std::cout << "Publication returned" << std::endl;
        }

        std::cout << std::endl;
    }

    // Methods with confirmation
    void LibApp::newPublication() {
        bool aborted = false;

        // Checking whether the library is at its maximum capacity
        if (m_NOLP == SDDS_LIBRARY_CAPACITY)
        {
            std::cout << "Library is at its maximum capacity!" << std::endl;
            aborted = true;
        }

        if (!aborted) {
            std::cout << "Adding new publication to the library" << std::endl;

            // Getting the publication type from the user
            int pubType = m_publicationType.run();
            std::cin.ignore(1000, '\n');

            // Instantiating a dynamic publication
            Publication* p = nullptr;

            if (pubType == 0) {
                std::cout << "Aborted!" << std::endl;
                aborted = true;
            }

            else if (pubType == 1) {
                p = new Book;
                std::cin >> *p;
            }

            else if (pubType == 2) {
                p = new Publication;
                std::cin >> *p;
            }

            if (std::cin.fail())
            {
                std::cin.ignore(1000, '\n');
                std::cin.clear();
                std::cout << "Aborted!" << std::endl;
                exit(0);
            }
            else {
                if (!aborted && confirm("Add this publication to the library?")) {
                    // Checking if the publication object is valid
                    if (!*p) {
                        std::cout << "Failed to add publication!" << std::endl;
                        delete p;
                    }

                    else {
                        m_LLRN++;
                        p->setRef(m_LLRN);

                        // Adding the publication object's address to the end of the PPA
                        m_PPA[m_NOLP] = p;

                        m_NOLP++;
                        m_changed = true;

                        std::cout << "Publication added" << std::endl;
                    }
                }
            }
        }

        std::cout << std::endl;
    }

    void LibApp::removePublication() {
        std::cout << "Removing publication from the library" << std::endl;
        int libRef = search(1); // Search all publications
        if (libRef) {
            if (confirm("Remove this publication from the library?")) {
                // Setting the library reference of the selected publication to 0 (zero)
                getPub(libRef)->setRef(0);

                m_changed = true;
                std::cout << "Publication removed" << std::endl;
            }
        }

        std::cout << std::endl;
    }

    void LibApp::checkOutPub() {
        std::cout << "Checkout publication from the library" << std::endl;
        int libRef = search(3); // Search only those publications which are not on loan / are available

        // Checking whether a match was found
        if (libRef > 0) {
            bool confirmed = confirm("Check out publication?");
            if (confirmed) {
                std::cout << "Enter Membership number: ";
                int inputMembership = getIntegerInput(10000, 99999, "Invalid membership number, try again: ");

                // Setting the membership number of the selected publication the integer value
                getPub(libRef)->set(inputMembership);

                m_changed = true;
                std::cout << "Publication checked out"<< std::endl;
            }
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