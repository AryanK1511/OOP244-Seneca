// Workshop 7
// Version: 1.0
// Author: Asam Gulaid
// Description:
// This file tests your workshop 7
/////////////////////////////////////////////

#include<iostream>
#include "Minister.h"
#include "Minister.h" // intentional
#include "MemberParliament.h"
#include "MemberParliament.h" // intentional

using namespace std;
using namespace sdds;

void printHeader(const char* title)
{
   char oldFill = cout.fill('-');
   cout.width(62);
   cout << "" << endl;

   cout << "|> " << title << endl;

   cout.fill('-');
   cout.width(62);
   cout << "" << endl;
   cout.fill(oldFill);
}

void newElections(Minister& aMinister, const char* district, const char* newPM, double year)
{
   aMinister.NewDistrict(district);
   aMinister.changePM(newPM);
   aMinister.assumeOffice(year);
   cout << "Status of New Election " << aMinister << endl << endl;
}


int main()
{

   printHeader("Person 1: MemberParliament");

   MemberParliament mp("MP9403", 59);
   cout << mp << endl << endl;

   mp.NewDistrict("Scarborough");
   mp.NewDistrict("Mississauga");
   mp.NewDistrict("Huron County");

   cout << endl << mp << endl << endl;

   printHeader("Person 2: Read/Write");
   cin >> mp;
   cout << endl << mp << endl << endl;

   printHeader("Person 3: Minister");

   Minister aMinister("MP9573", 63, 2003, "Harper", "Pickering");
   cout << endl;

   newElections(aMinister, "Whitby", "Trudeau", 2007);

   newElections(aMinister, "Kitchener", "Biden", 2010);

   newElections(aMinister, "Oakville", "Trump", 2015);

   printHeader("Person 4: Read/Write");
   cin >> aMinister;
   cout << endl << (MemberParliament)aMinister;
   cout << endl << aMinister << endl << endl;
   return 0;
}

