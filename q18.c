#include <stdio.h>
#define SIZE 10

// Function to implement bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    // Outer loop for each pass
    for (i = 0; i < n - 1; i++) {
        // Inner loop to compare adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            // If current element is greater than next element, swap them
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE], n, i;
    
    // Input the size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Input elements in the array
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Display the original array
    printf("Original Array: ");
    displayArray(arr, n);
    
    // Perform bubble sort
    bubbleSort(arr, n);
    
    // Display the sorted array
    printf("Sorted Array: ");
    displayArray(arr, n);
    
    return 0;
}