#include <stdio.h>

// Function to implement naive pattern matching
void patternMatching(char text[], char pattern[]) {
    int i, j;
    int textLen = 0, patternLen = 0;
    
    // Calculate length of text
    while (text[textLen] != '\0') {
        textLen++;
    }
    
    // Calculate length of pattern
    while (pattern[patternLen] != '\0') {
        patternLen++;
    }
    
    int found = 0;
    for (i = 0; i <= textLen - patternLen; i++) {
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Pattern not found\n");
    }
}

int main() {
    char text[100], pattern[50];
    
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    
    // Removing newline characters from text and pattern
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
        i++;
    }
    
    i = 0;
    while (pattern[i] != '\0') {
        if (pattern[i] == '\n') {
            pattern[i] = '\0';
            break;
        }
        i++;
    }
    
    patternMatching(text, pattern);
    
    return 0;
}