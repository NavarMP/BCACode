#include <stdio.h>

// Function for Recursive Binary Search
int binarySearch(int arr[], int low, int high, int x) {
    // Base case: element is not found
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2; // To avoid overflow
    
    // Check if the element is at mid
    if (arr[mid] == x) {
        return mid;
    }
    
    // If element is greater, search in the right half
    if (arr[mid] < x) {
        return binarySearch(arr, mid + 1, high, x);
    }
    
    // If element is smaller, search in the left half
    return binarySearch(arr, low, mid - 1, x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    int result = binarySearch(arr, 0, n - 1, x);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}