**Purpose of file:**  
Provide the rules to maintain readability and consistency throughout the project and allow ease of maintenance. 

**Coding style.**

1. **Naming conventions**

   Use snake\_case

   *example:*

   *my\_file,*

   *my\_function()*

   	

   **Exception**: Structures.

   Structures must use PascalCase:

   *Eg*

   *MyStruct(){*

   	*//code*

   *}*

   

   

2. **How curly braces are placed**

   *Int main(){*

   	*//code*

   *}*

   

   

3. **Use whitespace to separate out symbols when you can.**  
   	*Int x=123; \[no\]*  
   *Mylist \= (1,2,3,4); \[no\]*  
     
   	*Int x \= 123; \[yes\]*  
   *Mylist \= (1, 2, 3, 4); \[yes\]*  
     
     
4. **Organise header files in alphabetical order.**  
   	*\#include \<art\>*  
   	*\#include \<stdio.h\>*  
     
   	*Followed by file/function imports.*  
   	*Import s“..balaldja/dalfjak/hello.txt:”*  
   

     
5. **Comments  are always placed above the code you are referring to.** 

   *short comments:*

   *//comment*

   *int x do\_this(){}*

   

   */\**

   *Multiple*

   *line*

   *Explanation*

   *comment*

   *\*/*

   	*myFunc(){}*

**Documentation rules**

1. **File description(.h, .c, .md etc )**

   Include brief description of the file’s purpose at the top of any file you create

   

   *Opening my\_file.c would read:*

   

   */\**

   *my\_file.c:*

   *calculates the sum of two numbers for the main.c file to print.*

   *It also handles blah blah blah…*

   *\*/*

   

   

2. **Concise documentation**

   Do not add too many comments that will clutter the code. Say what the function/code block does and why it's there.

   

   *Example:*

   *\\\**

   *Finds the calculates the addition of the same number with two different exponents.  Example: 3^2+ 3^5.*

   *The result is used in important\_function() as a value it needs before it can work.*

   *\*/*

   *int calculate\_exponent\_sums( number, exponent1, exponent2);{*

   	*int sum \=  exponent1 \+ exponent2;*

   	*int product \= number \*\* sum;*

   	*return product;*

   *}*

   

   

3. **Unnecessary documentation**

   Dont comment inside the code block/ function unless it’s too complex for simple documentation. 

   *Example:*

   *Do:*

   *//used as example of small function to give reader general idea them*

   *int small\_function(){*

   	*printf(“this is a small function.”);*

   	*printf(“does like 1 or 2 things”);*

   	*printf(“easy to keep track of and understand while reading the*

   *above comment”);*

   

   *return 0;*

   *}*

		*Don’ Do:*  
		*int small\_function(){*  
			*\#prints to the terminal that this is a small function*  
	*printf(“this is a small function.”);*

	*\#prints to the terminal how many things is done*  
	*printf(“does like 1 or 2 things”);*

	*\#prints to the … you get the point*  
	*printf(“easy to keep track of and understand while reading the*  
*above comment”);*  
*return 0;*  
*}*

