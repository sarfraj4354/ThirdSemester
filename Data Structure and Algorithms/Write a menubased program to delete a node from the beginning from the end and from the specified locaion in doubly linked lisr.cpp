#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end (to build the list)
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to delete from beginning
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("Deleted first node successfully.\n");
}

// Function to delete from end
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL; // Only one node
    }

    free(current);
    printf("Deleted last node successfully.\n");
}

// Function to delete from specific position
void deleteFromPosition(Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position starts at 1.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node *current = *head;
    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position exceeds list length!\n");
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    printf("Deleted node at position %d successfully.\n", position);
}

// Function to display the list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List (forward): ");
    Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Optional backward traversal
    printf("Doubly Linked List (backward): ");
    if (head != NULL) {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        while (current != NULL) {
            printf("%d <-> ", current->data);
            current = current->prev;
        }
        printf("NULL\n");
    }
}

// Function to free the list memory
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    Node *head = NULL;
    int choice, position;

    // Create a sample list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Initial list:\n");
    displayList(head);

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Delete from beginning\n");
        printf("2. Delete from end\n");
        printf("3. Delete from specific position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromBeginning(&head);
                break;
            case 2:
                deleteFromEnd(&head);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                freeList(head);
                printf("Program exited. Memory freed.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
