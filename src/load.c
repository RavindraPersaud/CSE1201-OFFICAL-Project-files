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
Function load_messages
------------------------
Opens file in "read binary mode" and displays each message record.
Iterates through all the structs in the dat file and, it prints:
The ID
The Title
A preview of the message (first 21 characters followed by "...") adds EOL char to end of string
Whether the message is encrypted 

*/
void load_messages(){
    char slice[26];
    FILE *fptr;

    
    fptr = fopen("../data/message_storage.dat", "rb");   

    //placeholder record
    Record rec;
    
    while (fread(&rec, sizeof(Record), 1, fptr)){
        printf("ID: %d\n", rec.ID);
        printf("Title: %s\n", rec.title);
        
        memset(slice, 0, sizeof(slice));
        
        strncpy(slice,rec.message,21);
    
        slice[21] = '\0';
        strcat(slice,"..."); 
        printf("Message: %s\n", slice);
        printf("Encrypted:%d\n\n", rec.is_encrypted);
    }
    fclose(fptr);  
    return ;
}

