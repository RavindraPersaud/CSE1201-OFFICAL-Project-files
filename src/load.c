//a C header file that provides functions for input and output operations, such as reading from and writing to files and the console.
#include <stdio.h>
//a C header file that provides functions for memory allocation, process control, conversions, and other utility operations.
#include <stdlib.h>
//a C header file that provides functions for manipulating C-style strings and memory blocks.
#include <string.h>

void load_messages();
//Struct for each record
typedef struct {
    int ID;
    int is_encrypted;
    char title[50];
    char message[288];
} Record;

/*
*Load Messages Function
iterates throughout the dat file and prints the data stored within the 
structs.
*/
void load_messages(){
    FILE *fptr;

    //Opens file in "read binary mode"
    fptr = fopen("../data/message_storage.dat", "rb");   

    //placeholder record
    Record rec;
    //iterates through all the structs in the dat file and prints the ID,title and message
    while (fread(&rec, sizeof(Record), 1, fptr)){
        printf("ID: %d\n", rec.ID);
        printf("Title: %s\n", rec.title);
        printf("Message: %s\n", rec.message);
        printf("Encrypted:%d\n\n", rec.is_encrypted);
    }
    fclose(fptr);  
    return ;
}
