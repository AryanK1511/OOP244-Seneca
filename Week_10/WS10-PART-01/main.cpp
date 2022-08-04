// Workshop 10:
// Collection template
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////


#include <iostream>
#include "Card.h"
#include "Book.h"
#include "Pet.h"
#include "Collection.h"
#include "templateFunctions.h"
using namespace std;
using namespace sdds;

int main()
{
    Card C[7] = { Card("Hearts", 13), Card("Clubs", 7), Card("Spades", 5),
                 Card("Diamonds", 11),Card("Hearts", 10), Card("Spades", 1),
                 Card("Diamonds", 12) };
    Book B[6] = { Book(23456, "Dune","Frank Herbert",9.99),Book(45678, "Foundation", "Issac Asimov", 19.99), Book(56789, "The Lord of the Rings","J.R.R. Tolkien", 7.99),
                 Book(67890, "Frankenstein", "Mary Shelly", 4.99), Book(34567, "The Martian", "Andy Weir",10.50),Book(12345, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams",12.99)};
    
    Pet P[6] = { Pet("Carl", "Rat", 3), Pet("Mindy", "Rabbit", 2),
                 Pet("Lenny", "Weasel",4), Pet("Waylon", "Dog", 7),
                 Pet("Frank", "Cat", 12), Pet("Billy Joel","Dog",13)};

    //these collections will hold the copies of the arrays for printing
    Collection<Card> cCol1;
    Collection<Book> bCol;
    Collection<Pet> pCol;
    //these collections will hold the results of the finds
    Collection<Card> cCol2;
    Collection<Book> bCol2;
    Collection<Pet> pCol2;
    Collection<int> iCol;
    int ii, index;

    // Loading up the collections of Cards
    for (ii = 0; ii < 7; ii++) {
        //Load the collection of cards into cCol1
        loadCollection(cCol1, C[ii]);  //****TODO 4:
    }

    // Loading up the collections of Books
    for (ii = 0; ii < 6; ii++) {
        //Load the collection of cards into bCol
        loadCollection(bCol, B[ii]); //****TODO 4:
    }

    // Loading up the collections of Pets
    for (ii = 0; ii < 6; ii++) {
        //Load the collection of cards into pCol
        loadCollection(pCol, P[ii]); //****TODO 4:
    }

    //Printing out all the Cards using the ostream insertion operator
    cout << "Printing all the Cards:" << endl;
    cout << cCol1; //****TODO 3:
    

    cout << endl;
    cout << "Searching for King of Hearts, Jack of Diamonds and 10 of Spades cards: " << endl;

    // Call the search method passing in the value and Suit (remember 1 = ace, 11 = jack, 12 = queen, 13 = king)
    int valuesToSearch[] = { 1, 11, 10 };
    const char* suits[] = { "Spades", "Diamonds", "Spades" };
    for (ii = 0; ii < 3; ii++) {
        //call the 4 argument find function with values from the 2 above arrays
        index = find(C, 7, valuesToSearch[ii], suits[ii]); //****TODO 2:
        if (index >= 0) {
            //add the found object at the corresponding index to cCol2. (Review the Collection code for the correct operator) 
            loadCollection(cCol2, C[index]);   //****TODO 4:
        }
    }

    // Search for all "Hearts" cards
    for (ii = 0; ii < 7; ii++) {
        if (find(C, "Hearts", ii)) { //****TODO 1:
            loadCollection(cCol2, C[ii]); //****TODO 4:
        }
    }

    //Printing cards found in our searches
    cout << cCol2; //****TODO 3:

    // Call the find function to search the array B 
    // and store the matches in bCol2 passing the following parallel array arguments as the key

    int upcToSearch[] = { 23456, 34567, 67890, 45678};
    const char* titlesToSearch[] = { "Dune", "IncorrectTitle", "Frankenstein", "Foundation"};
    for (ii = 0; ii < 4; ii++) {
        //call the 4 argument find function with values from the 2 above arrays
        index = find(B, 6, upcToSearch[ii], titlesToSearch[ii]); //****TODO 2:
        if (index >= 0) {
            //add the found object at the corresponding index to bCol2. (Review the Collection code for the correct operator)
            loadCollection(bCol2, B[index]);    //****TODO 4:
        }
        else {
            cout << endl << "(" << upcToSearch[ii] << " " << titlesToSearch[ii] << "), is not in our collection of books" << endl << endl;
        }
    }

    cout << "Our results of our Book search: (Dune, IncorrectTitle, Frankenstein, Foundation)" << endl;
    //print out our collection of searched books
    cout << bCol2; //****TODO 3:

    cout << endl << "All the books listed in our collection: " << endl;
    //print out our collection of all books
    cout << bCol; //****TODO 3:



    // Call the find function to search the array P
    // and store the matches in pCol2 passing the key "Dog" into your find function 

    for (ii = 0; ii < 6; ii++) {
        if (find(P, "Dog", ii)) { //****TODO 1:
            loadCollection(pCol2, P[ii]); //****TODO 4:
        }
    }

    cout << endl << "All the Pets listed in our collection: " << endl;
    //print out our collection of all pet
    cout << pCol; //****TODO 3:

    cout  << endl <<"Our results of our Pet Query: (Dog)" << endl;
    //print out our collection of filtered pets
    cout << pCol2; //****TODO 3:

    int a[]{90,80,90,70,60,30 };

    // Call the find function to find all elements that match the value 90
    // Load the results into a collection iCol
    // Insert the iCol into the cout stream

    for (ii = 0; ii < 6; ii++) {
        if (find(a, 90, ii)) { //****TODO 1:
            loadCollection(iCol, a[ii]); //****TODO 4:
        }
    }

    cout << endl << "Our results of int Filter:" << endl;
    cout << iCol; //****TODO 3:

    return 0;
}
