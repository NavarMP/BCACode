#include <stdio.h>

#define MAX 100

struct SparseMatrix {
    int row;
    int col;
    int value;
};

int main() {
    int matrix[10][10];
    struct SparseMatrix sparse[MAX];
    int i, j, rows, cols, nonZeroCount = 0;

    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d%d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                sparse[nonZeroCount].row = i;
                sparse[nonZeroCount].col = j;
                sparse[nonZeroCount].value = matrix[i][j];
                nonZeroCount++;
            }
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSparse Matrix Representation (Triplet Format):\n");
    printf("Row Column Value\n");
    for (i = 0; i < nonZeroCount; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}