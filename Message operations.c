#include "message_system.h"

// Global array to store banned words
char banned_words[MAX_BANNED_WORDS][MAX_WORD_LENGTH];
int banned_word_count = 0;

// Function to initialize the banned words list
void initialize_banned_words() {
    // Add some default banned words
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

// Function to add a new banned word
int add_banned_word(const char* word) {
    if (banned_word_count >= MAX_BANNED_WORDS) {
        return 0; // List is full
    }
    
    strncpy(banned_words[banned_word_count], word, MAX_WORD_LENGTH - 1);
    banned_words[banned_word_count][MAX_WORD_LENGTH - 1] = '\0';
    banned_word_count++;
    return 1;
}

// Function to check if a word is in the banned list
int is_banned_word(const char* word) {
    for (int i = 0; i < banned_word_count; i++) {
        if (strcmp(word, banned_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Simplified function to redact a message
char* redact_message(char* message, const char* list) {
    if (message == NULL) {
        return NULL;
    }
    
    // Create a copy of the message
    char* redacted = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    if (redacted == NULL) {
        return NULL;
    }
    
    strcpy(redacted, message);
    
    // Use custom list if provided
    if (list != NULL && strlen(list) > 0) {
        banned_word_count = 0;
        char* word = strtok((char*)list, " ,;");
        while (word != NULL && banned_word_count < MAX_BANNED_WORDS) {
            add_banned_word(word);
            word = strtok(NULL, " ,;");
        }
    }
    
    // Simple word-by-word redaction
    char* word = strtok(redacted, " \n\t.,;:!?()[]{}\"\'");
    while (word != NULL) {
        if (is_banned_word(word)) {
            // Replace with asterisks
            int len = strlen(word);
            for (int i = 0; i < len; i++) {
                word[i] = '*';
            }
        }
        word = strtok(NULL, " \n\t.,;:!?()[]{}\"\'");
    }
    
    return redacted;
}

// Function to display all banned words
void display_banned_words() {
    printf("Banned words list:\n");
    for (int i = 0; i < banned_word_count; i++) {
        printf("%d. %s\n", i + 1, banned_words[i]);
    }
} 
