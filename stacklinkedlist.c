#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head=NULL, *top = NULL;

void push(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be pushed: ");
    scanf("%d", &newnode->data);
    if(head==NULL){
        head=newnode;
        top=newnode;
    } else {
        top->next=newnode;
        top=top->next;
    }
}

void pop(){
    if(head==NULL){
        printf("Underflow\n");
    }
    else if(head==top){
        free(head);
        head=NULL;
        top=NULL;
    }
    else {
        struct node* temp;
        for(temp=head;temp->next!=top;temp=temp->next);
        free(top);
        top=temp;
    }
}

void peek(){
    if(head==NULL){
        printf("Stack is empty\n");
    }else {
        printf("%d\n",top->data);
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("1-Push\n2-Pop\n3-Peek\n4-Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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