// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: main.cpp
// Version: 2.0
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "iAccount.h" 

using namespace sdds;
using namespace std;

// display inserts account information for client
//
void display(const char* client, iAccount* const acct[], int n) {
	int lineLength = int(strlen(client) + 22);
	cout.fill('*');
	cout.width(lineLength);
	cout << "*" << endl;
	cout << "DISPLAY Accounts for " << client << ":" << endl;
	cout.width(lineLength);
	cout << "*" << endl;
	cout.fill(' ');
	for (int i = 0; i < n; ++i) {
		acct[i]->display(cout);
		if (i < n - 1) cout << "-----------------------" << endl;
	}
	cout.fill('*');
	cout.width(lineLength);
	cout << "****************************" << endl << endl;
	cout.fill(' ');
}

// close a client's accounts
// 
void close(iAccount* acct[], int n) {
	for (int i = 0; i < n; ++i) {
		delete acct[i];
		acct[i] = nullptr;
	}
}

int main () {
	// Create Accounts for Angelina
	iAccount* Angelina[2];
    
	// initialize Angelina's Accounts
	Angelina[0] = CreateAccount("Savings", 400.0); 
	Angelina[1] = CreateAccount("Chequing", 400.0);
	display("Angelina", Angelina, 2);

	cout << "DEPOSIT $2000 into Angelina Accounts ..." << endl ;
	for(int i = 0 ; i < 2 ; i++)
		Angelina[i]->credit(2000);

	cout << "WITHDRAW $1000 and $500 from Angelina's Accounts ... " << endl ;
	Angelina[0]->debit(1000);
	Angelina[1]->debit(500);
	cout << endl;
	display("Angelina", Angelina, 2);

	Angelina[0]->monthEnd();
	Angelina[1]->monthEnd();
	display("Angelina", Angelina, 2);

	close(Angelina, 2);
}
