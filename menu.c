#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node *head) {
    struct Node *current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the list
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the list
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a new node in the middle of the list
struct Node *insertInMiddle(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node *current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node of the list
struct Node *deleteFirstNode(struct Node *head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node in the middle of the list
struct Node *deleteMiddleNode(struct Node *head, int position) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position for deletion.\n");
        return head;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to delete the last node of the list
struct Node *deleteLastNode(struct Node *head) {
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to search for an element in the list
int searchElement(struct Node *head, int key) {
    struct Node *current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

int main() {
    struct Node *head = NULL;
    int choice, data, position, key, result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create and Display a Singly Linked List\n");
        printf("2. Insert a New Node at the Beginning\n");
        printf("3. Insert a New Node at the End\n");
        printf("4. Insert a Node in the Middle\n");
        printf("5. Delete the First Node\n");
        printf("6. Delete a Node in the Middle\n");
        printf("7. Delete the Last Node\n");
        printf("8. Search for an Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertInMiddle(head, data, position);
                break;
            case 5:
                head = deleteFirstNode(head);
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                head = deleteMiddleNode(head, position);
                break;
            case 7:
                head = deleteLastNode(head);
                break;
            case 8:
                printf("Enter element to search for: ");
                scanf("%d", &key);
                result = searchElement(head, key);
                if (result != -1) {
                    printf("Element found at position %d.\n", result);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
