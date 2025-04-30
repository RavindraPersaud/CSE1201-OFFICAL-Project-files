#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/helper_functions.h"
// Counts how many words are separated by commas
int count(char *message) {
    int count = 1;  
    while (*message) {
        if (*message == ',') {
            count++;
        }
        message++;
    }
    return count;
}

// Splits the message by commas
char **list_maker(char *message, int *redacted_word_count) {
    int length = count(message);
    *redacted_word_count = length;

    //creating list to hold censored words
    char **new_list = malloc(length * sizeof(char*));
    int index = 0;
    //breaks the message up into tokens with "," as the separater
    char *token = strtok(message, ",");

    while (token != NULL && index < length) {
        // Trim leading/trailing whitespace
        while (isspace(*token)) token++;
        char *end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) *end-- = '\0';

        //allocates memory for length of word + 1 for the EOL char
        new_list[index] = malloc(strlen(token) + 1);
        //copies the word(token) into that memory allocated
        strcpy(new_list[index], token);

        //increases the index
        index++;

        //moves onto the next word
        token = strtok(NULL, ",");
    }

    return new_list;
}

void redact(char *message) {
    int len = strlen(message);
    char input[len]; 
    printf("Enter comma separated list of words you want to censor:");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';


    int redacted_word_count;
    char **redacted = list_maker(input, &redacted_word_count);
    printf("Original: %s\n", message);

    char redacted_message[MAX_MESSAGE_SIZE];
    int i = 0;
    int j = 0;
    //runs until it hits a EOL
    while (message[i]) {
        //skips over spaces unless its the start of a word
        if (isalpha(message[i]) || message[i] == '-' || message[i] == '\'') {
            //stores word
            char word[100];
            int w = 0;

            //while loop that loops until a space(gets a word)
            while (isalnum(message[i]) || message[i] == '-' || message[i] == '\'') {
                word[w++] = message[i++];
            }
            //adds end of sting char to word
            word[w] = '\0';

            //redact flag to set if word should be redacted or not
            int redact_flag = 0;

            //checks if word is in redacted word
            for (int k = 0; k < redacted_word_count; k++) {
                if (strcasecmp(word, redacted[k]) == 0) {
                    //if word in redacted word list redact flag is set to 1
                    redact_flag = 1;
                    break;
                }
            }

            //loops through word
            for (int m = 0; m < w; m++) {
                //if redact flag is 1 it appends an esterisk
                if(redact_flag){
                    redacted_message[j++] = '*';
                }
                //if not it appends the char
                else{
                    redacted_message[j++] = word[m];
                }
                
            }
        } else {
            redacted_message[j++] = message[i++];
        }
    }

    redacted_message[j] = '\0';
    //copies redacted message into message
    strcpy(message, redacted_message);

    
    printf("Redacted: %s\n", message);

    for (int i = 0; i < redacted_word_count; i++) {
        free(redacted[i]);
    }
    free(redacted);
}

