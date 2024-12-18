
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *rear = NULL, *front = NULL;

void insert()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &newnode->data);
    if (rear == NULL && front == NULL)
    {
        front = rear = newnode;
        front->next = rear;
    }
    else
    {
        front->next = newnode;
        front = front->next;
        front->next = rear;
    }
}

void delete()
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        free(rear);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct node *temp = rear;
        rear = rear->next;
        free(temp);
        front->next = rear;
    }
}

void peek()
{
    if (rear == NULL && front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d\n", front->data);
    }
}

void display()
{
    if (rear == NULL && front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp;
        printf("%d ", rear->data);
        for (temp = rear->next; temp != rear; temp = temp->next)
        {
            printf("%d ", temp->data);
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