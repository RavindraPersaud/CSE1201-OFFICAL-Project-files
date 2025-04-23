#include "message_system.h"


red
// Global array to store banned words
// Each word is a string of MAX_WORD_LENGTH characters
char banned_words[MAX_BANNED_WORDS][MAX_WORD_LENGTH];

// Tracks the number of banned terms that have been used
int banned_word_count = 0;

/*
 * Function: initialize_banned_words
 * ---------------------------------
 * Initializes the banned_words array with a set of predetermined banned words
 * Terms considered inappropriate or offensive.
 *
 * This function will be called at the start of the program.
 */
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
 * Function: add_banned_word
 * -------------------------
 * Adds a new word to the banned_words array.
 *
 * word: A pointer to the word (string) to be added.
 *
 * returns: 1 if the word is added successfully,
 *          0 if the banned word list is already full.
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
 * Function: is_banned_word
 * ------------------------
 * Checks if a word exists in the banned_words array.
 *
 * word: The word to be checked.
 *
 * returns: 1 if the word already is banned, 0 otherwise.
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
 * Function: redact_message
 * ------------------------
 * Redacts (censors) any banned words in the message.
 *
 * returns: A newly allocated string with redacted content.
 */
char* redact_message(char* message, const char* list) {
    if (message == NULL) {
        return NULL;
    }
    
    // Allocates memory for the censored version of the message
    char* redacted = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    if (redacted == NULL) {
        return NULL;
    }

     // Copy the original message into the redacted string
    strcpy(redacted, message);
    
    // If a custom list is provided, use it to build a new banned word list
    if (list != NULL && strlen(list) > 0) {
        banned_word_count = 0;
        char* word = strtok((char*)list, " ,;");
        while (word != NULL && banned_word_count < MAX_BANNED_WORDS) {
            add_banned_word(word);
            word = strtok(NULL, " ,;");
        }
    }
    
     /*
     * Splits the message to find and replace banned words.
     * We tokenize using common punctuation and whitespace characters.
     * Replace with asterisks
     */
    char* word = strtok(redacted, " \n\t.,;:!?()[]{}\"\'");
    while (word != NULL) {
        if (is_banned_word(word)) {
           
            int len = strlen(word);
            for (int i = 0; i < len; i++) {
                word[i] = '*';
            }
        }
        word = strtok(NULL, " \n\t.,;:!?()[]{}\"\'");
    }
    
    return redacted;
}

/*
 * Function: display_banned_words
 * ------------------------------
 * Prints all stored banned words to the screen.
 */
void display_banned_words() {
    printf("Banned words list:\n");
    for (int i = 0; i < banned_word_count; i++) {
        printf("%d. %s\n", i + 1, banned_words[i]);
    }
} 
