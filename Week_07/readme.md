# Workshop #7: Derived Classes & Custom I/O Operators

In this workshop, you will work with classes that make up the hierarchical structure. The base or parent class will be a `MemberParliament` that holds common attributes of a vehicle with an engine, then the child class `Minister` will be derived from the parent class. In addition to this hierarchy, we will define custom input/output operators for these classes.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Inherit a derived class from a base class
- Shadow a base class member function with a derived class member function
- Access a shadowed member function that is defined in a base class
- Utilize custom input/output operators with these classes
- Describe to your instructor what you have learned in completing this workshop



## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
## Due Dates

Depending on the section you are enrolled in, the submission due day of the week may shift a day or two. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]

### Overall workshop due days
- day 1: Workshop open for preview<br/>
  (If you need to check your program with the submitter, you can use `-feedback` option to test the execution without submission)
- day 2: submission opens for both parts 1 and 2
- day 5: (end of day) Part 1 due
- day 8: (end of day) Part 2 due
- day 9: (end of day) submissions rejected

If at the deadline (end of day 8) the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

# lab (part 1) (100%)


## `MemberParliament` Module

Design and code a class named `MemberParliament` that holds information about a member of parliament. Place your class definition in a header file named `MemberParliament.h` and your function definitions in an implementation file named `MemberParliament.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `MemberParliament` Class

Design and code a class named `MemberParliament` that holds information about a member of parliament.


#### `MemberParliament` Private Members

The class should be able to store the following data (Use appropriate names!):

- The parliament id number as a statically allocated array of characters of size 32.
- The district the MP represents as a statically allocated array of characters of size 64.
- The age of the MP.

You can add any other private members to the class, as required by your design.



#### `MemberParliament` Public Members

- A custom constructor that receives as parameters the MP Id and age.  Set the district the MP represents as  `Unassigned`. Assume all data is valid.

- `void NewDistrict(const char* district)`: assigns the MP to new district. Prints to the screen the message
  ```txt
  |[MP ID]| |[CURRENT_DISTRICT] ---> [NEW_DISTRICT]|<ENDL>
  ```
  where
  - the mp id is a field of 8 characters aligned to the right
  - current district is a field of 20 characters aligned to the right
  - new district is a field of 23 characters aligned to left

- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [MP ID] | [AGE] | [DISTRICT]
  ```
- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  MP Age: [USER TYPES HERE]
  MP Id: [USER TYPES HERE]
  District: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `MemberParliament` into a stream and extract a `MemberParliament` from a stream. These operators should call the `write`/`read` member functions in the class `MemberParliament`.


## `Minister` Module

Design and code a class named `Minister` that holds information about a minister of the crown in the Canadian Cabinet. Place your class definition in a header file named `Minister.h` and your function definitions in an implementation file named `Minister.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Minister` Class

Design and code a class named `Minister` that holds information about the a minister of the crown in the Canadian Cabinet.  **This class should inherit from `MemberParliament` class.**


#### `Minister` Private Members

The class should be able to store the following data (on top of data coming from the parent class):

- The name of the Prime Minister the Minister reports toas a statically allocated array of characters of size 50.
- The year the minister assumed office.

You can add any other private members in the class, as required by your design.  **Do not duplicate members from the base class!**



#### `Minister` Public Members

- a custom constructor that receives the following information about the Minister: idd, age, the year assumed office, district, and name of the prime minister.  Call the constructor from the base class and pass the relevant data to it.  update the private data members of the Minister accordingly

- `void changePM(const char* pm)`: a mutator that updates the PM the minister reports to. 

- `void assumeOffice(double year)`: a mutator that updates the year the minister assumed office

- `ostream& write(ostream& os)`: a query that inserts into `os` the content of the object in the format
  ```txt
  | [ID] | [age] | [DISTRICT] | [PM]/[Year Assumed Office]
  ```

- `istream& read(istream& in)`: a mutator that reads from the stream `in` the data for the current object
  ```txt
  Age: [USER TYPES HERE]
  Id: [USER TYPES HERE]
  District: [USER TYPES HERE]
  Reports TO: [USER TYPES HERE]
  Year Assumed Office: [USER TYPES HERE]
  ```


#### Helper Functions

- overload the insertion and extraction operators to insert a `Minister` into a stream and extract a `Minister` from a stream. These operators should call the `write`/`read` member functions in the class `Minister`.

## `w7_main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.
```C++
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

```


### Sample Output

```Text
--------------------------------------------------------------
|> Person 1: MemberParliament
--------------------------------------------------------------
| MP9403 | 59 | Unassigned

|  MP9403| |          Unassigned ---> Scarborough            |
|  MP9403| |         Scarborough ---> Mississauga            |
|  MP9403| |         Mississauga ---> Huron County           |

| MP9403 | 59 | Huron County

--------------------------------------------------------------
|> Person 2: Read/Write
--------------------------------------------------------------
Age: 40
Id: MP9566
District: Milton

| MP9566 | 40 | Milton

--------------------------------------------------------------
|> Person 3: Minister
--------------------------------------------------------------
|  MP9573| |          Unassigned ---> Pickering              |

|  MP9573| |           Pickering ---> Whitby                 |
Status of New Election | MP9573 | 63 | Whitby | Trudeau/2007

|  MP9573| |              Whitby ---> Kitchener              |
Status of New Election | MP9573 | 63 | Kitchener | Biden/2010

|  MP9573| |           Kitchener ---> Oakville               |
Status of New Election | MP9573 | 63 | Oakville | Trump/2015

--------------------------------------------------------------
|> Person 4: Read/Write
--------------------------------------------------------------
Age: 66
Id: MP9701
District: Sudbury
Reports TO: Obama
Year Assumed Office: 2021

| MP9701 | 66 | Sudbury
| MP9701 | 66 | Sudbury | Obama/2021

```


### Files to submit:  

```Text
MemberParliament.cpp
MemberParliament.h
Minister.cpp
Minister.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

```text
40
MP9566
Milton
66
MP9701
Sudbury
Obama
2021
```

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.




# PART2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Reflection Submission (part 2)


Upload the **reflect.txt** to your `matrix` account. 

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
