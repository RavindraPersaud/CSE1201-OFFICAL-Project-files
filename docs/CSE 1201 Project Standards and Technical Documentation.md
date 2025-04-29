
# CSE1201 Project Standards

## Table of Contents
- [Purpose of File](#purpose-of-file)

- [Code Formatting](#code-formatting)
  - [Naming Conventions](#naming-conventions)
  - [Curly Braces and Formatting](#curly-braces-and-formatting)
  - [Whitespace Rules](#whitespace-rules)
  - [Header File Organization](#header-file-organization)

 - [Documentation Rules](#documentation-rules)
  - [Commenting Practices](#commenting-practices)
  - [File Description](#file-description)
  - [Concise Documentation](#concise-documentation)
  - [Unnecessary Documentation](#unnecessary-documentation)

- [Project File Structure](#project-file-structure)

- [Final Notes](#final-notes)

******

## Purpose of File
This document provides rules for maintaining **readability**, **consistency**, and **ease of maintenance** throughout the project.

******

## Code Formatting

### Naming Conventions
- Use **snake_case** for variables, functions, and filenames:
  my_file;
  my_function();
  

- Use **PascalCase** for structure names:
  
  typedef struct MyStruct {
      // fields
  } MyStruct;

- Use **UPPER_SNAKE_CASE** aka **MACRO_CASE** for any variables that are read only. i.e Macros and the variables 
modified by the const data modifier.
    #define MY_HEADER_H 
    #define IMPORTANT_SCALE_FACTOR 3

    const int MAXIMUM_FIELD_LENGTH;


******

### Curly Braces and Formatting
- Always place the opening curly brace `{` on the same line as the control statement.
- Always use curly braces `{}` even for single-line blocks.

Example:
int main() {
    // code
}

if (condition) {
    do_something();
}

******

### Whitespace Rules
- Use whitespace to clearly separate elements:

Correct:
int x = 123;
Mylist = (1, 2, 3, 4);


Incorrect:
int x=123;
Mylist = (1,2,3,4);

******

### Header File Organization
- Place **system headers** first, then **custom headers**.
- Alphabetize headers within each group.

Example:
#include <art.h>
#include <stdio.h>

#include "file_handler.h"
#include "message_handler.h"

******

******

## Documentation Rules

### Commenting Practices
- Always place comments directly **above** the code they describe.
- Use `/* */` for longer explanations.
Example:
// Initializes variables
int x = initialize_variables();

Multiline Example:
/*
Initializes variables and sets the system to default mode.
Should be called at the start of the program.
*/
int initialize_system() {
    // code
}


### File Description
Include a description at the top of each file:
/*
my_file.c:
Calculates the sum of two numbers for the main.c file to print.
It also handles error checking and formatting.
*/

******

### Concise Documentation
- Summarize what the function/block does and why.

Example:
/*
Calculates the addition of the same number with two different exponents.
Example: 3^2 + 3^5.
The result is used in important_function() for further processing.
*/
int calculate_exponent_sums(int number, int exponent1, int exponent2) {
    int sum = pow(number, exponent1) + pow(number, exponent2);
    return sum;
}


******

### Unnecessary Documentation
Avoid obvious, repetitive comments inside simple functions.

**Don't:**
int small_function() {
    // Prints to the terminal that this is a small function
    printf("This is a small function.");
    
    // Prints to the terminal how many things it does
    printf("It does only 1 or 2 things.");
    
    // Prints again...
    printf("Easy to understand.");
    return 0;
}


**Do:**
// Example of a small function for demonstration
int small_function() {
    printf("This is a small function.");
    printf("It does only 1 or 2 things.");
    return 0;
}


******

## Project File Structure
/cse1201_official_project
|-- /src
|   |-- main.c
|   |-- /task_1
|   |
|   |-- /task...
|
|-- /include
|   |-- function_name_1.h
|   |-- ...
|   
|-- /data
|   |-- message_storage.dat
|
|-- /docs
|   |-- document_1.md
|   |-- ...
|
|-- README.md
|-- NotPad--.exe


******


### /src
Contains **main.c** and primary source files.

### .c Files in /src
Grouped based on the task they perform.

### /include
Stores header files (`.h`) for functions used across multiple `.c` files.

### /storage
Contains text/data files needed by the program.

### /docs
Holds all documentation files.


***

## Final Notes
- Be **consistent** and **organized**.
- Follow these standards strictly unless project supervisors specify otherwise.
- Good coding standards make it easier for others to understand and maintain your work!
