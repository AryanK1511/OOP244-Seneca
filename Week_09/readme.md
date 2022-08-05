# Workshop #9: Derived Classes and Resources
- Version 1.0
In this workshop, you are to code/complete two classes:
- **Name** A class that encapsulates a Name in a cString dynamically which includes no spaces.
- **FullName**: A **Name** Class that has an additional lastname kept in a cString (dynamically) which can include spaces

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Derive a class with resource from a base class which also includes a dynamic cString.
- Override virtual an non-virtual methods of the base class.
- Apply [the rule of three](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)) to the base and the derived class
- Use your acquired skills throughout the semester to read and write dynamic data from int into date files.
- describe what you have learned in completing this workshop


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

# Part 1 - LAB (100%)

## the `Name` class
Complete the implementation of the following class and add the rule of three:

```C++
  class Name {
      char* m_value;
   public:
      Name();  
      Name(const char* name);
      // Rule of three goes here:


      operator const char* ()const;
      virtual operator bool()const;
      virtual std::ostream& display(std::ostream& ostr = std::cout)const;
      virtual std::istream& read(std::istream& istr = std::cin);  
   };
```
### `Name();`

Creates an empty name

### `Name(const char* name);`
Keeps a dynamic copy of the name in the `Name` object.

### the Rule of three
Makes sure copy, assignment and destruction do not leak any memory.

### `operator const char* ()const;`
Returns the address of the dynamic Cstring.

### `virtual operator bool()const;`
Return true of name is not empty, otherwise, it returns false.

### `virtual std::ostream& display(std::ostream& ostr = std::cout)const;`
Inserts the Cstring value into `ostr` without going to new line if the `Name` is valid and then returns the `ostr`;

### `virtual std::istream& read(std::istream& istr = std::cin);` 
Dynamically reads the Cstring from `istr` without any spaces (stops at space) and keeps the address in the `m_value` pointer.<br />
If the read is successful it will ignore one character from istr.<br />
returns istr at end.

### Helper operator overloads.
Overload the insertion and extraction operators so Name can be inserted into ostream and extracted from istream using the display and read;

## The `FullName` class

Complete the implementation of the following class and add the rule of three. Also, override all the member functions of the Base class `Name`.

```C++
  class FullName : public Name {
      char* m_value;
   public:
      FullName();
      FullName(const char* name, const char* lastName);
      // Rule of three goes here:
      
      
      operator const char* ()const;
      virtual operator bool()const;
      virtual std::ostream& display(std::ostream& ostr = std::cout)const;
      virtual std::istream& read(std::istream& istr = std::cin);  
   };

```

### `FullName();`
Creates an empty FullName.

### `FullName(const char* name, const char* lastName);`
Passess `name` to the constructor of the base class and dynamically keeps a copy of `lastName` in the `m_value` of `FullName`

### the Rule of three
Makes sure copy, assignment and destruction do not leak any memory by invoking the proper methods and constructor of the base class when implementing the rule of three.

### `operator const char* ()const;`
Returns the address in the m_value of the FullName.
### virtual operator bool()const;
Returns true only if both FullName and Name are not empty.

### virtual std::ostream& display(std::ostream& ostr = std::cout)const;
If the FullName is not empty it will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line. Then it will return the ostream reference.

### virtual std::istream& read(std::istream& istr = std::cin);  
Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character. The newline character is removed from istream and the istream reference is returned. 


## Tester Program
```C++
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

```
## Expected output
```text
Simpons Family:
Abraham Simpson
Bart Simpson
Homer Simpson
Lisa Simpson
Maggie Simpson
Marge Simpson
Mona Simpson

sorted.txt----------------------------------------
1: Kumiko Albertson
2: Jasper Beardly
3: Comic Book Guy
4: Wendell Borton
5: Jacqueline Bouvier
6: Ling Bouvier
7: Patty Bouvier
8: Selma Bouvier
9: Kent Brockman
10: Chazz Busby
11: Sea Captain
12: Carl Carlson
13: Shauna Chalmers
14: Lunchlady Doris
15: Surly Duff
16: Ned Flanders
17: Rod Flanders
18: Todd Flanders
19: Maude Flanders[D]
20: Baby Gerald
21: Alice Glick
22: Barney Gumble
23: Gil Gunderson
24: Wise Guy
25: Herman Hermann
26: Bernice Hibbert
27: Elizabeth Hoover
28: Lionel Hutz
29: Rabbi Hyman Krustofsky
30: Gloria Jailbird
31: Snake Jailbird
32: Old Jewish Man
33: Mayor Joe Quimby
34: Jimbo Jones
35: Edna Krabappel
36: Akira Kurosawa
37: Dewey Largo
38: Lenny Leonard
39: Helen Lovejoy
40: Jessica Lovejoy
41: Bumblebee Man
42: Troy McClure
43: Sideshow Mel
44: Roger Meyers Jr.
45: Hans Moleman
46: Nelson Muntz
47: Lindsey Naegle
48: Apu Nahasapeemapetilon
49: Manjula Nahasapeemapetilon
50: Janey Powell
51: Ruth Powers
52: Martin Prince
53: The Rich Texan
54: Luigi Risotto
55: Judge Roy Snyder
56: Abraham Simpson
57: Bart Simpson
58: Homer Simpson
59: Lisa Simpson
60: Maggie Simpson
61: Marge Simpson
62: Mona Simpson
63: Agnes Skinner
64: Seymour Skinner
65: Waylon Smithers
66: Miss Springfield
67: Brandine Spuckler
68: Cletus Spuckler
69: Dolph Starbeam
70: Disco Stu
71: Moe Szyslak
72: Drederick Tatum
73: Allison Taylor
74: Squeaky-Voiced Teen
75: Krusty The Clown
76: Johnny Tightlips
77: Kirk Van Houten
78: Luann Van Houten
79: Milhouse Van Houten
80: Ralph Wiggum
81: Sarah Wiggum
82: Groundskeeper Willie
83: Rainier Wolfcastle
84: Artie Ziff
85: Uter Zorker
86: Kearney Zzyzwicz
87: END OF DATA---------------------------------------
```

## PART 1 Submission (lab)

### Files to submit:  

```Text
Name.cpp
Name.h
FullName.cpp
FullName.h
main.cpp
simpsons.txt
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

No data entry is needed

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
