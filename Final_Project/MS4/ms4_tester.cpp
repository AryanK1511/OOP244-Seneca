// Final Project Milestone 4
// Book 
// File	ms4_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Book.h"
#include "Utils.h"
#include "Date.h"


using namespace std;
using namespace sdds;

#ifdef _MSC_VER  // Windows Console Colors
const char col_grey[] = "\033[38;5;8m";
const char col_red[] = "\033[38;5;9m";
const char col_green[] = "\033[38;5;10m";
const char col_yellow[] = "\033[38;5;11m";
const char col_blue[] = "\033[38;5;12m";
const char col_pink[] = "\033[38;5;13m";
const char col_cyan[] = "\033[38;5;14m";
const char col_white[] = "\033[38;5;15m";
const char col_end[] = "\033[0m";
#else // Linux or Mac Console Colors
const char col_grey[] = "\e[38;5;8m";
const char col_red[] = "\e[38;5;9m";
const char col_green[] = "\e[38;5;10m";
const char col_yellow[] = "\e[38;5;11m";
const char col_blue[] = "\e[38;5;12m";
const char col_pink[] = "\e[38;5;13m";
const char col_cyan[] = "\e[38;5;14m";
const char col_white[] = "\e[38;5;15m";
const char col_end[] = "\e[0m";
#endif



void revert2Orignal();
Book readBook(istream& istr);
Book getNextRec(ifstream& ifstr);


int main() {
   sdds::sdds_test = true;
   Book pd;
   revert2Orignal();
   cout << "An Invalid Book printout:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << endl << "Enter the following: " << endl
      << col_red << "P1234" << col_end << endl
      << "------------------------------" << endl;
   pd = readBook(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << endl << "Enter the following: " << endl
      << col_red << "P123" << endl
      << "Seneca Handbook" << endl
      << "2022/13/17" << col_end << endl
      << "------------------------------" << endl;
   pd = readBook(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << endl << "Enter the following: " << endl
      << col_red << "P123" << endl
      << "The Story of My Experiments with Truth" << endl
      << "2022/7/17" << endl
      << "Mohandas Karamchand Gandhi" << col_end << endl
      << "------------------------------" << endl;
   pd = readBook(cin);
   cout << "You entered:" << endl;
   cout << pd << endl;
   cout << "And the title is agian: \"" << (const char*)pd << "\"" << endl;
   pd.set(12345);
   if (pd.onLoan()) {
      cout << "Now this publication is on loan to a member with the id: 12345" << endl;
      cout << "The checkout date is: " << pd.checkoutDate() << endl;
      pd.setRef(9999);
      cout << "The library unique reference id is: " << pd.getRef() << endl;
      cout << pd << endl;
      cout << "----------------------------------------------------------------" << endl;
    }
   cout << "Adding the Book to the end of the data file:" << endl;
   ofstream fileout("Books.txt", ios::app);
   if (pd) {
      cout << "appeneded to the file" << endl;
      fileout << pd << endl;
   }
   fileout.close();
   cout << endl << "Contents of the file:" << endl;
   ifstream filein("Books.txt");

   char pType{};
   for (int row = 1; filein; row++) {
      filein >> pType;
      if (pType != 'B') {
         cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
         filein.setstate(ios::failbit);
      }
      filein.ignore();
      pd = getNextRec(filein);
      if (filein) {
         if(pd == "My Experiments") cout << col_blue;
         cout << (pd.onLoan() ? "|*" : "| ");
         cout.width(4);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << row << (pd.onLoan()? "*": " ");
         cout.unsetf(ios::right);
         cout << pd << (pd == "Star" ? "<<<":"") << endl;
         if(pd == "My Experiments") cout << col_end;
      }
   }
   return 0;
}

void revert2Orignal() {
   ifstream infile("BooksOriginal.txt");
   ofstream outfile("Books.txt");
   char ch{};
   while(infile.get(ch)) {
      outfile.put(ch);
   }
}
Book readBook(istream& istr) {
   Book P;
   istr >> P;
   return P;
}
Book getNextRec(ifstream& ifstr) {
   Book P;
   ifstr >> P;
   ifstr.ignore(1000, '\n');
   return P;
}
