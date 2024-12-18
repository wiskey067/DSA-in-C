//WAP to perform transpose of a given sparse matrix in 3-tuple format
#include <stdio.h>
#define MAX 20


int main()
{ 
    int sparse[MAX][3], transpose[MAX][3];
    int mat[MAX][MAX], m, n;
    int i, j, k = 1;

    printf("Enter the order of matrix : ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of matrix : \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("\nSparse Matrix : \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (mat[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
    sparse[0][0] = m;
    sparse[0][1] = n;
    sparse[0][2] = k - 1;

    printf("\nSparse Matrix : \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", sparse[i][j]);
        printf("\n");
    }

    // Transpose of Sparse Matrix
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    k = 1;
    for (i = 0; i < n; i++)
        for (j = 1; j <= sparse[0][2]; j++)
            if (sparse[j][1] == i)
            {
                transpose[k][0] = i;
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }

    printf("\nTranspose of Sparse Matrix : \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
}

