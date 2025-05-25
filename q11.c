#include <stdio.h>
#define MAX 100
#define SIZE 10

// Function to compare two strings manually
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0')
            return 0; // Strings are equal
        i++;
    }
    return (str1[i] - str2[i]);
}

// Function to copy one string to another manually
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

// Main function to sort strings
int main() {
    char str[SIZE][MAX], temp[MAX];
    int i, j, n;
    
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character
    
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        fgets(str[i], MAX, stdin);
        // Remove newline if present
        int k = 0;
        while (str[i][k] != '\0') {
            if (str[i][k] == '\n') {
                str[i][k] = '\0';
                break;
            }
            k++;
        }
    }
    
    // Bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (stringCompare(str[i], str[j]) > 0) {
                stringCopy(temp, str[i]);
                stringCopy(str[i], str[j]);
                stringCopy(str[j], temp);
            }
        }
    }
    
    printf("\nSorted Strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    
    return 0;
}