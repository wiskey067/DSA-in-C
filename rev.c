#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Recursive function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    // Base case: If the list is empty or has only one element, return it
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    struct Node* rest = reverseList(head->next);

    // Reverse the current node
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning of the list
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Original Linked List: ");
    printList(head);

    // Reverse the linked list using recursion
    head = reverseList(head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
