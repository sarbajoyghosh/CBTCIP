#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 100

// Function to check if a character is a word delimiter
int isDelimiter(char ch) {
    return isspace(ch) || ch == '\0';
}

// Function to count words, lines, and characters in a file
void countFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    int characters = 0, words = 0, lines = 0;
    char ch;
    char prevCh = '\0';

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        // Check for new lines
        if (ch == '\n') {
            lines++;
        }

        // Check for word boundaries
        if ( isDelimiter(ch) && !isDelimiter(prevCh)) {
            words++;
        }

        prevCh = ch;
    }

    // If file is not empty and last character is not a delimiter, count the last word
    if (!isDelimiter(prevCh)) {
        words++;
    }

    fclose(file);

    printf("File %s contains:\n", filename);
    printf("%d characters\n", characters);
    printf("%d words\n", words);
    printf("%d lines\n", lines);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    // Prompt user for filename
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    // Remove newline character from filename
    filename[strcspn(filename, "\n")] = '\0';
     // Debug print to check the filename
    printf("Attempting to open file: %s\n", filename);

    // Count and display file contents
    countFileContents(filename);

    return 0;
}
