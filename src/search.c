/*
search_functions.c
-----------------------------------------
Functions to search message records stored in 'records.dat'.
Allows search by:
- Phrase (substring in message)
- Title (exact match)
- ID (exact match)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing a record
typedef struct {
    int ID;
    char title[50];
    char message[288];
} Record;


/*
search_by_phrase
---------------------------
Searches through all the messages in the structs to see if any messages contains the given word/phrase.
opens file in "read binary" mode
Prints all matching records.
Returns 0 on success, 1 on error.
*/

int search_by_phrase(char phrase[]){
    //
    FILE *fptr = fopen("records.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    Record rec;

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


/*
search_by_id()
-----------------------------------------
Searches for a record by its unique ID.
Prints the matching record.
Returns 0 on success, 1 on error.
 */
int search_by_id(int id){
    FILE *fptr = fopen("records.dat", "rb");

    if (fptr == NULL || temp == NULL){
        printf("Error opening files.\n");
        return 1;
    }

    Record rec;

    while (fread(&rec, sizeof(Record), 1, fptr)){
        if (rec.ID == id) {
            printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n\n", rec.message);
        }
    }

    fclose(fptr);
    fclose(temp);
    
    return 0;
}


/*
search_by_title()
-----------------------------------------
Searches for a record by its title (case-sensitive).
Prints the matching record.
Returns 0 on success, 1 on error.
 */
int search_by_title(char title[]){
    FILE *fptr = fopen("records.dat", "rb");

    if (fptr == NULL || temp == NULL){
        printf("Error opening files.\n");
        return 1;
    }
    Record rec;

    while (fread(&rec, sizeof(Record), 1, fptr)){
        if (strcmp(rec.title,title) == 0) {
			printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n\n", rec.message);
        }
    }


    fclose(fptr);
    fclose(temp);
    
    return 0;


