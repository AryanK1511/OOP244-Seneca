# Project: Seneca Library Application

### Milestones

|Milestone| Revision | Comments |
|------|:---:|:----|
| [MS1](#milestone-1) | V1.0 | |
| [MS2](#milestone-2) | V1.0 |  |
| [MS3](#milestone-3) | V1.0  | | 
| [MS4](#milestone-4) | V1.0  |  |
| [MS5](#milestone-5)<br />(Final Milestone) | V1.0 | |

When Books and other publications arrive in the Seneca library, they should be tagged and put on shelves, so they are easily retrievable to be lent out to those who need them. 
Your task is to design an application that receives the publications and stores them into the system with the information needed for their retrieval. 
Later, each publication can be lent out to members of the library with a due date for return.


## Milestones due dates
This project will be done in 5 milestones and each milestone will have its due date. The due date of each milestone is stated below, and it is based on the amount of work to be done for that milestone. 

## Final project mark and due dates

|Milestone| Mark | Due date | Submission Policy|
|:------:|:---:|:---:|-------|
| MS1 | 10% | Jul 8th | gets full mark even if 1 week late. gets 0% afterwards|
| MS2 | 10% | Jul 15th | gets full mark even if 1 week late. gets 0% afterwards|
| MS3 | 10% | Jul 22nd | gets full mark even if 1 week late. gets 0% afterwards|
| MS4 | 10% | Jul 29th  | gets full mark even if 1 week late. gets 0% afterwards|
| MS5 | 60% | Aug 7th  | See below|

> To make the final submission of the project easier and to make it possible to partially submit a project we have divided the submission of milestone 5 into six small ones. Each submission is worth 10% of the project mark. Your project will be marked only if you have all four milestones and at least have one of the 6 six submissions of milestone 5. 

|Milestone 5<br/> Divided into<br/>Six submission| Mark | Due date | Submission Policy|
|:------|:---:|:---:|-------|
| m51 (add) | 10% | Aug 7th| 10% penalty for each day being late up to 5 days|
| m52 (remove) | 10% | Aug 7th| 10% penalty for each day being late up to 5 days|
| m53 (checkout) | 10% | Aug 7th| 10% penalty for each day being late up to 5 days|
| m54 (return) | 10% | Aug 7th| 10% penalty for each day being late up to 5 days|
| m55 (Load Capacity) | 10% | Aug 7th| 10% penalty for each day being late up to 5 days|
| m56 (foolproofing) | 10% | Aug 7th| 10% penalty for each day being late up to 5 days|

> The first 4 milestones will not be marked based on the code, but their success and their timely submissions. You may modify or debug your previous code as you are going through the milestones. The only milestone that is going to scrutinized based your code will be milestone 5. If you require any feedback on your first four milestones you need to ask your professor to do so.


> :warning: Your project will receive a mark of zero if any of the first 4 milestones are not submitted by the rejection date (August 12th, 23:59 )<br />For your project to be marked, you must submit all the 4 milestones and at least one of the 6 submissions of Milestone 5 (Rejection date for milestone 5 is August 14th, 23:59)

You can check the due date of each milestone using the ```-due``` flag in the submission command:
```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- replace **2??** with the subject code
- replace **m?** with the milestone number
> Different sections may have different due dates based on their section's progress. Always check the due date using this command. The due date returned by this command always have priority over the due dates stated above.
## Citation, Sources

When submitting your work, all the files submitted should carry full student information along with the "citation and sources" information. See the following example:

If you have multiple submissions of the same milestone, please update the Revision History in each submission so your professor knows what changes to look for.

```C++
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failing to include the above citation to any of the files containing your work will cause the rejection of your project submission**

#### See below for details:

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.


> :warning: This [Submission Policy](#submission-policy) only applies to the project. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in an email write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ms file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ms`: the compiled application will be named `ms`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ms`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ms
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.


### Adding alias to `.bash_profile` on matrix
You can add the following two lines to the end of your `.bash_profile` file in your matrix home directory to create two aliases for the above C++ compilation and valgrind testing so you don't have to type such a long command to compile and execute your programs:
```bash
alias msc++="g++ -Wall -std=c++11 -g -o ms"
alias vrun="valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes"
```
By adding the above to the '.bash_profile' (you must logoff and log back it so it takes effect) you can compile your c++ files as follows:
```bash
msc++ file1.cpp file2.cpp file3.cpp...<ENTER>
```
The above will compile your files and if successful it will create an executable called `ms`.
```bash
vrun ms<ENTER>
```
The above will execute your `ms` executable under the tester `valgrind` for detailed test on leaks and runtime errors.

> Note: All the code written in this project must be implemented in the **sdds** namespace, unless instructed otherwise.

> Make sure that all the debugging code and debugging comments are removed before submission.

## Project Implementation notes:  *Very Important, read carefully*
- All the code written in this project should be within the namespace sdds.
- You are free and encouraged to add any attributes(member variables), functions and methods (member functions) you find necessary to complete your code. If you are not sure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.  
- If any methods are being added and they are not called outside the scope of the class, make sure they are private.

- Unless you are asked for a specific definition, name the variables, and functions yourself. Use proper names and follow the naming conventions instructed by your professor. Having meaningless and misleading names will attract a penalty.

- When creating methods (member functions) make sure to make them constant if in their logic, they are not modifying their class.

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- If an Empty state is required for an object, it is considered to be an “invalid” empty state, and objects in this state should be rendered unusable.

- A module called **Utils** is added to the project that can be used for your custom functions and classes in your implementation. Leave this module empty if you don't have any custom functionalities. <br />
You can add any custom code of your own to the **Utils** module to be used throughout the project. 

- You may reuse and copy any code your professor provided for your workshops or functions you may have from previous work in this subject or other subjects and place it in the Utils module. 

# The Project

Before we start developing the application, we need to have a few classes developed to help us with the dates in the system and also the user interface of the application. 


# Milestone 1

## Overview of the Classes to Be Developed for Milestone 1


### Date Class	
A class the encapsulates year, and month and day values for Date stamp, comparison and Date IO purposes. 
### MenuItem Class	
A class that hold a text Item; (an option or title to be displayed) in a menu to be selected by the user. This is a fully private class that is only accessible by Menu (see next class)
### Menu Class	
A class that has several MenuItems to be displayed so the user can select one of them for an action to be executed in the program 


## The Date Class
The Date class was partially implemented by another program that left the company and it is your responsibility to complete the implementation:

The date class encapsulates the following values:
- **Year**; an integer between the year 1500 till today
- **Month**, an integer between 1 and 12
- **Day**, an integer between 1 and the number of days in the month.
- **Error code**; an integer that holds the code that corresponds to an error that recently happened or ZERO if the date object is valid and ready to be used.
- **Current year**; an integer that is automatically initialized to the current date of the system for validation purposes when a Date object is instantiated.

The Date module (implemented in files **Date.h** and **Date.cpp**) is well documented and is placed in the project directory.

## Already implemented methods of the Date class and helper functions of Date

### Private functions:
```C++
int daysSince0001_1_1()const; 
```

returns number of days passed since the date 0001/1/1

```C++
bool validate();             
```

Validates the date setting the error code and then returns true, if valid, and false if invalid.

```C++
void errCode(int theErrorCode); 
```

sets the error code value

```C++
int systemYear()const;         
```

returns the current system year (2021 for this semester)

```C++
bool bad()const;             
```

returns true if the Date is in an erroneous state.

```C++
int mdays()const; 
```

returns the number of days in current month (the month stored in m_mon attribute)

```C++
void setToToday();
```

sets the date to the current date (system date)


### Public functions and Constructors

```C++
Date();
```

creates a date with current date

```C++
Date(int year, int mon, int day); 
```

creates a date with assigned values then validates the date and sets the error code accordingly 


```C++
int errCode()const;
```

returns the error code or zero if date is valid

```C++
const char* dateStatus()const;
```

returns a string stating the current status of the date 


```C++
int currentYear()const;
```

returns the m_CUR_YEAR attribute value

```C++
 std::ostream& operator<<(std::ostream& os, const Date& RO);
 std::istream& operator>>(std::istream& is, Date& RO);
```

Overloads of insertion and extraction operators to call write and read methods of Date 

---------------------------------------------------


> Study the class and learn what each constant, variable and member function does and then using those functions and your knowledge of iostream, cin and cout, add the following member functions to the Date class:

## Your task is to develop the following 

### the read method
```C++
std::istream& read(std::istream& is = std::cin);
```
This function reads a date from the console in the following format YYYY/MM/DD as follows:

- Clears the error code by setting it NO_ERROR
- Reads the year, the month and the day member variables using istream and ignores a single character after the year and the month values to bypass the Slashes.
> Note that the separators do not have to be Slash characters **“/”** but any separator that is not an integer number.
- Checks if istream has failed. If it did fail, it will set the error code to CIN_FAILED and clears the istream. If not, it will validate the values entered.
- Flushes the keyboard
- Returns the istream object

------------------------

### The write method
```C++
std::ostream& write(std::ostream& os = std::cout)const;
```
If the Date object is in a “bad” state (it is invalid) print the “dateStatus()”.
Otherwise, the function should write the date in the following format using the ostream object:
- Prints the year
- Prints a Slash “/”
- Prints the month in two spaces, padding the left digit with zero if the month is a single-digit number
- Prints a Slash “/”
- Prints the day in two spaces, padding the left digit with zero if the day is a single-digit number 
- Makes sure the padding is set back to spaces from zero 
- Returns the ostream object.

--------------------------

### Comparison operator overload methods
Overload the following comparison operators to compare two dates.

```C++
bool operator==
bool operator!=
bool operator>=
bool operator<=
bool operator<
bool operator>
```
Use the return value of the **daysSince0001_1_1()** method to compare the two dates:

--------------------------------

### Operator- method

Returns the difference between two Dates in days. 

#### Example
```C++
Date
      D1(2019, 12, 02),
      D2(2019, 11, 11);
int days = D1 - D2;

```
**days** in the above code snippet will hold the value 21.

-----------------------

### bool type conversion operator

It will return true if the date is valid and false if it is not.

------------------------


## Date Tester program

Write your own tester or use the following tester program to test and debug your Date class.

```C++
// Final Project Milestone 1 
// Date Tester program
// File	dateTester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Description
// This programs tests the Date class and is not for submission
//
// When testing before submission: DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Date.h"
using namespace sdds;
 
// A fool proof Date entry from console 
Date getDate();

int main() {
   Date
      D1,   // daysSince0001_1_1 to be recieved from console
      D2(2022, 6, 20);
   
   cout << "Current Date: " << D1 << endl;
   cout << D1 - D2 << " days since ms1 was published" << endl;
   cout << "Please enter a date to be compared to " << D2 << endl
      << "(Also try some invalid values for testing): " << endl
      << "YYYY/MM/DD > ";
   D1 = getDate();
   cout << "Your Entry: " << D1 << endl;
   cout << "Set by program to 2022/6/20: " << D2 << endl;
   cout << "Days between the two dates: " << D1 - D2 << endl;
   cout << "All the following statements must be correct: " << endl;
   if (D1 > D2) {
      cout << D1 << " > " << D2 << endl;
   }
   else {
      cout << D1 << " <= " << D2 << endl;
   }
   if (D1 < D2) {
      cout << D1 << " < " << D2 << endl;
   }
   else {
      cout << D1 << " >= " << D2 << endl;
   }
   if (D1 <= D2) {
      cout << D1 << " <= " << D2 << endl;
   }
   else {
      cout << D1 << " > " << D2 << endl;
   }
   if (D1 >= D2) {
      cout << D1 << " >= " << D2 << endl;
   }
   else {
      cout << D1 << " < " << D2 << endl;
   }
   if (D1 == D2) {
      cout << D1 << " == " << D2 << endl;
   }
   else {
      cout << D1 << " != " << D2 << endl;
   }
   if (D1 != D2) {
      cout << D1 << " != " << D2 << endl;
   }
   else {
      cout << D1 << " == " << D2 << endl;
   }
   return 0;
}

Date getDate() {
   Date D;
   do {
      cin >> D;      // get D from console
   } while (!D && cout << D.dateStatus() << ", Please try again > ");  // if D is invalid, print error message and loop
   return D;
}

```

### output sample

> Note that the current date will change based on the day of execution

```Text
Current Date: 2022/06/17
-3 days since ms1 was published
Please enter a date to be compared to 2022/06/20
(Also try some invalid values for testing):
YYYY/MM/DD > abc
cin Failed, Please try again > 1/1/1
Bad Year Value, Please try again > 2022/0/0
Bad Month Value, Please try again > 2022/10/30
Your Entry: 2022/10/30
Set by program to 2022/6/20: 2022/06/20
Days between the two dates: 132
All the following statements must be correct:
2022/10/30 > 2022/06/20
2022/10/30 >= 2022/06/20
2022/10/30 > 2022/06/20
2022/10/30 >= 2022/06/20
2022/10/30 != 2022/06/20
2022/10/30 != 2022/06/20

```


## The Menu Module

Create a module called Menu (in files Menu.cpp and Menu.h) this module will hold both MenuItem and Menu Classes’ implementation code. 

> Since the Menu class owns its MenuItem objects, it must have full control over the MenuItem creation. To implement this, have the declaration of the MenuItem and Menu class in the following sequence:
> - Forward declare the class Menu in the header file.
> - Implement the MenuItem class declaration (fully private) with Menu class as a friend. (see **MenuItem** class)
> - Implement the Menu class declaration.  (See **Menu** Class)

### The MenuItem Class
Create a class called MenuItem. This class holds only one Cstring of characters for the content of the menu item dynamically. The length of the content is unknown.
This class should be fully private (no public members; even constructor is private!):

Make the “Menu” class a friend of this class (which makes MenuItem class only accessible by the Menu class).
```C++
   friend class Menu;
```

### Constructor 
Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation (or initialization). If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.

### Rule of Three 
A MenuItem object cannot be copied from or assigned to another MenuItem object.<br />
*(Copy constructor and Copy assignment are deleted)*

#### Destructor 
Deallocates the content


### `bool` type conversion
When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.

### `const char*` type conversion
When a MenuItem is casted to “const char*” it should return the address of the content Cstring.

### displaying the MenuItem
Create a method to display the content of the MenuItem on ostream. *(No newline is printed after)* <br />Nothing is printed if MenuItem is empty.

> Remember that the MenuItem class is fully private.

### The Menu Class
Create the Menu class as follows:

#### Rule of Three

A Menu Object can not be copied or assigned to another Menu Object. *(Copy constructor and Copy assignment are deleted)*

#### Attributes
This class has a minimum of three attributes.
1) A MenuItem to possibly hold the title of the Menu.
2) An array of MenuItem pointers. The size of this array is set by a constant unsigned integer defined in the Menu header file; called **MAX_MENU_ITEMS**. Have the **MAX_MENU_ITEMS** integer initialized to 20.
This array will keep potential MenuItems added to the Menu. Each individual element of this array will hold the address of a dynamically allocated MenuItem as they are added to the Menu. *(See insertion operator overload for Menu)* <br />Initialize this array of pointers to **nullptr**s.  
3) An integer to keep track of how many MenuItem pointers are pointing to dynamic MenuItem objects. *(obviously, the value of this variable is always between 0 and MAX_MENU_ITEMS)*.

#### Constructors
A Menu is always created empty; with no MenuItems, with or without a title.<br /> Example:
```C++
Menu A;
Menu B("Lunch Menu");
```

#### Destructor
Looping through the MenuItems array of pointers, it deletes each pointer up to the number of menu items in the menu.

#### Methods
- Suggestion: create a function to display the title of the Menu on ostream if the title is not empty, otherwise, it does nothing.
- Create a function to display the entire Menu on ostream: <br />
This function first displays the title (if it is not empty) followed by a **":"** and a new-line, then it will display all the MenuItems one by one; adding a row number in front of each. The row numbers are printed in two spaces, right justified followed by a **"dash"** and a **"space"**. 
After printing all the MenuItems it should print `" 0- Exit"` and new-line and `"> "`. <br />
For example if the title is "Lunch Menu" and the menu items are "Omelet", "Tuna Sandwich" and "California Rolls", the Menu object should be printed like this:<b />
```Text
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 > 
```

- Create a member function called **`run`**. This function displays the Menu and gets the user selection.<br />
    *(this function should be completely foolproof)*
    The function receives nothing and returns an unsigned integer (That is the user’s selection). 
    After displaying the menu, ask for an integer and make sure the value of the integer is between 0 and the number of the menu items. If the user enters anything incorrect, print:<br />
    `"Invalid Selection, try again: "`<br />
    and get the integer again until a valid selection is made.

    > Nice to do:<br />  The action of a foolproof integer entry within limits, with a prompt and an error message is a good candidate for a separate function implementation in the Utils module

- Overload **`operator~`** to do exactly what the run function does (two different ways to run the menu)

- Overload a **member** insertion operator (operator<<) to add a MenuItem to the Menu.
    ```C++ 
    Menu& Menu::operator<<(const char* menuitemConent);
    ```
 
    This operator receives a C-style string containing the content of the MenuItem and returns the reference of the Menu object (*this).

    To accomplish this, check if the next spot for a MenuItem is available in the array of MenuItem pointers. If it is, dynamically create a MenuItem out of the content received through the operator argument and then store the address in the available spot and finally increase the number of allocated MenuItem pointers by one.

    If no spot is available, ( that is; if number of allocated MenuItem pointers is equal to  MAX_MENU_ITEMS) this function silently ignores the action.

    At the end, return the reference of the Menu object. 
    
    Usage example:
    
    ```C++
    int a;
    Menu M;
    M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    a = M.run()
    cout << "Your selection " << a << endl;
    ```
    
    output:
    ```Text
     1- Omelet
     2- Tuna Sandwich
     3- California Rolls
     0- Exit
     > 3 <ENTER>
    Your selection 3
    ```

- Overload two type conversions for **`int`** and **`unsigned int`** to return the number of MenuItems on the Menu.

- Overload the type conversion for **`bool`** to return true if the Menu has one or more MenuItems otherwise, false;

- Overload the insertion operator to print the title of the Menu using **cout**.

    Example for the last three overloads:

    ```C++
    Menu M ("Lunch Menu");
    M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    if (M) { // bool conversion
      cout << "The " << M << " is not empty and has "      //  insertion operator overload
            << unsigned int(M) << " menu items." << endl;  //  const int conversion (int conversion not tested)
    }
    ```

    Output:

    ```Text
    The Lunch Menu is not empty and has 3 menu items.
    ```

- Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
    If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)  
    Example:
    ```C++
    Menu M;
    M << "Omelet" << "Tuna Sandwich" << "California Rolls";
    cout << M[0] << endl;
    cout << M[1] << endl;
    cout << M[3] << endl; // << note that the last valid index is "2"
    ```
    The above code snippet will print the following:
    ```Text
    Omelet
    Tuna Sandwich
    Omelet
    ```
## Menu tester program
Write your own tester or use the following tester program to test and debug your Menu class.

```C++
// Final Project Milestone 1 
// Menu Module
// File	menuTester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29		       Preliminary release
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
using namespace sdds;

void showOrder(const unsigned int* cnt, const Menu& M);
int main() {
   unsigned int selections[3]{};
   unsigned int s;
   Menu m1("Lunch Menu"), m2;
   if (m2) {
      cout << "Wrong output, your bool cast is done incorrenctly!";
   }
   else {
      cout << "The >" << m2 << "< menu is empty" << endl;
   }
   m1 << "Omelet" << "Tuna Sandwich" << "California Roll";
   m2 << "Order more";
   if (m1) {
      cout << "The " << m1 << " is not empty and has " << (unsigned int)(m1) << " menu items." << endl;
   }
   do {
      s = m1.run();
      if (s) {
         selections[s - 1]++;
         cout << "you chose " << m1[s - 1] << endl;
      }
   } while (s != 0 || ~m2 != 0);
   showOrder(selections, m1);
   return 0;
}
void showOrder(const unsigned int* cnt, const Menu& M) {
   bool orderedSomthing = false;
   cout << "Your orders: " << endl;
   for (int i = 0; i < 3; i++) {
      if (cnt[i]) {
         orderedSomthing = true;
         cout << cnt[i] << " " << M[i] << (cnt[i] > 1 ? "s" : "") << endl;
      }
   }
   if (!orderedSomthing) cout << "You didn't order anything!" << endl;
}
```

### Sample Execution

```Text
The >< menu is empty
The Lunch Menu is not empty and has 3 menu items.
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> abc
Invalid Selection, try again: 5
Invalid Selection, try again: -1
Invalid Selection, try again: 0
 1- Order more
 0- Exit
> 0
Your orders:
2 Omelets
3 Tuna Sandwichs
```

# ms1_tester.cpp
This file contains both date and menu testers functions and runs them at once for submission:

[ms1_tester.cpp](ms1/ms1_tester.cpp)

[ms1_tester output](ms1/ms1_tester_output.md)


## MS1 Submission 



> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Date.cpp, Date.h, Menu.cpp, Menu.h and ms1_tester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m1
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)

# Milestone 2
## The Seneca Library Application Module
Your task for milestone 2 is to build a mockup application for the Seneca Library Application in a module called LibApp. 

The **LibApp** class demos the execution of the Seneca Library Application with printing messages instead of actually doing the tasks.

Later these messages are replaced with actual working modules to make the application functional. 

Creating a mockup application before developing the main program helps to understand the entire system and also demonstrates the execution of the program to the client before the application is fully developed.

You are going to use the Menu Module in this milestone. 
### Modules (files) included in this milestone:
```Text
Utils.cpp
Utils.h
Menu.cpp
Menu.h
LibApp.cpp
LibApp.h
ms2_tester.cpp
```
Before starting the milestone you have to make a minor modification to the title of the Menu class: 

> *Remove the colon **(":")** character after displaying the title of the Menu*
#### MS1 MENU:
```Text
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 > 
```
#### MS2 Menu:
```Text
Lunch Menu
 1- Omelet
 2- Tuna Sandwich
 3- California Rolls
 0- Exit
 > 
```

> Note: these types of modifications to previously written code are very common to accommodate newly developed logic.

## The LibApp Module

create a class called **LibApp** with following attributes:

### LibApp Attributes
```C++
      bool m_changed;
      Menu m_mainMenu;
      Menu m_exitMenu;
```

#### `m_changed`
A flag to keep track of changes made to the application data. This flag is initially set to false. If any change is made to the data of the application, this flag is set to true. 

Doing so, when exiting the program, we can warn the user and ask if they like the changes to be saved or discarded.

#### `m_mainMenu`
This menu will be used as the main menu of the application and should be initialized with the following title:
```text
"Seneca Libray Application"
```
and then populated with the following menu items:
```text
"Add New Publication"
"Remove Publication"
"Checkout publication from library"
"Return publication to library"
```

#### `m_exitMenu`
This menu will be used when exiting the program if any changes are made to the data. This menu should be initialized with the following title:
```text
"Changes have been made to the data, what would you like to do?"
```
and then populated with the following menu items:
```text
"Save changes and exit"
"Cancel and go back to the main menu"
```

### Private Methods
```C++
bool confirm(const char* message);
```
Instantiate a **Menu** in this function and initialize it with the **message** argument.

Then add only a `"yes"` as a single menu item to the Menu.  

Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
#### Simple private fuctions:
```C++
      void load();  // prints: "Loading Data"<NEWLINE>
      void save();  // prints: "Saving Data"<NEWLINE>
      void search();  // prints: "Searching for publication"<NEWLINE>
      
      void returnPub();  /*  Calls the search() method.
                             prints "Returning publication"<NEWLINE>
                             prints "Publication returned"<NEWLINE>
                             sets m_changed to true;
                         */
```
#### Methods with confirmation
```C++
void newPublication();
```

prints `"Adding new publication to library"`+newline<br />
calls the confirm method with `"Add this publication to library?"`<br />
if confrim returns true, it will set `m_changed` to true and prints `"Publication added"` + newline<br />
```C++
void removePublication();
```
prints `"Removing publication from library"`+newline<br />
calls the search method<br />
calls the confirm method with `"Remove this publication from the library?"`<br />
if confrim returns true, it will set `m_changed` to true and prints `"Publication removed"` + newline<br />
```C++
void checkOutPub();
```
calls the search method<br />
calls the confirm method with `Check out publication?"`<br />
if confrim returns true, it will set `m_changed` to true and prints `"Publication checked out"` + newline<br />

## Constructor
Constructor should initialize and set the attributes and load the publication records from database
- Initializes the attributes (see the attribute section)
- populates the Menu attributes
- calls the `load()`` method


## The run method

The run method is the main application driver.

It displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.

When the user selects exit, the value of `m_changed` is examined. 
If the value is false, then since the data of the application is not modified, the program terminates.

If the value is true, the `m_exitMenu` is used by calling its run method. Doing so the user has the selection of saving and exiting, cancelling and going back to the main menu or exiting without saving. 

If the first one is selected, the `save()` method is called and the program terminates.

If the second one is selected the program goes back to the main menu and execution continues.

If the exit is selected, then the confirm menu will be called using the message: `"This will discard all the changes are you sure?"`.  If the user selects **Yes**, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.


When the program is terminated, the following message is printed:
```Text
-------------------------------------------
Thanks for using Seneca Library Application
```

### suggested pseudo code:
```text
loop until done
    display menu
    if first option  new publication otherwise
    if second option remove publication otherwise
    if third option checkout otherwise
    if fourth option return publication otherwise 
        if changed
           Warning menu and choices
           if save selected save and its done otherwise
           if discard selected 
              final confirmation for exit 
              if exit selected 
                 its done (no saving)   
              end if
           end if
        otherwise (no change)
           it is done          
        end if
    end if
end loop        
goodbye message
```

## Tester program
```C++
// Final Project Milestone 2
// LibApp Mockup Module
// File	ms2_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "LibApp.h"
using namespace std;
int main() {
   sdds::LibApp theApp;
   cout << endl << "Testing exiting with no change:" << endl;
   theApp.run();
   cout << endl << "Testing exiting with change and discarding data:" << endl;
   theApp.run();
   cout << endl << "Testing exiting with change and saving data:" << endl;
   theApp.run();
   cout << endl << "Testing all actions:" << endl;
   theApp.run();
   return 0;
}
/* data to be entered:
 1- 1
 2- 0
 3- 0
 4- 2
 5- 1
 6- 0
 7- 0
 8- 1
 9- 3
10- 1
11- 0
12- 1
13- 4
14- 0
15- 2
16- 0
17- 1
*/
```
## output

[MS2 Output](ms2/ms2_output.md)


## MS2 Submission 


> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.cpp, Menu.h, LibApp.cpp, LibApp.h and ms2_tester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m2
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


# Milestone 3
## Streamable Interface module and Publication class module

> An Interface is an abstract base class with only pure virtual functions.

This milestone will include the Date and Utils modules. 

Before starting to develop milestone 3, please apply the following modifications to the Date module:

### In Date.cpp
- In Date::read() method:
   remove "flushing the keyboard" (i.e. `cin.ignore(1000,'\n')`) at the end of your read function. The read function should not flush the keyboard when the reading process is done.

- Add the following global variable (for testing purposes) to the top of the **sdds** namespace in Date.cpp.
```C++
   bool sdds_test = false;
   int sdds_year = 2022;
   int sdds_mon = 8;
   int sdds_day = 7;
```
- replace **systemYear** and **setToToday** methods with the following:
```C++
   int Date::systemYear()const {
      int theYear = sdds_year;
      if (!sdds_test) {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         theYear = lt.tm_year + 1900;
      }
      return theYear;
   }
   void Date::setToToday() {
      if (sdds_test) {
         m_day = sdds_day;
         m_mon = sdds_mon;
         m_year = sdds_year;
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         m_day = lt.tm_mday;
         m_mon = lt.tm_mon + 1;
         m_year = lt.tm_year + 1900;
      }
      errCode(NO_ERROR);
   }
```


### in Date.h 
- Add the following to the bottom of the **sdds** namespace; This will make the global variables added to Date.cpp, truly global for any code including "Date.h".
```C++
   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
```

## Types of publications in Seneca Library
Seneca Library holds two types of Publication; Periodical (like newspapers and Magazines) and Books. 

Publications are not loaned out to members. Members can check them out and read them in the library. These publications are put back on their shelves at the end of the day.

Books can be borrowed and returned within 15 days. After 15 days, the member will be charged daily for a late penalty.

## General definitions of the library system. 
Create a header file called **"Lib.h"** to hold all the general values of the system. 
Add the following and any other general values you find necessary to this header file. This header file should be included anywhere any of these values are needed. 
```C++
const int SDDS_MAX_LOAN_DAYS = 15; 
     // maximum number of day a publication can be borrowed with no penalty
const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
const int SDDS_SHELF_ID_LEN = 4;
   // The width in which the shelf id of a publication should be printed on the console
const int SDDS_LIBRARY_CAPACITY = 5000;
   // Maximum number of publications the library can hold.
```


## Streamable Interface Modules.
Create an Interface called **Streamable** to enforce implementation of the following methods. Any class inherited from Streamable will have the capability to be inserted into or extracted from a  stream.

### Streamable Pure Virtual funcitons
Add the following pure virtual function to Streamable:

#### `write` pure virtual function
This method is not capable of modifying the Streamable object.  **write** receives and returns a reference of an `ostream` object.

Functions overriding this function will write into an ostream object.

#### `read` pure virtual function
**read** receives and returns a reference of an `istream` object.

Functions overriding this function will read from an istream object.

#### `conIO`
This method is not capable of modifying the Streamable object. **conIo** receives a reference of an `ios` object and returns a Boolean.

Functions overriding this function will determine if the incoming `ios` object is a console IO object or not.

#### `Boolean conversion operator overload` (pure virtual)

Boolean conversion overloads of this method will return if the Streamable object is in a valid state or not.

### destructor
Add an empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak.

### Insertion operator overload
Overload the insertion operator so a constant object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state. Otherwise, the function will quietly ignore the insertion action.


### Extraction operator overload
Overload the extraction operator so an object of type Streamable can be read from an istream object.





## Publication class module
The publication class is a general encapsulation of any periodic publication. 
> Later by adding an author to the descendant of the **Publication** class we will encapsulate a **Book** for the system.

### Publication Attributes
#### m_title
**m_title** is a c-string to hold a dynamic title for the publication. 
> To ease the implementation, let's assume this dynamic array can not be more than 255 characters long.

This attribute is **null** by default.
#### m_shelfId
Hold the location of the publication in the library. 
**m_shelfId** is a c-string that is exactly 4 characters long. 

This attribute is an empty string by default.

#### m_membership
This attribute is an integer to hold a 5 digit membership number of members of the library. 

In this class, if the membership number is '0', it means the publication is available and is not checked out by any members. 

If the membership number is a five-digit number, it means the publication is checked out by the member holding that membership number.

This attribute is zero by default.

#### m_libRef
This serial number is used internally to uniquely identify each publication in the system. 

This attribute is -1 by default.

#### m_date
A Date object.

In periodical publications, this date is used for the publish date of the item. 

In Books, this date is used to keep the date on which the book was borrowed by the member.

The Date, by default, is set to the current date.

### Constructor (default)
Sets all the attributes to their default values.

### Methods
#### Modifiers
```C++  
virtual void set(int member_id);
   // Sets the membership attribute to either zero or a five-digit integer.
void setRef(int value);
   // Sets the **libRef** attribute value
void resetDate();
   // Sets the date to the current date of the system.
```

#### Queries

```C++
virtual char type()const;
   //Returns the character 'P' to identify this object as a "Publication object"
bool onLoan()const;
   //Returns true is the publication is checkout (membership is non-zero)
Date checkoutDate()const; 
   //Returns the date attribute
bool operator==(const char* title)const;
   //Returns true if the argument title appears anywhere in the title of the 
   //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
operator const char* ()const;
   //Returns the title attribute
int getRef()const;
   //Returns the libRef attirbute. 
```
 

### Streamable pure virtual function implementations

#### `bool conIO(ios& io)const`
Returns true if the address of the **io** object is the same as the address of either the **cin** object or the **cout** object.

#### `ostream& write(ostream& os) const`
If the **os** argument is a console IO object (use **conIO()**), print **shelfId**, **title**, **membership** and **date** attributes as the following format (title is left-justified padded with dots)

```text
         1         2         3         4         5         6         7 
1234567890123456789012345678901234567890123456789012345678901234567890
| P001 | The Toronto Star.............. | 34037 | 2021/11/17 |
| P007 | Macleans Magazine............. |  N/A  | 2021/11/11 |
```
Otherwise:

Print the type() and then libRef, shelfId, title, membership and date attributes in a tab-separated format. 
```Text
P	2001	P001	The Toronto Star	34037	2021/11/17
```

No newline is printed afterwards either way.

#### `istream& read(istream& istr)`
Read all the values in local variables before setting the attributes to any values.

First, clear all the attributes by freeing the memory and setting everything to their default values.

Then, if the istr argument is a console IO object (use conIO()) read the attributes as  follows:

- prompt: `"Shelf No: "`
- read the shelf number up to its limit (see Lib.h).
- if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
- prompt: `"Title: "`
- read the title
- prompt: `"Date: "`
- read the date
> in this case the libRef value is left with its default value.

Otherwise, assume reading begins with libRef attribute as if the type 'P' is not in the file.

- read the libRef number
- skip the tab
- read the shelf number
- skip the tab
- read the title 
- skip the tab
- read the membership
- skip the tab
- read the date

Either way if the date is in an invalid state set the istr to a fail state manually

After the process of reading is done if istr is in a valid state:

- Dynamically store the title into the title attribute
- copy the shelf id into the shelfId attribute
- set the membership
- set the date
- set the libRef attribute

At the end return the istr argument.

#### `operator bool() const `

Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.

### The Rule of three
Make sure this object complies with the guidelines of the Rule of three so the copying and assignment and destruction are done safely and without any memory leak.


## the Tester program

```C++
// Final Project Milestone 3
// File	ms3_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "Publication.h"
#include "Utils.h"
#include "Date.h"


using namespace std;
using namespace sdds;

//Please use putty for termial client on Matrix (https://www.putty.org/)

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
Publication readPublication(istream& istr);
Publication getNextRec(ifstream& ifstr);

int main() {
   sdds::sdds_test = true;
   Publication pd;
   revert2Orignal();
   cout << "An Invalid publication printout:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << "Enter the following: " << endl
      << col_red << "P1234" << col_end << endl
      << "------------------------------" << endl;
   pd = readPublication(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << "Enter the following: " << endl
      << col_red << "P123" << endl
      << "Seneca Weekly" << endl
      << "2022/13/17" << col_end << endl
      << "------------------------------" << endl;
   pd = readPublication(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << "Enter the following: " << endl
      << col_red << "P123" << endl
      << "Seneca Weekly" << endl
      << "2022/7/17" << col_end << endl
      << "------------------------------" << endl;
   pd = readPublication(cin);
   cout << "You entered:" << endl;
   cout << col_green << pd << col_end << endl;
   cout << "And the title is agian: \"" << (const char*)pd << "\"" << endl;
   pd.set(12345);
   if (pd.onLoan()) {
      cout << "Now this publication is on loan to a member with the id: 12345" << endl;
      pd.resetDate();
      cout << "The checkout date is: " << pd.checkoutDate() << endl;
      pd.setRef(9999);
      cout << "The library unique reference id is: " << pd.getRef() << endl;
      cout << col_green << pd << col_end << endl;
      cout << "----------------------------------------------------------------" << endl;
    }
   cout << "Adding the periodical publication to the end of the data file:" << endl;
   ofstream fileout("Periodicals.txt", ios::app);
   if (pd) {
      cout << "appeneded to the file" << endl;
      fileout << pd << endl;
   }
   fileout.close();
   cout << endl << "Contents of the file:" << endl;
   ifstream filein("Periodicals.txt");
   char pType{};
   for (int row = 1; filein; row++) {
      filein >> pType;
      if (pType != 'P') {
         cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
         filein.setstate(ios::failbit);
      }
      filein.ignore();
      pd = getNextRec(filein);
      if (filein) {
         if(pd == "Seneca Weekly") cout << col_blue;
         cout << (pd.onLoan() ? "|*" : "| ");
         cout.width(4);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << row << (pd.onLoan()? "*": " ");
         cout.unsetf(ios::right);
         cout << pd << (pd == "Star" ? "<<<":"") << endl;
         if(pd == "Seneca Weekly") cout << col_end;
      }
   }
   return 0;
}

void revert2Orignal() {
   ifstream infile("PeriodicalsOriginal.txt");
   ofstream outfile("Periodicals.txt");
   char ch{};
   while(infile.get(ch)) {
      outfile.put(ch);
   }
}

Publication readPublication(istream& istr) {
   Publication P;
   istr >> P;
   return P;
}
Publication getNextRec(ifstream& ifstr) {
   Publication P;
   ifstr >> P;
   ifstr.ignore(1000, '\n');
   return P;
}
```
 
## Tester Output
[MS3 tester output](ms3/ms3_output.md)



## MS3 Submission


> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Date.cpp, Date.h, Streamable.cpp, Streamable.h, Publication.cpp, Publication.h,Periodicals.txt, and ms3_tester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m?
```
and follow the instructions.

- *2??* is replaced with your subject code
- *m?* is replaced with your milestone


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


# Milestone 4
## The **Book** class

This milestone will require the following modules and header files:
- Lib.h
- Uitls
- Date
- Streamable
- Publication

### The Book class implementation
The Book class is derived from the Publication class. A book is a publication with an "Author name". 
 
The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically. 

#### Construction
A book is created empty by default, in a safe empty state. 

#### The rule of three
Implement what is needed to comply with the rule of three so a book can safely be copied or assigned to another book.

### Methods
The book class overrides the following virtual methods and type conversion operator.
- type
- write
- read
- set
- operator bool()

### Method implementations:

#### type method
Returns the character "B".

#### write method
- First, it will invoke the write of its Base class.
- If the incoming argument is a console IO object.
   - writes a single space
   - writes the author's name in SDDS_AUTHOR_WIDTH spaces. If the author's name is longer than the SDDS_AUTHOR_WIDTH value, it will cut it short and writes exactly  SDDS_AUTHOR_WIDTH characters. Note that this should not modify the author's name.
   - writes `" |"`
- If the incoming argument is not a console IO object
   - writes a tab character `'\t'` 
   - writes the author's name
- returns the incoming ostream.

#### Read
Read the author name in local variables before setting the attribute to any value. (to make it easier lets assume the author's name can not be more than 256 characters)

- First, invoke the read of the Base class.
- Free the memory held for the author's name
-  If the incoming argument is a console IO object
   - ignore one character (skip the '\n')
   - prompt  `"Author: "`
   - read the author's name 
- If the incoming argument is not a console IO object
   - ignore the tab character
   - read the author's name

Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.

At the end return the incoming istream object.

#### set
- invoke the set of the base class to set the member id
- reset the date to the current date.

#### operator bool()
return true if the author's name exists and is not empty and the base class's operator bool() has returned true.

## the Tester program
``` C++
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
```

## MS4 tester program output
[MS4 tester output](ms4/ms4_output.md)


## MS4 Submission 


> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Date.cpp, Date.h, Streamable.cpp, Streamable.h, Publication.cpp, Publication.h,Book.cpp,Book.h,Books.txt, and ms4_tester.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m?
```
and follow the instructions.

- *2??* is replaced with your subject code
- *m?* is replaced with your milestone


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


# Milestone 5
## The Seneca Library Application

To complete your project for this semester, create a project called **ms5**. Then go back to all your milestones,  and add all the latest versions of your modules (developed throughout the first 4 milestones) to **ms5**.

Get the **PublicationSelector** module (fully developed by another developer) from the project repository and add it to your project. Use **pubSel_Tester.cpp** to test the module and understand its usage.

### PublicationSelector Module

The PublicationSelector module holds the addresses of a selection of the Publications in an array and lets the user select one of them. Upon user's selection, the Library Reference number of the selected publication is returned to the caller module for further actions. 

For example, the array of Publications can be searched for a match to a specific title, and the matches found in the array can be inserted into the PublicationSelector. 
Then the PublicationSelector can be run to display the search results and ask the user to select one of them.  

The logic below (in pubSel_Tester.cpp) is searching all the publications in "LibRecs.txt", displaying the matches to "Harry" and "MoneySense" and letting the user select one.

```C++
// Final Project 
// PublicationSelector Usage demonstration
// File	pubSel_Tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
using namespace sdds;

// prints the publication with the library reference number "ref:
void prnPub(Publication* p[], int size, int ref) {
   int i;
   for (i = 0; i < size; i++) {
      if (ref == p[i]->getRef()) {
         cout << *p[i] << endl;
         i = size; // Exit the loop.
      }
   }
}
int main() {
   ifstream infile("LibRecs.txt");
   Publication* p[1000]{};
   PublicationSelector ps("Publications with Harry and MoneySencse", 5);
   char type{};
   int i;
   for (i = 0; infile; i++) {
      infile >> type;
      infile.ignore();
      if (infile) {
         if (type == 'P')
            p[i] = new Publication;
         else if (type == 'B')
            p[i] = new Book;
         if (p[i]) {
            infile >> *p[i];
            // find publications with Harry or MoneySence in the title
            if (strstr(*p[i], "Harry") || strstr(*p[i], "MoneySense"))
               ps << p[i]; // insert into PublicationSelector if there is match
         }
      }
   }
   if (ps) {
      ps.sort(); // sort them based on date and title
      int ref = ps.run(); // display the publications and select one
      if (ref) {
         cout << "Selected Library Reference Number: " << ref << endl;
         prnPub(p, 100, ref);
      }
      else {
         cout << "Aborted by user!";
      }
   }
   else {
      cout << "No matches to \"Harry\" and \"MoneySense\" found" << endl;
   }
   for (i = 0; p[i]; i++) {  //free the allocated memory
      delete p[i];
   }
   return 0;
}
```

## LibApp Module
Complete the LibApp module as follows

Add the following attributes to the LibApp Module.

### File name
Add an array of 256 characters to hold the publication data file name.

### Publication Pointers Array 
Create and add an array of Publication pointers to the size of SDDS_LIBRARY_CAPACITY.  This array will be populated with all the records of the publication data file when the LibApp is instantiated. 
> We will call Publication Pointers Array "PPA" for short, from now on. 

### Number Of Loaded Publications 
Add an integer to hold the number of Publications loaded into the PPA. 
> We will call this attribute "NOLP" for short, from now on.

### Last Library Reference Number 
Add an integer to hold the last library reference number read from the data file. This number will be used to assign new library reference numbers to new publications added to the library. When a new publication is added to the library, this number will be added by one and then assigned to the new publication.
Doing this; each publication in the library will have a unique library reference number.
> We will call this attribute "LLRN" for short, from now on.

### Publication Type Menu
Add a Menu to the LibApp for selection of publication type. 
The title of this menu is: "Choose the type of publication:"

The publication type menu should also provide two selections:
"Book" and "Publication". 

Setup the publication type menu in the constructor as you did for the main and exit menus.

## Method Implementations 
Create new methods or Modify MS2 methods for the following
### The load method 
First print "Loading Data" and then open the data file for reading and read all the publications in dynamic instances pointed by the PPA Array. 

Do this by first reading a single character for the type of publication and then dynamically instantiating the corresponding object into the next available PPA element. Then extract the object from the file stream and add one to the NOLP. Since the extraction operator calls the proper read function virtually, the object will be properly read from the file. 

Continue this until the ifstream reading fails.

At the end set the LLRN to the reference number of the last publication read.

> See the `pubSel_Tester.cpp` that uses a similar logic to load the publications for example...

### The save method 
First print "Saving Data" and then open the data file stream for overwriting.  (ofstream)
Go through the elements of PPA up to the N0LP. Insert all elements into the ofstream object except those with 0 (zero) as Library Reference Number.  (return value of getRef() method)

> Publications that have the reference number of 0 (zero) are deleted by the user (removed from the library) and therefore should not be saved back into the data file. We refer to these publications as deleted ones. 

### search 
Add needed arguments so the search function can be called in three different modes:
1. Search all
2. Search Checkout Items 
Search only those publications which are on loan by library members
3. Search Available Items
Search only those publications which are not on loan

Search will use an instance of PublicationSelector class to collect the search matches and user selection.
The prompt of the PublicSelector should be:
"Select one of the following found matches:"
The page size for the selector menu should be 15 (the default value)

First, get the type of publication to search for from the user. (user the type selection Menu of the class)

Then print `"Publication Title: "` and get the title to search the PPA for. (up to 256 characters)

Go through all the publications in the PPA and base on the method of search (all the items, on loan items or available ones) check each element and if the publication (pointed by the PPA element) is not deleted and type matches the selection of the user and the title contains the title the user entered, insert it into the PublicationSelector object. 

If matches are found, sort the result and get the user's selection ***and return the library reference number***. If not print "No matches found!"

If the user aborts at any stage print "Aborted!"

#### Abort Scenarios  (searching all)
```text
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 0
Aborted!
-------------------------------------------------------
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2021/11/19 | J. K. Rowling   |
   2- | F861 | Harry Potter and the Chamber o |  N/A  | 2021/11/24 | J. K. Rowling   |
   3- | C872 | Harry Potter and the Deathly H | 64984 | 2021/11/17 | J. K. Rowling   |
   4- | C945 | Harry Potter and the Goblet of |  N/A  | 2021/11/14 | J. K. Rowling   |
   5- | C332 | Harry Potter and the Half/Bloo | 85952 | 2021/11/22 | J. K. Rowling   |
   6- | L290 | Harry Potter and the Order of  |  N/A  | 2021/11/11 | J. K. Rowling   |
   7- | D208 | Harry Potter and the Philosoph | 72685 | 2021/11/19 | J. K. Rowling   |
   8- | R856 | Harry Potter and the Prisoner  |  N/A  | 2021/11/10 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
> x
Aborted!
```
#### Search on loan
```text
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2021/11/19 | J. K. Rowling   |
   2- | C872 | Harry Potter and the Deathly H | 64984 | 2021/11/17 | J. K. Rowling   |
   3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2021/11/22 | J. K. Rowling   |
   4- | D208 | Harry Potter and the Philosoph | 72685 | 2021/11/19 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
>
```
#### Search available publications
```Text
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | F861 | Harry Potter and the Chamber o |  N/A  | 2021/11/24 | J. K. Rowling   |
   2- | C945 | Harry Potter and the Goblet of |  N/A  | 2021/11/14 | J. K. Rowling   |
   3- | L290 | Harry Potter and the Order of  |  N/A  | 2021/11/11 | J. K. Rowling   |
   4- | R856 | Harry Potter and the Prisoner  |  N/A  | 2021/11/10 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
>
```
### `Publication* getPub(int libRef)`  method
Create a method to return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument. 

### the newPublication() method
If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: `"Library is at its maximum capacity!"` and exit. 

Otherwise, 
- print: `"Adding new publication to the library"`
- get the publication type from the user.
- in a publication pointer, instantiate a dynamic "Publication" or "Book" based on the user's choice.
- Read the instantiated object from the cin object.
- If the cin fails, flush the keyboard, print "Aborted!" and exit.
- If the cin is ok, then confirm that the user wants to add the publication to the library using this prompt:
`"Add this publication to the library?"`. If the user did not confirm, print "Aborted!" and exit.
- After the user confirms, if the publication object is valid
   - Add one to the LLRN and set the library reference number to the value
   - Add the publication object's address to the end of the PPA and add one to the NOLP.
   - set the "changed" flag to true
   - print: `"Publication added"`
- If the publication object is not valid print: `"Failed to add publication!"` and delete the allocated memory.

#### Adding a new publication to the library:
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 1
Adding new publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Shelf No: S001
Title: Seneca Student Handbook
Date: 2022/1/5
Add this publication to the library?
 1- Yes
 0- Exit
> 1
Publication added
```
### The removePublication Method
- print: `"Removing publication from the library"`
- Search all the publications
- If the user selects a publication and confirms to remove the publication using the prompt: `"Remove this publication from the library?"`
   - Set the library reference of the selected publication to 0 (zero)
   - set the "changed" flag to true
   - print: `"Publication removed"`

#### removing a publication from the library 
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 2
Removing publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/11 |
   2- | P008 | MoneySense Magazine........... | 72614 | 2021/11/16 |
   3- | P008 | MoneySense Magazine........... | 48096 | 2021/11/17 |
   4- | P008 | MoneySense Magazine........... | 89325 | 2021/11/17 |
   5- | P008 | MoneySense Magazine........... | 33074 | 2021/11/17 |
   6- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/18 |
   7- | P008 | MoneySense Magazine........... | 70451 | 2021/11/24 |
   8- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
> X (to Exit)
> Row Number(select publication)
> 8
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Remove this publication from the library?
 1- Yes
 0- Exit
> 1
Publication removed
```

### The checkOutPub method
- print: `"Checkout publication from the library"`
- Search in available publications only
- If the user selects a publication and confirms to checkout using the prompt: `"Check out publication?"`
   - read a 5 digit number from the console, if invalid print: `"Invalid membership number, try again: "` and read again
   - set the membership number of the selected publication the integer value. 
   - set the changed flag to true
   - print: `"Publication checked out"`

#### Checking out a publication
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 3
Checkout publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/11 |
   2- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/18 |
   3- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
> X (to Exit)
> Row Number(select publication)
> 3
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Check out publication?
 1- Yes
 0- Exit
> 1
Enter Membership number: 12345
Publication checked out
```

### The returnPub() Method
- Print: `"Return publication to the library"`
- Search for "on loan" publications only
- If the user selects a publication and confirms the return using the prompt: `"Return Publication?"`
   - If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days. 
      - Following message is printed: `Please pay $9.99 penalty for being X days late!`, 9.99 is replaced with the penalty value and X is replaced with the number of late days.
   - set the membership number of the publication to 0 (zero)
   - set the "changed" flag to true
   - print: `"Publication returned"`

#### Returning publication to library
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 4
Return publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2021/11/19 | J. K. Rowling   |
   2- | C872 | Harry Potter and the Deathly H | 64984 | 2021/11/17 | J. K. Rowling   |
   3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2021/11/22 | J. K. Rowling   |
   4- | D208 | Harry Potter and the Philosoph | 72685 | 2021/11/19 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
> 2
| C872 | Harry Potter and the Deathly H | 64984 | 2021/11/17 | J. K. Rowling   |
Return Publication?
 1- Yes
 0- Exit
> 1
Please pay $4.00 penalty for being 8 days late!
Publication returned
```
### The constructor
Add the following to the constructor:
- Initialize and set the [Publication Type Menu](#publication-type-menu) as described in the attributes section.
- Add an argument to the constructor to receive the file name. Set the file name attribute to the incoming argument.

## MS5 Sample execution

### Milestone 5 Test One  (m51)

Data file: [LibRecsSmall.txt](ms5/LibRecsSmall.txt)

- load
- Book and Publication entry
- setting the library reference number
- save

Data Entry:
```Text
1
1
S001
Book one
2022/6/10
John Doe
1
1
2
S002
Daily one
2022/6/10
1
0
1
```
[Correct Output](ms5/m51_correct_output.md)

### Milestone 5 Test Two  (m52)

Data file: [LibRecsSmall.txt](ms5/LibRecsSmall.txt)

- load
- Removing Publication and Book
- save

Data Entry:
```Text
2
1
e
3
1
2
2
e
3
1
0
1
```
[Correct Output](MS5/m52_correct_output.md)

### Milestone 5 Test Three (m53)

Data file: [LibRecsSmall.txt](MS5/LibRecsSmall.txt)

- load
- Checking out and no match found
- Checking out with success
- save

Data Entry:
``` Text
3
1
Harry
3
1
Web
1
1
12345
0
1
```

[Correct Output](MS5/m53_correct_output.md)

### Milestone 5 Test Four (m54)

Data file: [LibRecsSmall.txt](MS5/LibRecsSmall.txt)

- load
- Returning a Book with no penalty
- Returning a Book with penalty
- Returning a Publication
- save

Data Entry:
```Text
4
1
Harry
1
1
4
1
Hobbit
1
1
4
2
e
2
1
0
1
```


[Correct Output](MS5/m54_correct_output.md)

### Milestone 5 Test Five  (m55)

Data file: [LibRecs.txt](MS5/LibRecs.txt)

>Before starting this this test make sure that in "Lib.h" <br />
The maximum capacity of the library is set to 333. <br />`>>  const int SDDS_LIBRARY_CAPACITY = 333;  <<`

- load
- Adding a publication
- Add another publication unsuccessfully
- save

Data Entry:
```Text
1
2
S003
News Daily
2022/7/30
1
1
0
1
```

[Correct Output](MS5/m55_correct_output.md)

### Milestone 5 Test Six (m56)

Data file: [LibRecs.txt](MS5/LibRecs.txt)

- load
- Aborting and error handling
- exit without saving

Data Entry:
```Text
1
0
2
2
<ENTER>
x
3
1
<ETNER>
1
1
123456
12345
4
2
<ENTER>
x
0
0
1
```

[Correct Output](MS5/m56_correct_output.md)  

## MS5 Submission

For marking see [Final Project Mark and Due dates](#final-project-mark-and-due-dates)

Files to upload to matrix:
```Text
Lib.h
Utils.cpp
Utils.h
Date.cpp
Date.h
Menu.cpp
Menu.h
Streamable.cpp
Streamable.h
Publication.cpp
Publication.h
Book.cpp
Book.h
PublicationSelector.cpp
PublicationSelector.h
LibApp.cpp
LibApp.h
LibAppMain.cpp
LibRecsSmall.txt
LibRecs.txt
```

Upload all the source code , the tester program and the data files to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following commands from your account (replace `profname.proflastname` with your professor’s Seneca userid):

Each successful submission will earn you 10% of the prject mark (and with 4 submissions of milestones the total will be 100%)

```
~profname.proflastname/submit 2??/prj/m51
~profname.proflastname/submit 2??/prj/m52
~profname.proflastname/submit 2??/prj/m53
~profname.proflastname/submit 2??/prj/m54
~profname.proflastname/submit 2??/prj/m55
~profname.proflastname/submit 2??/prj/m56
```
and follow the instructions.

- *2??* is replaced with your subject code

### The submit program's options:

```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


