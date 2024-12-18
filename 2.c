#include <stdio.h>
#include <stdlib.h>

// Structure to represent a triplet (row, column, value)
typedef struct {
    int row;
    int col;
    int value;
} Triplet;

// Function to multiply two sparse matrices in triplet form
void multiplySparseMatrices(Triplet *matrix1, int m1, int n1, Triplet *matrix2, int m2, int n2) {
    if (n1 != m2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    // Create a result matrix in triplet form
    int maxSize = m1 * n2; // The maximum number of non-zero elements in the result
    Triplet *result = (Triplet *)malloc(sizeof(Triplet) * maxSize);
    if (result == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    int resultSize = 0; // Number of non-zero elements in the result matrix

    // Transpose the second matrix for efficient multiplication
    Triplet *transposedMatrix2 = (Triplet *)malloc(sizeof(Triplet) * n2 * m2);
    if (transposedMatrix2 == NULL) {
        printf("Memory allocation error.\n");
        free(result);
        return;
    }

    // Initialize transposedMatrix2 with all zeros
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            transposedMatrix2[i * m2 + j].row = i;
            transposedMatrix2[i * m2 + j].col = j;
            transposedMatrix2[i * m2 + j].value = 0;
        }
    }

    // Populate transposedMatrix2 by transposing matrix2
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            int index = i * n2 + j;
            transposedMatrix2[j * m2 + i].row = matrix2[index].col;
            transposedMatrix2[j * m2 + i].col = matrix2[index].row;
            transposedMatrix2[j * m2 + i].value = matrix2[index].value;
        }
    }

    // Multiply the matrices and store the result in result matrix
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            int dotProduct = 0;
            for (int k = 0; k < n1; k++) {
                for (int p = 0; p < n2 * m2; p++) {
                    if (matrix1[i * n1 + k].col == transposedMatrix2[j * m2 + p].col) {
                        dotProduct += matrix1[i * n1 + k].value * transposedMatrix2[j * m2 + p].value;
                    }
                }
            }
            if (dotProduct != 0) {
                result[resultSize].row = i;
                result[resultSize].col = j;
                result[resultSize].value = dotProduct;
                resultSize++;
            }
        }
    }

    // Print the result
    printf("Result matrix in triplet form:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("(%d, %d, %d)\n", result[i].row, result[i].col, result[i].value);
    }

    // Free dynamically allocated memory
    free(result);
    free(transposedMatrix2);
}

int main() {
    int m1, n1, m2, n2;

    // Input dimensions of the first matrix
    printf("Enter the dimensions of the first matrix (m1 n1): ");
    scanf("%d %d", &m1, &n1);

    // Input dimensions of the second matrix
    printf("Enter the dimensions of the second matrix (m2 n2): ");
    scanf("%d %d", &m2, &n2);

    // Input the non-zero elements of the first matrix
    printf("Enter the non-zero elements of the first matrix in triplet form (row col value):\n");
    Triplet *matrix1 = (Triplet *)malloc(sizeof(Triplet) * m1 * n1);
    if (matrix1 == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < m1 * n1; i++) {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    // Input the non-zero elements of the second matrix
    printf("Enter the non-zero elements of the second matrix in triplet form (row col value):\n");
    Triplet *matrix2 = (Triplet *)malloc(sizeof(Triplet) * m2 * n2);
    if (matrix2 == NULL) {
        printf("Memory allocation error.\n");
        free(matrix1);
        return 1;
    }

    for (int i = 0; i < m2 * n2; i++) {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    // Perform matrix multiplication
    multiplySparseMatrices(matrix1, m1, n1, matrix2, m2, n2);

    // Free dynamically allocated memory
    free(matrix1);
    free(matrix2);

    return 0;
}
