#include <stdio.h>
#include <stdlib.h>

int arr[5];
int rear = -1;
int front = -1;

void insert()
{
    int n = sizeof(arr) / sizeof(int);
    if (front == n - 1)
    {
        printf("Overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        printf("Enter an element: ");
        scanf("%d", &arr[front]);
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
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        rear++;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d\n", arr[front]);
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        for (i = rear; i <= front; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Peek\n4-Display\n5-Exit\nEnter your choice: ");
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
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}