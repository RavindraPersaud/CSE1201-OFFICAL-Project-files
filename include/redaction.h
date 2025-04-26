// Function to redact a message by replacing a specific word with asterisks
char* redact_message(char* message, const char* target_word) {
    if (message == NULL || target_word == NULL) {
        return NULL;
    }

    // Create a copy of the message to avoid modifying the original
    char* redacted_message = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    if (redacted_message == NULL) {
        return NULL;
    }

    strcpy(redacted_message, message);

    char* current_pos = redacted_message;
    int target_length = strlen(target_word);

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

        // Compare with the target word
        if (strcmp(word_start, target_word) == 0) {
            // Redact: replace with asterisks
            for (int i = 0; i < target_length; i++) {
                word_start[i] = '*';
            }
        }

        // Restore the original character
        *current_pos = temp;
    }

    return redacted_message;
}
