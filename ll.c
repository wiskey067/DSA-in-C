#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; 
};

void traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
} 
void insert_at_begin(struct Node *head){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("enter data");
    scanf("%d", &ptr->data);
    ptr->next=head;
    head=ptr;

}
int main(){
    int a;
    printf("choose from 1-5")
    scanf("%d"&a);
    switch(a){
        case 1:
        traversal(a)
}