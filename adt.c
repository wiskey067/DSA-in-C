#include <stdio.h>
#include <stdlib.h>

typedef struct MyArray {
    int total_size;
    int used_size;
    int *ptr;
} MyArray;

void createArray(MyArray *a, int tSize, int uSize) {
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = malloc(tSize * sizeof(int));
    if (!a->ptr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void show(MyArray *a) {
    for (int i = 0; i < a->used_size; i++) {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setValue(MyArray *a) {
    int n, i;
    for (i = 0; i < a->used_size; i++) {
        printf("Enter value: ");
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main() {
    MyArray marks;
    createArray(&marks, 100, 22);
    printf("Setting values\n");
    setValue(&marks);
    printf("Showing values\n");
    show(&marks);
    return 0;
}
