/*
load_messages.c
----------------------------
Displays a list of messages stored in the .dat file, showing a preview
of each message for user reference.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/helper_functions.h"

/*
Load Messages Function
============================================
iterates throughout the dat file and prints the data stored within the 
structs.
*/
void load_messages(){
    char slice[26];
    FILE *fptr;

    //Opens file in "read binary mode"
    fptr = fopen("../data/message_storage.dat", "rb");   

    //placeholder record
    Record rec;
    //iterates through all the structs in the dat file and prints the ID,title and message
    while (fread(&rec, sizeof(Record), 1, fptr)){
        printf("ID: %d\n", rec.ID);
        printf("Title: %s\n", rec.title);
        //clears previous data from slice string
        memset(slice, 0, sizeof(slice));
        //copies up to the 21st index of rec.message into slice 
        strncpy(slice,rec.message,21);
        //adds EOL char to end of string
        slice[21] = '\0';
        //adds a "..." to the end of the slice for it to look like a preview
        strcat(slice,"..."); 
        printf("Message: %s\n", slice);
        printf("Encrypted:%d\n\n", rec.is_encrypted);
    }
    fclose(fptr);  
    return ;
}

