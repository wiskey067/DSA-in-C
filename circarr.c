// gandfaad
#include <stdio.h>
#include <stdlib.h>

int arr[5];
int rear = -1;
int front = -1;

void insert()
{
    int n = sizeof(arr) / sizeof(int);
    if (rear == -1 && front == -1)
    {
        front++;
        rear++;
        printf("Enter an element: ");
        scanf("%d", &arr[front]);
    }
    else if (front == n - 1)
    {
        if (rear > 0)
        {
            front = 0;
            printf("Enter an element: ");
            scanf("%d", &arr[front]);
        }
        else
        {
            printf("Overflow\n");
        }
    }
    else if (front == rear - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        front++;
        printf("Enter an element: ");
        scanf("%d", &arr[front]);
    }
}

void delete()
{
    int n = sizeof(arr) / sizeof(int);
    if (rear == -1 && front == -1)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else if (rear == n - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
}

void display(){
    int n = sizeof(arr)/sizeof(int);
    if(rear == -1 && front == -1){
        printf("Queue is empty\n");
    } else if (rear<=front){
        int i;
        for(i=rear;i<=front;i++){
            printf("%d ", arr[i]);
        }
    } else {
        int i;
        for(i=rear;i<n;i++){
            printf("%d ",arr[i]);
        }
        for(i=0;i<=front;i++){
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Display\n4-Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}