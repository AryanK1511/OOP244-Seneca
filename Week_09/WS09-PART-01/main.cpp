/* ------------------------------------------------------
Workshop 9 part 1
Filename: main.cpp
Version 1.0
Author : Fardad Soleimanloo
Date: 2022-06-09
---------------------------------------------------------- - */
#include <iostream>
#include <fstream>
#include "FullName.h"
using namespace sdds;
using namespace std;
bool operator==(FullName fn, const char* lastname);
bool operator>(FullName left, FullName right);
int readNames(FullName*& names, ifstream& istr);
void sort(FullName arr[], int n);
void cat(const char* fname);
int main() {
   FullName* simpsons;
   ifstream infile("simpsons.txt");
   ofstream outfile("sorted.txt");
   int cnt = readNames(simpsons, infile);
   sort(simpsons, cnt);
   cout << "Simpons Family:" << endl;
   for(int i = 0; i < cnt; i++) {
      if(simpsons[i] == "Simpson") cout << simpsons[i] << endl;
      outfile << simpsons[i] << endl;
   }
   cout << endl;
   delete[] simpsons;
   infile.close();
   outfile.close();
   cat("sorted.txt");
   return 0;
}
int readNames(FullName*& names, ifstream& istr) {
   int len = 10;
   names = new FullName[len];
   int cnt = 0;
   while(istr >> names[cnt]) {
      if(cnt == len - 1) {
         FullName* temp = new FullName[len += 10];
         for(int i = 0; i <= cnt; i++) {
            temp[i] = names[i];
         }
         delete[] names;
         names = temp;
      }
      cnt++;
   }
   return cnt;
}

bool operator==(FullName fn, const char* lastname) {
   int i;
   bool res = false;
   if(fn && lastname) {
      const char* s1 = fn;
      for(i = 0; s1[i] && lastname[i] && s1[i] == lastname[i]; i++);
      res = s1[i] == lastname[i];
   }
   return res;
}
bool operator>(FullName left, FullName right) {
   int i;
   bool res = false;
   if(left && right) {
      const char* s1 = left;
      const char* s2 = right;
      for(i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      res = s1[i] > s2[i];
   }
   return res;
}
void sort(FullName arr[], int n) {
   int i{}, j{};
   for(i = 0; i < n; i++) {
      for(j = 0; j < n - i - 1; j++) {
         if(arr[j] > arr[j + 1]) {
            FullName temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

void cat(const char* fname) {
   ifstream istr(fname);
   char ch{};
   int i = 1;
   cout.width(50);
   cout.fill('-');
   cout.setf(ios::left);
   cout << fname << endl << i << ": ";
   while(istr.get(ch)) {
      cout << ch;
      (ch == '\n') && cout << ++i << ": ";
   }
   cout.width(50);
   cout << "END OF DATA" << endl;
   cout.fill(' ');
   cout.unsetf(ios::left);
}
