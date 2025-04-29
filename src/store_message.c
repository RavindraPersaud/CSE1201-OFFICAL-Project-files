/*
store_message.c

Allows users to create message records containing an ID, title, and message.
Each record is stored by appending it to the 'records.dat' binary file.
Supports adding multiple records in a single session.

*/

// Input/output operations (file handling, console printing)
#include <stdio.h>  
// General utilities (memory allocation, process control)  
#include <stdlib.h>
// String manipulation functions   
#include <string.h>   


/*
Record

Defines the structure used to store individual messages in the records.dat file.

Fields:
- ID: Unique identifier for the record.
- title: Title of the message (max 49 characters + null terminator).
- message: Content of the message (max 287 characters + null terminator).

*/
typedef struct {
    int ID;
    char title[50];
    char message[288];
} Record;


/*
store_message

Prompts the user to enter an ID, title, and message.
Appends the entered record to the 'records.dat' binary file.

Returns:
- None.

*/
void store_message() {
    
    FILE* fptr;
    int run = 1;
    
    while (run == 1) {
        
        Record rec;
        
        printf("Enter ID: ");
        scanf("%d", &rec.ID);
        
        printf("Enter Title: ");
        scanf(" %[^\n]", rec.title);
        
        printf("Enter Message: ");
        scanf(" %[^\n]", rec.message);
        
        fptr = fopen("records.dat", "ab");  // Open file in append-binary mode
        
        if (fptr == NULL) {
            printf("Error: Unable to open file 'records.dat'.\n");
            return;
        }
        
        fwrite(&rec, sizeof(Record), 1, fptr);  // Write the record to the file
        fclose(fptr);
        
        printf("Type 0 to exit, or 1 to add another record: ");
        scanf("%d", &run);
        
        while (getchar() != '\n');  // Clear input buffer
    }
    
    return;
}
