# CSE1201 Project Standards

## Table of Contents
- [Purpose of File](#purpose-of-file)
- [Coding Style](#coding-style)
  - [Naming Conventions](#naming-conventions)
  - [Curly Braces and Formatting](#curly-braces-and-formatting)
  - [Whitespace Rules](#whitespace-rules)
  - [Header File Organization](#header-file-organization)
  - [Commenting Practices](#commenting-practices)
- [Documentation Rules](#documentation-rules)
  - [File Description](#file-description)
  - [Concise Documentation](#concise-documentation)
  - [Unnecessary Documentation](#unnecessary-documentation)
- [Project File Structure](#project-file-structure)
- [How to Organise Code](#how-to-organise-code)


## Purpose of File
Provide the rules to maintain readability and consistency throughout the project and allow ease of maintenance.

## Coding Style

### Naming Conventions
- Use snake_case:
  
  my_file,
  my_function()
  
- Exception: Structures must use PascalCase:
  
  MyStruct(){
      // code
  }
  

### Curly Braces and Formatting

int main() {
    // code
}


### Whitespace Rules
- Use whitespace to separate out symbols:
  
  int x = 123; // [yes]
  Mylist = (1, 2, 3, 4); // [yes]
  
  
  int x=123; // [no]
  Mylist = (1,2,3,4); // [no]
  

### Header File Organization
Organize header files alphabetically when importing:
#include <art.h>
#include <stdio.h>
...

### Commenting Practices
- Place comments above the code they refer to:
  
  // comment
  int x = do_this();
  

- For multiline explanations:
  
  /*
  Multiple line
  explanation
  comment
  */
  myFunc();
  

---

## Documentation Rules

### File Description
Include a brief description of the file’s purpose at the top of any file you create:

/*
my_file.c:
Calculates the sum of two numbers for the main.c file to print.
It also handles blah blah blah...
*/


### Concise Documentation
- Summarize what the function/block does and why:
  
  /*
  Calculates the addition of the same number with two different exponents.
  Example: 3^2 + 3^5.
  The result is used in important_function() as a value it needs before it can work.
  */
  int calculate_exponent_sums(int number, int exponent1, int exponent2) {
      int sum = exponent1 + exponent2;
      int product = pow(number, sum);
      return product;
  }
  

### Unnecessary Documentation
Avoid adding comments inside simple code blocks:
- **Do:**
  
  // Used as an example of a small function to give readers a general idea.
  int small_function() {
      printf("This is a small function.");
      printf("Does like 1 or 2 things.");
      return 0;
  }
  
- **Don’t Do:**
  
  int small_function() {
      // Prints to the terminal that this is a small function
      printf("This is a small function.");
      
      // Prints to the terminal how many things it does
      printf("Does like 1 or 2 things.");
      
      // Prints to the... you get the point
      printf("Easy to keep track of and understand while reading the above comment.");
      return 0;
  }
  

---

## Project File Structure


/cse1201_official_project
|-- /src
|   |-- main.c
|   |-- /task_1
|   |   |-- function_name_1.c
|   |
|   |-- /task_2
|   |   |-- function_name_2.c
|   |   |-- function_name_3.c
|   |
|   |-- /task...
|
|-- /helper_functions
|   |-- helper_function_name.c
|   |-- ...
|
|-- /include
|   |-- function_name_1.h
|   |-- ...
|   
|-- /storage
|   |-- storage_file.dat
|
|-- /docs
|   |-- document_1.md
|   |-- document_2.pdf
|
|-- make_file
|-- README.md


---

## How to Organise Code

### /src
Abbreviation for source files. Contains main.c and all the functions main.c calls directly.

### /task
Represents a folder named according to the task assigned:
- Example:
  
  /message_handling
    |-- message_receiver.c
    |-- message_sender.c
  

### .c Files in /src
main.c relies on these functions to work. They are organized into folders based on the task those functions were coded to accomplish.

### /helper_functions
Contains functions not called in main.c but reused throughout multiple source files.

### /include
Stores the .h files created to port functions from file to file.

### /storage
Contains text files used to store messages for later access.

### /docs
Stores the documentation.

Note: Files or folders that cannot be categorized into the above should go directly into the root folder with the README.md and make_file.