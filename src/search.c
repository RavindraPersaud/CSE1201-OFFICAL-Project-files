/*
search_functions.c
--------------------------------------------------
Functions to search message records stored in 'message_storage.dat'.
Allows search by:
- Phrase (substring in message)
- Title (exact match)
- ID (exact match)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/helper_functions.h"

// External function declarations
char* decrypt(char message[], char key[]);
char* ask_decrypt(Record rec);


/*
search_by_phrase
--------------------------------------------------
Searches messages for a given word/phrase (substring match).
Prints all matching records and prompts to decrypt if encrypted.
*/
void search_by_phrase() {
    int found = 0;
    char phrase[MAX_MESSAGE_SIZE];

    printf("Enter Phrase: ");
    getchar();
    scanf(" %[^\n]", phrase);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;
    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (strstr(rec.message, phrase)) {
            printf("ID: %d\nTitle: %s\nMessage: %s\nEncrypted: %d\n\n",
                   rec.ID, rec.title, rec.message, rec.is_encrypted);

            if (rec.is_encrypted == 1) {
                ask_decrypt(rec);
            }

            found = 1;
        }
    }

    if (!found) {
        printf("Message not found.\n");
    }

    fclose(fptr);
}


/*
search_by_id
--------------------------------------------------
Searches for a record by its unique ID.
Prints the matching record and prompts to decrypt if encrypted.
*/
void search_by_id() {
    int id, found = 0;

    printf("Enter Message ID: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    FILE *fptr = fopen("../data/message_storage.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;
    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (rec.ID == id) {
            printf("ID: %d\nTitle: %s\nMessage: %s\nEncrypted: %d\n\n",
                   rec.ID, rec.title, rec.message, rec.is_encrypted);

            if (rec.is_encrypted == 1) {
                ask_decrypt(rec);
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Message not found.\n");
    }

    fclose(fptr);
}


/*
search_by_title
--------------------------------------------------
Searches for a message by its title (case-sensitive).
Prints the matching record and prompts to decrypt if encrypted.
*/
void search_by_title() {
    int found = 0;
    char title[MAX_TITLE_SIZE];

    printf("Enter Message Title: ");
    scanf(" %[^\n]", title);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Record rec;
    while (fread(&rec, sizeof(Record), 1, fptr)) {
        if (strcmp(rec.title, title) == 0) {
            printf("ID: %d\nTitle: %s\nMessage: %s\nEncrypted: %d\n\n",
                   rec.ID, rec.title, rec.message, rec.is_encrypted);

            if (rec.is_encrypted == 1) {
                ask_decrypt(rec);
            }

            found = 1;
        }
    }

    if (!found) {
        printf("Message not found.\n");
    }

    fclose(fptr);
}


/*
ask_decrypt
--------------------------------------------------
Asks user if they want to decrypt an encrypted message.
Prompts for a key and prints decrypted message.
Returns NULL always (no decrypted string is passed back).
*/
char* ask_decrypt(Record rec) {
    int choice;
    char key[MAX_KEY_SIZE];
    char *decrypted = NULL;

    printf("Do you want to decrypt message?\n1. Yes\n2. No\nEnter Choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n');

    if (choice == 1 && rec.is_encrypted) {
        printf("Enter Decryption Key: ");
        scanf(" %[^\n]", key);

        decrypted = decrypt(rec.message, key);
        printf("Decrypted Message:\n%s\n", decrypted);
        free(decrypted);
    }

    return NULL;
}
