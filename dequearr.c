#include <stdio.h>
#include <stdlib.h>

int arr[5];
int rear = -1;
int front = -1;

void insert_at_start(){
    if(rear == -1 && front == -1){
        rear++;
        front++;
        printf("Enter an element: ");
        scanf("%d", &arr[rear])
    }
    else {
    rear--
    }
}