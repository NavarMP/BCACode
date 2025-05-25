#include <stdio.h>

void countingSort(int arr[], int n) {
    int i, j;
    
    // Find the maximum and minimum element in the array
    int max = arr[0], min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    // Range of the elements (max - min + 1)
    int range = max - min + 1;
    
    // Create a count array and initialize all elements to 0
    int count[range];
    for (i = 0; i < range; i++) {
        count[i] = 0;
    }
    
    // Store the frequency of each element in the count array
    for (i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    // Modify the count array to store cumulative count
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Create an output array to store sorted elements
    int output[n];
    
    // Place the elements in the correct position in the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    // Copy the sorted elements into the original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    countingSort(arr, n);
    
    printf("\nSorted Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}