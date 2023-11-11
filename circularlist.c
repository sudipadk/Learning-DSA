#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;
    int found = 0;

    // Traverse the list to find the node to be deleted
    do {
        if (current->data == key) {
            found = 1;
            break;
        }
        previous = current;
        current = current->next;
    } while (current != *head);

    if (!found) {
        printf("Node with key %d not found in the list.\n", key);
        return;
    }

    // Update the next pointers of the previous and next nodes to bypass the node to be deleted
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        // If the node to be deleted is the head node, update the head pointer
        *head = current->next;
    }

    // If the node to be deleted is the only node in the list, set the head pointer to NULL
    if (current->next == *head) {
        *head = NULL;
    }

    // Free the memory occupied by the node
    free(current);
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    // Traverse the circular linked list and print the data
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int data, choice;

    while (1) {
        printf("\n1. Insert at the beginning\n");
        printf("2. Delete a node\n");
        printf("3. Display the circular linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the key of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

