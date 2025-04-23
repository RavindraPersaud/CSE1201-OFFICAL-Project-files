CSE1201 Project Standards

##Table of Contents
- [Purpose](#purpose)
- [Coding Style](#coding_style)
  - [Naming Conventions](#coding_style)
  - [Curly Braces and Formatting](#coding_style)
  - [Whitespace Rules](#coding_style)
  - [Header File Organization](#coding_style)
  - [Commenting Practices](#coding_style)
- [Documentation Rules](#docs)
  - [File Descriptions](#docs)
  - [Concise Documentation](#docs)
  - [Unnecessary Documentation](#docs)
- [Project File Structure](#file_struct)
- [How to Organise Code](#organise)

##purpose
Purpose of File:
Provide the rules to maintain readability and consistency throughout the project and allow ease of maintenance. 

NOTE: This file was written in Google docs then downloaded as .md. As a result the formatting looks a bit strange when opening just the .md file. Use link to see original formatting.
https://docs.google.com/document/d/1Qy4Uuc--ueJHGzOF7M2OKbOd8G5pCz84Q-lMbqmHm2Y/edit?usp=sharing 

##coding_style
Coding Style
Naming conventions
Use snake_case
example:
my_file,
my_function()
	
Exception: Structures.
Structures must use PascalCase:
Eg
MyStruct(){
	//code
}


How curly braces are placed
Int main(){
	//code
}


Use whitespace to separate out symbols when you can.
	Int x=123; [no]
Mylist = (1,2,3,4); [no]

	Int x = 123; [yes]
Mylist = (1, 2, 3, 4); [yes]


Organise header files in alphabetical order.
	#include <art>
	#include <stdio.h>

	Followed by file/function imports.
	Import s“..balaldja/dalfjak/hello.txt:”

Comments  are always placed above the code you are referring to. 
short comments:
//comment
int x do_this(){}

/*
Multiple
line
Explanation
comment
*/
	myFunc(){}

##docs
Documentation Rules
File description(.h, .c, .md etc )
Include brief description of the file’s purpose at the top of any file you create

Opening my_file.c would read:

/*
my_file.c:
calculates the sum of two numbers for the main.c file to print.
It also handles blah blah blah…
*/


Concise documentation
Do not add too many comments that will clutter the code. Say what the function/code block does and why it's there.

Example:
\*
Finds the calculates the addition of the same number with two different exponents.  Example: 3^2+ 3^5.
The result is used in important_function() as a value it needs before it can work.

*/
int calculate_exponent_sums( number, exponent1, exponent2);{
	int sum =  exponent1 + exponent2;
	int product = number ** sum;
	return product;
}


Unnecessary documentation
Dont comment inside the code block/ function unless it’s too complex for simple documentation. 
Example:
Do:
//used as example of small function to give reader general idea them
int small_function(){
	printf(“this is a small function.”);
	printf(“does like 1 or 2 things”);
	printf(“easy to keep track of and understand while reading the
above comment”);

return 0;
}

		Don’ Do:
		int small_function(){
			#prints to the terminal that this is a small function
	printf(“this is a small function.”);

	#prints to the terminal how many things is done
	printf(“does like 1 or 2 things”);

	#prints to the … you get the point
	printf(“easy to keep track of and understand while reading the
above comment”);
return 0;
}


##file_struct
Project File Structure
	/cse1201_official_project
	|--/src
	|	|--main.c
	|	|--/task_1
	|	|	|--function_name_1.c
	|	|
|	|--/task_2
	|	|	|--function_name_2.c
	|	|	|--function_name_3.c
	|	|
	|	|--/task…
|
|--/helper_functions
	|	|-- helper_function_name.c
	|	|--...
|
|--/include
	|	|-- function_name_1.h
	|	|-- …
|	
|--/storage
	|	|--storage_file.dat
	|
|--/docs
	|	|--document_1.md
	|	|--document_2.pdf
	|
	|--make_file
	|--README.md





##organise
How to Organise Code
/src 
Abbreviation for source files. Contains main.c and all the functions main.c calls directly.

/task
Represents a folder that is named according to the task the person assigned had to make
	Example: |--/message_handling
			|--message_reciever.c
			|--message_sender.c

.c files in /src
Main.c relies on these functions to work and are organised into folders based on the task those functions were coded to accomplish


/helper_functions
Contains functions that not called in main.c but reused throughout multiple source files


/include
Stores the .h folders created to port functions from file to file.


/storage
Contains the text file that is used to store messages for later access


/docs
Stores the documentation

NOTE: Files/folders that cannot be categorised into the above just go straight to the root folder with the README.md and the cmake file.
