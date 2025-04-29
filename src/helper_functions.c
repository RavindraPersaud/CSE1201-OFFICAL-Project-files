/*
helper_functions.c:
This file stores functions and constant values that are reused throuhout multiple c files in the project.
*/


#include <stdio.h>

#include "../include/helper_functions.h"


/*
user_choice:
Retrieve the user's choice.
Checks the value scanf() returns. Since we use %d, scanf should return a value of 1 if the user entered an integer.

If the user did not enter an integer (choice != 1), it will convert the user's choice into a number.
The chosen number must be larger than any number int choice could possibly equal throughout the system.
For now, 30 is larger than any choice value needed by the program.

That chosen number is then returned, and the respective menu handles giving the error message.

Clears the input buffer to discard any invalid input.
*/
int user_choice(){ 
    int choice;
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        choice = 7;
        while (getchar() != '\n'); 
    }
    else {
        return choice;
    }
}
