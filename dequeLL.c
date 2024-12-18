#include <stdio.h>

#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *rear = NULL, *front = NULL;

void insert_at_start()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter an element: ");
    scanf("%d", &newnode->data);
    if (rear == NULL && front == NULL)
    {
        rear = front = newnode;
    }
    else
    {
        newnode->next = rear;
        rear = newnode;
    }
}

void insert_at_end()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter an element: ");
    scanf("%d", &newnode->data);
    if (rear == NULL && front == NULL)
    {
        rear = front = newnode;
    }
    else
    {
        front->next = newnode;
        front = front->next;
    }
}

void delete_at_start()
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        free(rear);
        rear = NULL;
        front = NULL;
    }
    else
    {
        struct node *temp = rear;
        rear = rear->next;
        free(temp);
    }
}

void delete_at_end()
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        free(rear);
        rear = NULL;
        front = NULL;
    }
    else
    {
        struct node *temp;
        for (temp = rear; temp->next != front; temp = temp->next)
            ;
        free(front);
        front = temp;
        front->next=NULL;
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
        for (temp = rear; temp != NULL; temp = temp->next)
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
        printf("1-Insert at start\n2-Insert at end\n3-Delete at start\n4-Delete at end\n5-Display\n6-Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_at_start();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            delete_at_start();
            break;
        case 4:
            delete_at_end();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
} 