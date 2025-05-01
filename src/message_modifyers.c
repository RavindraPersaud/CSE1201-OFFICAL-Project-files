/*
cipher_functions.c:
This file implements encryption and decryption of messages using columnar transposition cipher
based on a provided key. Spaces are replaced with '-' during encryption to maintain structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
encrypt:
Encrypts a message using columnar transposition with the given key.

Parameters:
- message: the plaintext message to encrypt
- key: the string key to determine column order

Returns:
- A pointer to the encrypted message string (dynamically allocated)
*/
char* encrypt(char *message, char *key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int counter = 0;

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
                matrix[i][j] = (message[counter] == ' ') ? '-' : message[counter];
            } else {
                matrix[i][j] = '-';
            }
            counter++;
        }
    }

    // Rearrange to column-wise matrix
    for (int n = 0; n < key_len; n++) {
        for (int o = 0; o < rows; o++) {
            matrix2[n][o] = matrix[o][n];
        }
        matrix2[n][rows] = '\0'; 
    }

    // Sort columns based on alphabetical order of the key
    for (int k = 0; k < key_len; k++) {
        for (int l = k + 1; l < key_len; l++) {
            if ((int)mod_key[l] < (int)mod_key[k]) {
                // Swap key characters
                temp = mod_key[l];
                mod_key[l] = mod_key[k];
                mod_key[k] = temp;

                // Swap corresponding columns in matrix2
                strcpy(matrix2_temp, matrix2[l]);
                strcpy(matrix2[l], matrix2[k]);
                strcpy(matrix2[k], matrix2_temp);
            }
        }
