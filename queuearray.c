#include <stdio.h>
#include <stdlib.h>

int *arr;
int front = 0;
int rear = 0;
int n;

void createarray() {
    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = (int *) calloc(n, sizeof(int));
}

void insert() {
    if (rear == n) {
        printf("Overflow\n");
    } else {
        int x;
        printf("Enter element to insert: ");
        scanf("%d", &x);
        arr[rear] = x;
        rear++;
    }
}

void delete () {
    if (front == rear) {
        printf("Underflow\n");
    } else {
        printf("Deleted element: %d\n", arr[front]);
        front++;
    }
}

void display() {
    int i;
    if (front == rear) {
        printf("Queue is empty\n");
    } else {
        for (i = front; i < rear; i++) {
            printf("%d\n", arr[i]);
        }
    }
}

void isEmpty() {
    if (front == rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}

void isFull() {
    if (rear == n) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
}

int main() {
    createarray();
    int c;
    while (1) {
        printf("1-Insert\n2-Delete\n3-Display\n4-Check If Empty\n5-Check If Full\n6-Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}