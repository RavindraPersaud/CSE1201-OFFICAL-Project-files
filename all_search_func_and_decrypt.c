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
    int is_encrypted;
    char title[50];
    char message[288];
} Record;

char* decrypt(char message[], char key[]);
void ask_decrypt(Record rec);


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
    char phrase[288];
    printf("Enter Phrase:");
    scanf(" %[^\n]", phrase);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening files.\n");
        return 1;
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
        printf("Message not Found");
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
void search_by_id() {
    int id;
    int found = 0;
    printf("Enter Message ID:");
    scanf("%d", &id);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
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
        printf("Message not Found");
    }

    fclose(fptr);

    return 0;
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
    char title[50];
    printf("Enter Message Title:");
    scanf(" %[^\n]", title);

    FILE *fptr = fopen("../data/message_storage.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
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
        printf("Message not Found");
    }
    

    fclose(fptr);

    return 0;
}


/*
decrypt()
-----------------------------------------
Takes encrypted message along with a key 
and decrypts the message using that key.
Prints the decrypted message.
*/



char* decrypt(char* message, char* key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int counter = 0;
    char temp;
    char mod_key[key_len + 1];
    strcpy(mod_key, key);

    int cols = (msg_len / key_len) + (msg_len % key_len != 0);

    char matrix[key_len][cols + 1];
    char new_matrix[key_len][cols + 1];
    char* full_sentence = malloc((msg_len + key_len + 1) * sizeof(char));
    full_sentence[0] = '\0';

    for (int i = 0; i < key_len; i++) {
        matrix[i][cols] = '\0';
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = message[counter];
            counter += 1;
        }
    }
    //This sorts the key into alphabetical ordere
    for (int k = 0; k < key_len; k++) {
        for (int l = k + 1; l < key_len; l++) {
            if ((int)mod_key[l] < (int)mod_key[k]) {
                temp = mod_key[l];
                mod_key[l] = mod_key[k];
                mod_key[k] = temp;
            }
        }
    }

    //creates a list to keep track of what spaces have been filled(This is used if a key as repeating letters)
    int used[key_len]; //list created
    for (int i = 0; i < key_len; i++) used[i] = 0;//fills the list with 0
    for (int p = 0; p < key_len; p++) {
        int num = (int)key[p];//set num to the ascii of the letter and key inex p
        for (int j = 0; j < key_len; j++) {
            if ((int)mod_key[j] == num && used[j] == 0) { 
                strcpy(new_matrix[p], matrix[j]);//coppies the matrix at index j into new matrix at index p
                used[j] = 1;//Marks the spot as 1 to prevent repeating characters from getting put in the same place
                break;
            }
        }
    }

    //Iterates column by column and appends chars to full sentence replacing '-' with ' '
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < key_len; j++) {
            if (new_matrix[j][i] == '-') {
                new_matrix[j][i] = ' ';
            }
            strncat(full_sentence, &new_matrix[j][i], 1);
        }
    }

    return full_sentence;
}

//Asks user if they want to decrypt message then calls the decrypt function
void ask_decrypt(Record rec) {
    int dec;
    char key[50];

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
}
