/*
standards_test.c:
Demonstrates adherence to the CSE1201 Project Standards.
Tests naming conventions, curly braces, whitespace, commenting, and file organization.
Used for validating correct coding style across the project.
Disclaimer! Used purely for demonstrative purposes, file does not 
*/


#include <stdio.h>
#include <stdlib.h>

#include "example_helper.h"
#include "storage_manager.h"


//Used to demonstrate two blank lines above and below a struct(including the comment).
typedef struct MyStruct {
    int value;
    char label[50];
} MyStruct;


//Initializes a MyStruct instance with given value and label then returns the initialized struct.

MyStruct initialize_my_struct(int init_value, const char *init_label) {
    MyStruct new_struct;

    new_struct.value = init_value;
    snprintf(new_struct.label, sizeof(new_struct.label), "%s", init_label);

    return new_struct;
}


//Prints the fields of a MyStruct instance.
void print_my_struct(MyStruct my_struct) {
    printf("Value: %d\n", my_struct.value);
    printf("Label: %s\n", my_struct.label);
}


//Demonstrates initialization and printing of a struct instance.
int main() {

    MyStruct sample = initialize_my_struct(42, "Test Label");

    print_my_struct(sample);

    if (sample.value > 0) {
        printf("Sample has a positive value.\n");
    }

    for (int i = 0; i < 3; i++) {
        printf("Loop iteration: %d\n", i);
    }

    return 0;
}

