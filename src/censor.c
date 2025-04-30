#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/helper_functions.h"

void end_of_menu();


/*
count:
Counts the number of comma-separated values in a message string.
Used to determine how many words will be redacted.
*/
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


/*
list_maker:
Takes a comma-separated string, trims whitespace from each token,
and returns a dynamically allocated list of strings.

Parameters:
- message: input string (will be modified).
- redacted_word_count: pointer to store the number of words parsed.

Returns:
- char**: an array of redacted words.
*/
char **list_maker(char *message, int *redacted_word_count) {
    int length = count(message);
    *redacted_word_count = length;

    char **new_list = malloc(length * sizeof(char *));
    int index = 0;

    // Break the input into tokens separated by commas
    char *token = strtok(message, ",");

    while (token != NULL && index < length) {
        // Trim leading whitespace
        while (isspace(*token)) token++;

        // Trim trailing whitespace
        char *end = token + strlen(token) - 1;
        while (end > token && isspace(*end)) {
            *end-- = '\0';
        }

        // Allocate memory and copy token
        new_list[index] = malloc(strlen(token) + 1);
        strcpy(new_list[index], token);

        index++;
        token = strtok(NULL, ",");
    }

    return new_list;
}


/*
redact:
Replaces any word in the message that appears in the user-provided
redacted list with asterisks (*).

Parameters:
- message: the original message to censor (modified in place).
*/
void redact(char *message) {
    char input[MAX_MESSAGE_SIZE];

    printf("Enter comma separated list of words you want to censor: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int redacted_word_count;
    char **redacted = list_maker(input, &redacted_word_count);

    printf("Original: %s\n", message);

    char redacted_message[MAX_MESSAGE_SIZE];
    int i = 0;
    int j = 0;

    while (message[i]) {
        //checks if message[i] is not a space
        if (isalpha(message[i]) || message[i] == '-' || message[i] == '\'') {
            // Extract a word
            char word[100];
            int w = 0;
            //creates word
            while (isalnum(message[i]) || message[i] == '-' || message[i] == '\'') {
                word[w++] = message[i++];
            }

            word[w] = '\0';

            // Determine if the word needs to be redacted
            int redact_flag = 0;

            for (int k = 0; k < redacted_word_count; k++) {
                if (strcasecmp(word, redacted[k]) == 0) {
                    redact_flag = 1;
                    break;
                }
            }

            // Append either asterisks or the original word
            for (int m = 0; m < w; m++) {
                if (redact_flag) {
                    redacted_message[j++] = '*';
                } else {
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

    end_of_menu();

    // Free allocated memory
    for (int i = 0; i < redacted_word_count; i++) {
        free(redacted[i]);
    }

    free(redacted);
}
