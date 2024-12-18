#include <stdio.h>
#include <stdlib.h>

int arr[5];
int top = -1;

void insert()
{
    int n = sizeof(arr)/sizeof(int);
    int x;
    printf("Enter an element: ");
    scanf("%d", &x);
    if (top == n-1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

void delete()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d\n", arr[top]);
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Peek\n4-Exit\nEnter your choice: ");
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
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}