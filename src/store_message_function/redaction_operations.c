/*
redactor.c
-----------------------------------------
The messaging system's redaction features are managed by this file.
It offers features to show the list of prohibited terms, create custom restricted words,
redact input messages, and initialize blacklisted words.
The main objective is to make sure that any offensive or 
reported terms are removed before a message is shown or saved.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_BANNED_WORDS 100
#define MAX_MESSAGE_LENGTH 1000

// Global array to store banned words
char banned_words[MAX_BANNED_WORDS][MAX_WORD_LENGTH];
int banned_word_count = 0;

/*
 * initialize_banned_words()
 * -----------------------------------------
 * Adds a default list of banned words to the global array.
 */

//Function to initialize the banned words list
void initialize_banned_words() {
    strcpy(banned_words[banned_word_count++], "bad");
    strcpy(banned_words[banned_word_count++], "ugly");
    strcpy(banned_words[banned_word_count++], "stupid");
    strcpy(banned_words[banned_word_count++], "dumb");
    strcpy(banned_words[banned_word_count++], "idiot");
    strcpy(banned_words[banned_word_count++], "hate");
    strcpy(banned_words[banned_word_count++], "terrible");
    strcpy(banned_words[banned_word_count++], "awful");
    strcpy(banned_words[banned_word_count++], "horrible");
    strcpy(banned_words[banned_word_count++], "worst");
}

/* 
add_banned_word()
-----------------------------
Function to add a new banned word
Returns 1 on success, 0 if the list is full.
*/
int add_banned_word(const char* word) {
    if (banned_word_count >= MAX_BANNED_WORDS) {
        return 0;
    }
    
    strncpy(banned_words[banned_word_count], word, MAX_WORD_LENGTH - 1);
    banned_words[banned_word_count][MAX_WORD_LENGTH - 1] = '\0';
    banned_word_count++;
    return 1;
}

/*
is_banned_word()
-----------------------------------------
Function to check if a word is in the banned list
Returns 1 if it is, 0 otherwise.
*/
int is_banned_word(const char* word) {
    for (int i = 0; i < banned_word_count; i++) {
        if (strcmp(word, banned_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/*
redact_message()
-----------------------------------------
Function to redact a message by replacing banned words with asterisks
Accepts an optional list of banned words (comma/space/semicolon separated).
If a custom list is provided, use it instead of the global banned words
Returns a pointer to the redacted message.
*/
char* redact_message(char* message, const char* list) {
    if (message == NULL) {
        return NULL;
    }
    
    // Create a copy of the message to avoid modifying the original
    char* redacted_message = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    if (redacted_message == NULL) {
        return NULL;
    }
    
    strcpy(redacted_message, message);
    
    if (list != NULL && strlen(list) > 0) {
       
        banned_word_count = 0;
        
        
        char* word = strtok((char*)list, " ,;");
        while (word != NULL && banned_word_count < MAX_BANNED_WORDS) {
            add_banned_word(word);
            word = strtok(NULL, " ,;");
        }
    }
    
    // Process each word in the message
    char* word_start = redacted_message;
    char* word_end;
    char* current_pos = redacted_message;
    
    while (*current_pos != '\0') {
        // Skip non-alphabetic characters
        while (*current_pos != '\0' && !isalpha(*current_pos)) {
            current_pos++;
        }
        
        if (*current_pos == '\0') {
            break;
        }
        
        // Mark the start of a word
        word_start = current_pos;
        
        // Find the end of the word
        while (*current_pos != '\0' && isalpha(*current_pos)) {
            current_pos++;
        }
        
        // Temporarily terminate the word for comparison
        char temp = *current_pos;
        *current_pos = '\0';
        
        // Check if the word is banned
        if (is_banned_word(word_start)) {
            // Replace the word with asterisks
            int word_length = strlen(word_start);
            for (int i = 0; i < word_length; i++) {
                word_start[i] = '*';
            }
        }
        
        // Restore the original character
        *current_pos = temp;
    }
    
    return redacted_message;
}

/*
display_banned_words()
-----------------------------------------
Function to display all banned words
Prints the current list of banned words to the screen.
 */
void display_banned_words() {
    printf("Banned words list:\n");
    for (int i = 0; i < banned_word_count; i++) {
        printf("%d. %s\n", i + 1, banned_words[i]);
    }
}

/*
test_redaction()
-----------------------------------------
Test function for redaction
Initialize banned words and test the message
 */
void test_redaction() {
   
    initialize_banned_words();
    
    // Test messages
    const char* test_messages[] = {
        "This is a bad message with some ugly words.",
        "I hate this stupid program, it's the worst thing ever!",
        "This message has no banned words.",
        "The weather is terrible and awful today."
    };
    
    printf("Testing redaction with default banned words list:\n\n");
    
    for (int i = 0; i < 4; i++) {
        printf("Original: %s\n", test_messages[i]);
        char* redacted = redact_message((char*)test_messages[i], NULL);
        printf("Redacted: %s\n\n", redacted);
        free(redacted);
    }
    
    // Test with custom banned words list
    const char* custom_list = "weather,program,message";
    printf("Testing redaction with custom banned words list: %s\n\n", custom_list);
    
    for (int i = 0; i < 4; i++) {
        printf("Original: %s\n", test_messages[i]);
        char* redacted = redact_message((char*)test_messages[i], custom_list);
        printf("Redacted: %s\n\n", redacted);
        free(redacted);
    }
}

// Main function for testing
/*
int main() {
    printf("Testing redaction functionality...\n\n");
    test_redaction();
    printf("Redaction test complete.\n");
    return 0;
}
*/ 
