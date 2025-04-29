int main() {

    char message[MAX_MESSAGE_LENGTH];
    char redaction_input[MAX_MESSAGE_LENGTH];
    char target_words[MAX_WORDS_TO_REDACT][MAX_MESSAGE_LENGTH];
    const char* target_words_ptrs[MAX_WORDS_TO_REDACT];
    int num_words = 0;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    printf("Enter the words to redact (separated by commas): ");
    fgets(redaction_input, sizeof(redaction_input), stdin);
    redaction_input[strcspn(redaction_input, "\n")] = '\0'; // Remove newline

    // Tokenize input on commas
    char* token = strtok(redaction_input, ",");
    while (token != NULL && num_words < MAX_WORDS_TO_REDACT) {
        // Trim leading spaces
        while (isspace((unsigned char)*token)) token++;

        strncpy(target_words[num_words], token, MAX_MESSAGE_LENGTH);
        target_words[num_words][MAX_MESSAGE_LENGTH - 1] = '\0'; // Ensure null-termination
        target_words_ptrs[num_words] = target_words[num_words];
        num_words++;

        token = strtok(NULL, ",");
    }

    char* redacted = redact_message(message, target_words_ptrs, num_words);

    if (redacted != NULL) {
        printf("\nOriginal Message: %s\n", message);
        printf("Redacted Message: %s\n", redacted);
        free(redacted); // Free the allocated memory
    } else {
        printf("Failed to redact the message.\n");
    }

    return 0;
}
