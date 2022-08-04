// Workshop 10:
// Write.cpp
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#include <iostream>
#include "Write.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }
}