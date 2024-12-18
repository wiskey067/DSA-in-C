#include <stdio.h>
#include<stdlib.h>

void insert_element(int arr[], int n, int element, int position) {
    for (int i = n; i >= position; i--)
        arr[i] = arr[i-1];
    arr[position-1] = element;
}

void delete_element(int arr[], int n, int position) {
    for (int i = position-1; i < n-1; i++)
        arr[i] = arr[i+1];
}

int linear_search(int arr[], int n, int element) {
    for (int i = 0; i < n; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

void traverse_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n+1];
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("Menu\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Traverse array\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int element, position;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert_element(arr, n, element, position);
            n++;
        } else if (choice == 2) {
            int position;
            printf("Enter the position: ");
            scanf("%d", &position);
            delete_element(arr, n, position);
            n--;
        } else if (choice == 3) {
            int element;
            printf("Enter the element to search: ");
            scanf("%d", &element);
            int result = linear_search(arr, n, element);
            if (result == -1)
                printf("Element not found\n");
            else
                printf("Element found at position %d\n", result+1);
        } else if (choice == 4) {
            traverse_array(arr, n);
        } else if (choice == 5) {
            break;
        }
    }
}