#include <stdio.h>

void mergeSortedArrays(int A[], int n, int B[], int m, int merged[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge arrays while both have elements
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            merged[k++] = A[i++];
        } else {
            merged[k++] = B[j++];
        }
    }
    
    // Copy remaining elements of A[]
    while (i < n) {
        merged[k++] = A[i++];
    }
    
    // Copy remaining elements of B[]
    while (j < m) {
        merged[k++] = B[j++];
    }
}

int main() {
    int A[100], B[100], merged[200];
    int n, m, i;
    
    printf("Enter the number of elements in first sorted array: ");
    scanf("%d", &n);
    
    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    printf("Enter the number of elements in second sorted array: ");
    scanf("%d", &m);
    
    printf("Enter %d sorted elements: ", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    
    mergeSortedArrays(A, n, B, m, merged);
    
    printf("Merged Sorted Array: ");
    for (i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }
    
    printf("\n");
    return 0;
}