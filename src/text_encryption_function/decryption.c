/*
decryption.c:
Decrypts messages encrypted by encryption.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Columnar Decryption function
Decrypts messages ecnrypted by the columnar transposition cipher
*/
char* decrypt(char message[], char key[]){
    //Reuses most variables from encrpyt function
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
    
    //Getting back matrix from encrypted text
    for (int i = 0; i < key_len; i++){
        matrix[i][cols] = '\0';
        for(int j = 0 ; j < cols; j++){
            matrix[i][j] = message[counter];
            counter += 1;
        }
    }

    //sorting key into alphabetical order
    for(int k = 0; k < key_len ; k++){
        for (int l = k+1; l < key_len ; l++){
            if((int)mod_key[l] < (int)mod_key[k]){
                temp = mod_key[l];
                mod_key[l] = mod_key[k];
                mod_key[k] = temp;
            
            }
        }
    }

    /*
    Iterated through the ASCII values of original key, finds its position in the sorted key 
    then uses the indexes of those values to get the matrix of the original key before sorting.
    */
    for(int p = 0; p < key_len; p++){
        int num = (int)key[p];
        for(int j = 0; j < key_len; j++){
            if ((int)mod_key[j] == num){
                strcpy(new_matrix[p],matrix[j]);
            }
        }
    }

    //Iterates column by column and appends chars to full sentence replacing '-' with ' '
    printf("Decrypted Message:");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < key_len; j++) {
            if (new_matrix[j][i] == '-'){
                new_matrix[j][i] = ' ';
            }
            strncat(full_sentence, &new_matrix[j][i], 1);
        }
    }

    return full_sentence;

}


