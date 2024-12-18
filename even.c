#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void insertElement(int **arr, int *size, int position, int value) {
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    (*size)++;
    *arr = (int *)realloc(*arr, (*size) * sizeof(int));

    for (int i = *size - 1; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = value;
}

int main() {
    int *arr = NULL;
    int size, position, value;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert a new element: ");
    scanf("%d", &position);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    insertElement(&arr, &size, position, value);

    printf("Modified array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int max = findMax(arr, size);
    int min = findMin(arr, size);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    free(arr);
    return 0;
}
