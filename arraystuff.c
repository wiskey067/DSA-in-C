#include <stdio.h>

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int *size, int capacity, int index, int element) {
    if (*size >= capacity) {
        return -1;
    }
    for (int i = *size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    (*size)++;
    return 1;
}

void delete_element(int arr[], int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int size, int element) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100] = {100, 23, 45, 65, 6, 34};
    int size = 6, element = 2, index = 0;

    traverse(arr, size);
    insert(arr, &size, 100, index, element);
    traverse(arr, size);

    int search_result = search(arr, size, 45);
    if (search_result != -1) {
        printf("Element found at index %d\n", search_result);
    } else {
        printf("Element not found\n");
    }

    int binary_search_result = binary_search(arr, size, 45);
    if (binary_search_result != -1) {
        printf("Element found at index %d using binary search\n", binary_search_result);
    } else {
        printf("Element not found using binary search\n");
    }

    delete_element(arr, &size, 2);
    traverse(arr, size);

    return 0;
}