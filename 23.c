#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonzeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonzeroCount++;
            }
        }
    }

    int sparseMatrix[nonzeroCount + 1][3]; 
    // 3-tuple format: row, column, value
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = nonzeroCount;

    int currentRow = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[currentRow][0] = i;
                sparseMatrix[currentRow][1] = j;
                sparseMatrix[currentRow][2] = matrix[i][j];
                currentRow++;
            }
        }
    }

    printf("Sparse matrix in 3-tuple format:\n");
    for (int i = 0; i <= nonzeroCount; i++) {
        printf("%d %d %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}