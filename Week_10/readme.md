# Workshop #10: Function Templates

Version 1.0

In this workshop, you are to code 3 function templates and 1 insertion operator template:
- "find": checks if a key value matches an array item at a provided index
- "find": takes 2 incoming keys of different types and searches through an array to find the first match.
- "operator <<": inserts a collection into the ostream
- "loadCollection": takes an object and adds it to a collection of the same type


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

-	code function templates
-	implement calls to function templates
-	describe what you have learned in completing this workshop


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

Look at the code provided in the **Collection** template module, study it and understand it. The Collection class is a template that works like a dynamic array of objects and resizes itself as objects are added to it. The code snippet below demonstrates how Collection works:  

```C++
Collection<double> dCol;
dCol.add(4.23);
dCol.add(5.34);
dCol.add(6.45);
cout << "We have " << dCol.size() << " items in the Collection!" << endl;
for(int i=0; i< dCol.size();i++){
    cout << dCol[i] << endl;
}
```
Output:
```Text
We have 3 items in the Collection!
4.23
5.34
6.45
```
## Supplied Modules:
- Collection
- Write 
- Book
- Pet
- Card

**Do not modify these modules!**  Look at the code and make sure you understand them.
# Modules that you will modify (The templateFunctions module and the main module)

## templateFunctions module
Implement this module in 'templateFunctions.h' header file.

- "find": checks if a key value matches an array item at a provided index
- "find": takes 2 incoming keys of different types and searches through an array to find the first match.
- "operator <<": inserts a collection into the ostream
- "loadCollection": takes an object and adds it to a collection of the same type

### `find`  3 argument function template

Create a function template called **find** to check if a key value matches an array item at a provided index
Arguments:
- An array of templated objects; the same type as the Collection type. (template type 1)
- An integer variable that represents the index to use in the comparison
- A  **key** templated value to search for, in the array of objects. (template type 2)

The find function is rather simple and will return true or false based on the following condition:
- if the element at index **i** of the array equals the key or not
Use the "==" operator to check for a match between the objects and the key. This operator is overloaded in each testing class used.

### `find`  4 argument function template

Create a function template called **find** that accepts four arguments in any order you prefer:
- An array of templated objects; the same type as the Collection type. (template type 1)
- An integer represents the number of elements in the array of objects.
- A  **key** templated value as one of our search parameters. (template type 2)
- Another **key** templated value as our second search parameter. (template type 3) 

The find function template returns an int that represents the index of a found item that matches the 2 search keys, and returns -1 if no successful matches were found.
The find function goes through all the elements of the array of objects checks if the keys are comparable to the array object (use the overloaded comparison operator).  


### `Insertion operator(<<)` template
Lists all the elements of an array. 

The insertion operator takes a reference to an ostream object and a collection template as parameters.
It will then iterate over every item in the collection and insert it and an endl into the ostream parameter.


### `loadCollection` function template
This function takes a reference to a collection (of template type 1) and an object of the same type.
It will then call the overloaded += operator in the collections class to add the new item.  

This function returns a constant collection reference.

### Template type requirements
Each function and overloaded operator that uses templates require some code that is already provided to you in order to work properly.
Add a comment to each of the functions/operator you just created listing what code is needed/required to allow those functions to work. 
**Then also copy these comments to the part 2 reflection of the workshop.**

## The main module
> In this workshop you are modifying the main module. Make sure to update the comments at the top to reflect your work on the module

Modify the main module and call the **find** function with 3 arguments at all spots with the comment labled //TODO 1:
> See the comments in **main.cpp** on where to use this function

Modify the main module and call the **find** function with 4 arguments at all spots with the comment labled //TODO 2:
> See the comments in **main.cpp** on where to use this function

Modify the main module and call the **insertion <<** operator at all spots with the comment labled //TODO 3:
> See the comments in **main.cpp** on where to use this function

Modify the main module and call the **loadCollection** function at all spots with the comment labled //TODO 4:
> See the comments in **main.cpp** on where to use this function


## output

```Text
Printing all the Cards:
King of Hearts
7 of Clubs
5 of Spades
Jack of Diamonds
10 of Hearts
Ace of Spades
Queen of Diamonds

Searching for King of Hearts, Jack of Diamonds and 10 of Spades cards:
Ace of Spades
Jack of Diamonds
King of Hearts
10 of Hearts

(34567 IncorrectTitle), is not in our collection of books

Our results of our Book search: (Dune, IncorrectTitle, Frankenstein, Foundation)
23456 Dune (Author: Frank Herbert) Price: $9.99
67890 Frankenstein (Author: Mary Shelly) Price: $4.99
45678 Foundation (Author: Issac Asimov) Price: $19.99

All the books listed in our collection:
23456 Dune (Author: Frank Herbert) Price: $9.99
45678 Foundation (Author: Issac Asimov) Price: $19.99
56789 The Lord of the Rings (Author: J.R.R. Tolkien) Price: $7.99
67890 Frankenstein (Author: Mary Shelly) Price: $4.99
34567 The Martian (Author: Andy Weir) Price: $10.50
12345 The Hitchhiker's Guide to the Galaxy (Author: Douglas Adams) Price: $12.99

All the Pets listed in our collection:
Type: Rat, Name: Carl Age: 3
Type: Rabbit, Name: Mindy Age: 2
Type: Weasel, Name: Lenny Age: 4
Type: Dog, Name: Waylon Age: 7
Type: Cat, Name: Frank Age: 12
Type: Dog, Name: Billy Joel Age: 13

Our results of our Pet Query: (Dog)
Type: Dog, Name: Waylon Age: 7
Type: Dog, Name: Billy Joel Age: 13

Our results of int Filter:
90
90

```




### Files to submit:  
All the files are needed for compilation but only the first two files will be submitted to your professor. 
```Text
main.cpp
templateFunctions.h
Book.cpp
Book.h
Card.cpp
Card.h
Collection.h
Pet.cpp
Pet.h
Write.cpp
Write.h
```

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

No Data entry needed.

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
