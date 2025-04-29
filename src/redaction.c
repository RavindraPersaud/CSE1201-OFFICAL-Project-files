/*
redact_message.c

Handles the redaction of multiple target words from a user-provided message by replacing them with asterisks.
Demonstrates a basic text processing task that matches specified target words exactly
and replaces them while maintaining other text structure.

*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_MESSAGE_LENGTH 1000
#define MAX_WORDS_TO_REDACT 50


/*
redact_message

Redacts a message by replacing every occurrence of any target word with asterisks.

Parameters:
- message: Pointer to the original message string.
- target_words: Array of words to be redacted.
- num_words: Number of words in the target_words array.

Returns:
- A newly allocated string with the target words replaced by asterisks.
- NULL if inputs are invalid or memory allocation fails.
*/
char* redact_message(char* message, const char* target_words[], int num_words) {
    
    if (message == NULL || target_words == NULL || num_words <= 0) {
        return NULL;
    }
    
    char* redacted_message = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    
    if (redacted_message == NULL) {
        return NULL;
    }
    
    strcpy(redacted_message, message);
    
    char* current_pos = redacted_message;
    
    while (*current_pos != '\0') {
        
        // Skip non-alphabetic characters
        while (*current_pos != '\0' && !isalpha((unsigned char)*current_pos)) {
            current_pos++;
        }
        
        if (*current_pos == '\0') {
            break;
        }
        
        char* word_start = current_pos;
        
        // Find end of the word
        while (*current_pos != '\0' && isalpha((unsigned char)*current_pos)) {
            current_pos++;
        }
        
        char temp = *current_pos;
        *current_pos = '\0';
        
        // Check against all target words
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_start, target_words[i]) == 0) {
                int target_length = strlen(target_words[i]);
                for (int j = 0; j < target_length; j++) {
                    word_start[j] = '*';
                }
                break;
            }
        }
        
        *current_pos = temp;
    }
    
    return redacted_message;
}




/*
main

Main function to test the redact_message function.
Prompts the user to input a message and a set of words to redact (separated by commas),
then displays the redacted message result.

*/
int main() {
    
    char message[MAX_MESSAGE_LENGTH];
    char redaction_input[MAX_MESSAGE_LENGTH];
    char target_words[MAX_WORDS_TO_REDACT][MAX_MESSAGE_LENGTH];
    const char* target_words_ptrs[MAX_WORDS_TO_REDACT];
    int num_words = 0;
    
    printf("Enter a message: ");
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("Failed to read message.\n");
        return 1;
    }
    
    message[strcspn(message, "\n")] = '\0'; // Remove newline character if present
    
    
    printf("Enter the words to redact (separated by commas): ");
    if (fgets(redaction_input, sizeof(redaction_input), stdin) == NULL) {
        printf("Failed to read redaction words.\n");
        return 1;
    }
    
    redaction_input[strcspn(redaction_input, "\n")] = '\0';
    
    
    // Parse comma-separated list into target_words array
    char* token = strtok(redaction_input, ",");
    while (token != NULL && num_words < MAX_WORDS_TO_REDACT) {
        
        // Trim leading spaces
        while (isspace((unsigned char)*token)) {
            token++;
        }
        
        // Trim trailing spaces
        char* end = token + strlen(token) - 1;
        while (end > token && isspace((unsigned char)*end)) {
            *end = '\0';
            end--;
        }
        
        if (strlen(token) > 0) {
            strncpy(target_words[num_words], token, MAX_MESSAGE_LENGTH - 1);
            target_words[num_words][MAX_MESSAGE_LENGTH - 1] = '\0';
            target_words_ptrs[num_words] = target_words[num_words];
            num_words++;
        }
        
        token = strtok(NULL, ",");
    }
    
    
    if (num_words == 0) {
        printf("No valid words entered for redaction.\n");
        return 1;
    }
    
    
    char* redacted = redact_message(message, target_words_ptrs, num_words);
    
    if (redacted != NULL) {
        printf("\nOriginal Message: %s\n", message);
        printf("Redacted Message: %s\n", redacted);
        free(redacted);
    }
    else {
        printf("Failed to redact the message.\n");
    }
    
    return 0;
}

