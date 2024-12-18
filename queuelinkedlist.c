// gcc -o p queuelinkedlist.c
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
    printf("Enter element to be inserted: ");
    scanf("%d", &newnode->data);
    if (rear == NULL && front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        front->next = newnode;
        front = front->next;
    }
    printf("%d has been inserted\n", newnode->data);
}

void delete()
{
    if (rear == NULL && front == NULL)
    {
        printf("Underflow\n");
    }
    else if (rear == front)
    {
        printf("Deleted Element: %d\n", front->data);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct node *temp = rear;
        rear = rear->next;
        printf("Deleted Element: %d\n", temp->data);
        free(temp);
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
            printf("%d\n", temp->data);
        }
    }
}

void isEmpty()
{
    if (rear == NULL && front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Insert\n2-Delete\n3-Display\n4-Check If Empty\n5-Exit\nEnter your choice: ");
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
            isEmpty();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}