/*
This file contains functions that modify the message before storing 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Encrypt function
 * Encrypts message based on provided key by columnar transposition
 */
char* encrypt(char *message, char *key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int counter = 0;

    // Allocate memory for output string
    char* full_sentence = malloc((msg_len + key_len + 1) * sizeof(char));
    full_sentence[0] = '\0'; 

    int rows = (msg_len / key_len) + (msg_len % key_len != 0);
    char matrix[rows][key_len];
    char matrix2[key_len][rows + 1]; 

    char temp;
    char matrix2_temp[rows + 1]; 
    char mod_key[key_len + 1]; 
    strcpy(mod_key, key);

    // Fill matrix row by row, replacing spaces with '-'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            if (counter < msg_len) {
                if (message[counter] == ' ') {
                    matrix[i][j] = '-';
                } else {
                    matrix[i][j] = message[counter];
                }
            } else {
                matrix[i][j] = '-';
            }
            counter += 1;
        }
    }

    // Rearrange to column-wise matrix
    for (int n = 0; n < key_len; n++) {
        for (int o = 0; o < rows; o++) {
            matrix2[n][o] = matrix[o][n];
        }
        matrix2[n][rows] = '\0'; 
    }

    // Sort based on the key characters
    for (int k = 0; k < key_len; k++) {
        for (int l = k + 1; l < key_len; l++) {
            if ((int)mod_key[l] < (int)mod_key[k]) {
                // Swap characters in key
                temp = mod_key[l];
                mod_key[l] = mod_key[k];
                mod_key[k] = temp;

                // Swap corresponding columns
                strcpy(matrix2_temp, matrix2[l]);
                strcpy(matrix2[l], matrix2[k]);
                strcpy(matrix2[k], matrix2_temp);
            }
        }
    }

    printf("\nEncrypted Message: ");

    for (int k = 0; k < key_len; k++) {
        strcat(full_sentence, matrix2[k]);
    }

    printf("%s\n", full_sentence); // Show the encrypted message
    return full_sentence;
}


/*
decrypt()
-----------------------------------------
Takes encrypted message along with a key 
and decrypts the message using that key.
Prints the decrypted message.
*/
char* decrypt(char* message, char* key) {
    //gets message and key len along with a counter to keep track of message position
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int counter = 0;
    char temp;
    char mod_key[key_len + 1];
    strcpy(mod_key, key);

    int cols = (msg_len / key_len) + (msg_len % key_len != 0);
    //creates matrices for messages
    char matrix[key_len][cols + 1];
    char new_matrix[key_len][cols + 1];

    //dyanmically sets aside memory for the full sentence
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
    int used[key_len];
    for (int i = 0; i < key_len; i++) used[i] = 0;//fills the list with 0
    for (int p = 0; p < key_len; p++) {
        int num = (int)key[p];//set num to the ascii of the letter and key inex p
        for (int j = 0; j < key_len; j++) {
            if ((int)mod_key[j] == num && used[j] == 0) { 
                //coppies the matrix at index j into new matrix at index p
                strcpy(new_matrix[p], matrix[j]);
                //Marks the spot as 1 to prevent repeating characters from getting put in the same place
                used[j] = 1;
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

