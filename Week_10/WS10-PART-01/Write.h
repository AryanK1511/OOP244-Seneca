// Workshop 10:
// Write.h
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class ReadWrite {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
      virtual ~ReadWrite() {
      }
   };
   std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_

