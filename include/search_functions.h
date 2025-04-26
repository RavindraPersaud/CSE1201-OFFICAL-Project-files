#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for each record
typedef struct {
    int ID;
    char title[50];
    char message[288];
} Record;

/*
Search by Phrase function:
searches through all the messages in the structs to see
if any containes the given word/phrase
*/

int search_by_phrase(char phrase[]){
    //opens file in "read binary" mode
    FILE *fptr = fopen("records.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    //placeholder rect 
    Record rec;

    //while loop that uses the "strstr" function to check if phrase is in the message
    while (fread(&rec, sizeof(Record), 1, fptr)){
            if (strstr(rec.message, phrase)){
                printf("ID: %d\n", rec.ID);
                printf("Title: %s\n", rec.title);
                printf("Message: %s\n\n", rec.message);
            }
        }
    
    fclose(fptr);
    
    return 0;
}

#endif
