/*
redact_message.c

Handles the redaction of multiple target words from a user-provided message by replacing them with asterisks.
Includes a simple testing main() function for demonstration.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1000
#define MAX_WORDS_TO_REDACT 50



/*
redact_message
-----------------------------------------
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

    // Create a copy of the message to avoid modifying the original
    char* redacted_message = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));

    if (redacted_message == NULL) {
        return NULL;
    }

    strcpy(redacted_message, message);

    char* current_pos = redacted_message;

    while (*current_pos != '\0') {

        // Skip non-alphabetic characters
        while (*current_pos != '\0' && !isalpha(*current_pos)) {
            current_pos++;
        }

        if (*current_pos == '\0') {
            break;
        }

        char* word_start = current_pos;

        // Find end of the word
        while (*current_pos != '\0' && isalpha(*current_pos)) {
            current_pos++;
        }

        // Temporarily end the word
        char temp = *current_pos;
        *current_pos = '\0';

        // Check against all target words
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_start, target_words[i]) == 0) {
                // Redact: replace with asterisks
                int target_length = strlen(target_words[i]);
                for (int j = 0; j < target_length; j++) {
                    word_start[j] = '*';
                }
                break; // Once redacted, no need to check other words
            }
        }

        // Restore the original character
        *current_pos = temp;
    }

    return redacted_message;

}



/*
main
-----------------------------------------
Main function to test the redact_message function.
Prompts the user to input a message and multiple words to redact, then displays the result.
*/
int main() {

    char message[MAX_MESSAGE_LENGTH];
    char target_words[MAX_WORDS_TO_REDACT][MAX_MESSAGE_LENGTH];
    const char* target_words_ptrs[MAX_WORDS_TO_REDACT];
    int num_words = 0;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character if present

    printf("Enter the number of words to redact: ");
    scanf("%d", &num_words);

    if (num_words > MAX_WORDS_TO_REDACT) {
        printf("Too many words to redact. Maximum allowed is %d.\n", MAX_WORDS_TO_REDACT);
        return 1;
    }

    // Clear newline left by scanf
    getchar();

    for (int i = 0; i < num_words; i++) {
        printf("Enter word %d to redact: ", i + 1);
        fgets(target_words[i], sizeof(target_words[i]), stdin);
        target_words[i][strcspn(target_words[i], "\n")] = '\0'; // Remove newline
        target_words_ptrs[i] = target_words[i]; // Setup array of pointers
    }

    char* redacted = redact_message(message, target_words_ptrs, num_words);

    if (redacted != NULL) {
        printf("\nOriginal Message: %s\n", message);
        printf("Redacted Message: %s\n", redacted);
        free(redacted); // Free the allocated memory
    }
    else {
        printf("Failed to redact the message.\n");
    }

    return 0;

}

