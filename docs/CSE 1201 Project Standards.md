
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

### Curly Braces 
- Always place the opening curly brace { on the same line as the control statement.
- Always use curly braces {} even for single-line blocks.

Example:
int main() {
    // code
}

if (condition) {
    do_something();
}

******

### Whitespace Rules
- Use whitespace to clearly separate operators(=, >, && etc.) and symbols(",", "|", etc.) from values/variables.
Incorrect:
int x=123;
Mylist = (1,2,3,4);

Correct:
int x = 123;
Mylist = (1, 2, 3, 4);

- Put two blank lines before and after functions and structs.(see example_of_standards.c)
- It in mandatory to use a blank space above a comment in a code block, except for the first line of the block.

void cool_function(){ 
    //Mandatory to start a code block right below the declaration . This function still adresses the comment below
    int example_function();

    //Lines taht have comments ater another are separated by a single space:
    int for(i = 0; i < 10; i++){
        printf("this is an example." )
    }
    }

- It is optional to use a blank line to spearate adjacent lines of code in a code block.
Allowed:
int main(){
    int x = 5 + 3
    int y = x * 12
    printf("%d is a really cool number.\n", y);
}

******

### Header File Organization
- Place **system libraries** in alphabetical order, a blank line,  **custom libraries**.
- Alphabetize headers within each group.

Example:
#include <art.h>
#include <stdio.h>

#include "file_handler.h"
#include "message_handler.h"

******


## Documentation Rules

### Commenting Practices
- Always place comments directly **above** the code they describe.
- Use /* */ for longer explanations.
Example:
// Initializes variables
int x = initialize_variables();


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
- Ideally a good comment summarizes **what** the function/code block does and **why**.

Example:
/*
Calculates the addition of the same number with two different exponents.(what)
The result is used in important_function() for further processing. (why)
*/
int calculate_exponent_sums(int number, int exponent1, int exponent2) {
    int sum = pow(number, exponent1) + pow(number, exponent2);
    return sum;
}

**Note:** The format of "what and why" is not a rigid rule, use own judgement to determine a comment's content.  
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
/group-2-semester-project
|-- /src
|   |-- main.c
|   |-- source_files.c
|   |-- NotPad--.exe
|   |-- ...
|
|-- /include
|   |-- header_files.h
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
|-- ...


******
### /group-2-semester-project
The root file contains the folders mentioned below, a user manual (README.md) and any random files/folders that 
cannot be organised into the folders seen in the file structure.

### /src
Contains the source files including **main.c** and the NotPad--.exe file.

### .c Files in /src
The source files define functions which will be called in main.c or by other .c files.

### /include
Stores header files (.h) containing at minimum 2 callable items. If a .c file has 2 or more functions from it being
called to another .c file, make a header file for it.

### /data
Stores the .dat file that records the user's message information.

### /docs
Holds technical documentation and other relevant documents to the project for ease of access.

******

## Final Notes
- Be **consistent** and **organized**.
- Follow these standards strictly unless project supervisors specify otherwise.
- Good coding standards make it easier for others to understand and maintain your work!
