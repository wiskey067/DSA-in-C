#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count = 0;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int a[n][n];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Find the no.of nonzero elements
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("The number of nonzero elements in the matrix is: %d\n", count);

    // Display upper triangular matrix
    printf("The upper triangular matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Display the elements of just above and below the main diagonal
    printf("The elements of just above and below the main diagonal are:\n");
    for (i = 1; i < n - 1; i++)
    {
        printf("%d ", a[i - 1][i]);
        printf("%d ", a[i][i]);
        printf("%d\n", a[i + 1][i]);
    }

    return 0;
}