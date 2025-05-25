#include <stdio.h>

// Function to search an element in a 2D array
int searchElement(int arr[][3], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                printf("Element %d found at position (%d, %d)\n", target, i, j);
                return 1; // Return 1 to indicate element is found
            }
        }
    }
    
    printf("Element %d not found\n", target);
    return 0; // Return 0 if element is not found
}

int main() {
    // Example 2D array
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target;
    
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    // Call the search function
    searchElement(arr, 3, 3, target);
    
    return 0;
}