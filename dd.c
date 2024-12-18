#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the double linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a new node at a specific position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current->next == NULL && currentPosition < position - 1) {
        printf("Position exceeds the length of the list.\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(current);
        printf("Node deleted from the end.\n");
    }
}

// Function to delete a node from a specific position in the list
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Invalid operation.\n");
    } else if (position == 1) {
        deleteFromBeginning(head);
    } else {
        struct Node* current = *head;
        int currentPosition = 1;
        while (currentPosition < position && current->next != NULL) {
            current = current->next;
            currentPosition++;
        }
        if (currentPosition == position) {
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Node deleted from position %d.\n", position);
        } else {
            printf("Position exceeds the length of the list.\n");
        }
    }
}

// Function to traverse and print the list
void traverseList(struct Node* head) {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to print the list in reverse
void printReverse(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("Reversed List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n----- Menu -----\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Traverse list\n");
        printf("8. Print list in reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                traverseList(head);
                break; } }