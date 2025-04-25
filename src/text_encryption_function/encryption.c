#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Columnar Transpositon Cipher
method of encryption where the message is written out in rows under a keyword, 
then the columns are rearranged in the order of the letters in the keyword (usually alphabetically). 
The ciphertext is then read column by column.
*/

// Encrytps the message given by the user.
char* encrypt(char message[], char key[]){
    //Getting message and key length for array iteration.
    int msg_len = strlen(message);
    int key_len = strlen(key);

    //Counter to keep track of place in plaintext(message).
    int counter = 0;

    //variable for return value (uses malloc because local arrays get detsroyed after function execution).
    char* full_sentence = malloc((msg_len + key_len + 1) * sizeof(char));
    full_sentence[0] = '\0'; 

    //Calculating rows based on message length and remainder.
    int rows = (msg_len / key_len) + (msg_len % key_len != 0);

    char matrix[rows][key_len];
    char matrix2[key_len][rows + 1];

    //vars used for sorting and swapping.
    char temp;
    char matrix2_temp[rows + 1];
    
    //copy of key as editing key in place causes errors.
    char mod_key[key_len + 1]; 
    strcpy(mod_key, key);
    
    //Constructing matrixs with dimensions rows and key_len replacing spaces with '-'.
    for(int i = 0; i<rows; i++){
        for(int j = 0; j < key_len; j++){
            if ((counter) < msg_len){
                if (message[counter] == ' ') {
                    matrix[i][j] = '-';
                }else{
                     matrix[i][j] = message[counter];
                }
            }
            else{
                matrix[i][j] = '-';
            }
            counter += 1;
        }
    }

    //rearranges matrix so that each index contains a column of values from the original matrix.
    for (int n = 0; n  < key_len; n ++){
        matrix2[n][rows] = '\0';
        for (int o = 0; o < rows; o ++){
            matrix2[n][o] = matrix[o][n];
        }
    }

    //SORTING.
    for(int k = 0; k < key_len ; k++){
        //Uses selection sorting to sort based on the ASCII value of each char in key.
        for (int l = k+1; l < key_len ; l++){
            if((int)mod_key[l] < (int)mod_key[k]){
                temp = mod_key[l];
                mod_key[l] = mod_key[k];
                mod_key[k] = temp;
                //sorts matrix as key is being sorted.
                strcpy(matrix2_temp, matrix2[l]);
                strcpy(matrix2[l],matrix2[k]);
                strcpy(matrix2[k], matrix2_temp);

            }
        }
    }
    printf("\nEncrpyted Message:");

    for (int k = 0; k < key_len; k++) {
        strcat(full_sentence, matrix2[k]);
        
    }

    return full_sentence;
}

