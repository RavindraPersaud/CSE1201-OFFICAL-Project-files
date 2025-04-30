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
#include "../include/helper_functions.h"


// Struct representing a record

char* decrypt(char message[], char key[]);

char* ask_decrypt(Record rec);


/*
search_by_phrase
---------------------------
Searches through all the messages in the structs to see if any messages contains the given word/phrase.
opens file in "read binary" mode
Prints all matching records.
Returns 0 on success, 1 on error.
*/
void search_by_phrase() {
    int found = 0;
    char phrase[MAX_MESSAGE_SIZE];
    printf("Enter Phrase:");
    scanf(" %[^\n]", phrase);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening files.\n");
        return;
    }

    Record rec;

    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (strstr(rec.message, phrase)) {
            printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n", rec.message);
            printf("Encrypted: %d\n\n", rec.is_encrypted);

            ask_decrypt(rec);
            found = 1;
        }
    }
    if (!found){
        printf("Message not Found\n");
    }
    
    fclose(fptr);

    return;
}


/*
search_by_id()
-----------------------------------------
Searches for a record by its unique ID.
Prints the matching record.
Returns 0 on success, 1 on error.
*/
void search_by_id() {
    int id;
    int found = 0;
    printf("Enter Message ID:");
    scanf("%d", &id);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;

    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (rec.ID == id) {
            printf("ID: %d\n", rec.ID);
            printf("Title: %s\n", rec.title);
            printf("Message: %s\n", rec.message);
            printf("Encrypted: %d\n\n", rec.is_encrypted);

            ask_decrypt(rec);
            found = 1;
        }
    }
    if (!found){
        printf("Message not Found\n");
    }

    fclose(fptr);

    return;
}


/*
search_by_title()
-----------------------------------------
Searches for a record by its title (case-sensitive).
Prints the matching record.
Returns 0 on success, 1 on error.
*/
void search_by_title() {
    int found = 0;
    char title[MAX_TITLE_SIZE];
    printf("Enter Message Title:");
    scanf(" %[^\n]", title);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;

    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (strcmp(rec.title, title) == 0) {
            printf("\nID: %d\n", rec.ID);
            printf("Message: %s\n", rec.message);
            printf("Encrypted: %d\n\n", rec.is_encrypted);

            ask_decrypt(rec);
            found = 1;
        }
    }
    if (!found){
        printf("Message not Found\n");
    }
    

    fclose(fptr);

    return;
}


//Asks user if they want to decrypt message then calls the decrypt function
char* ask_decrypt(Record rec) {
    int dec;
    char key[MAX_KEY_SIZE];
    char *decrypted;

    printf("Do you want to decrypt message?\n1.Yes\n2.No\nEnter Choice: ");
    scanf("%d", &dec);

    if (dec == 1) {
        if (rec.is_encrypted) {
            printf("Enter Decryption Key: ");
            scanf(" %[^\n]", key);
            char *decrypted = decrypt(rec.message, key);
            printf("Decrypted Message:\n%s\n", decrypted);
            free(decrypted);
        } else {
            printf("This message is not encrypted.\n");
        }
    }
    return decrypted;
}


