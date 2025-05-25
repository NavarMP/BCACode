#include <stdio.h>

// Function for Iterative Binary Search
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // To avoid overflow
        
        // Check if the element is present at mid
        if (arr[mid] == x) {
            return mid;
        }
        
        // If element is greater, ignore the left half
        if (arr[mid] < x) {
            low = mid + 1;
        }
        // If element is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    int result = binarySearch(arr, n, x);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}