#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the end of the list
void insertElement(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Element %d inserted successfully.\n", value);
}

// Function to modify an element in the list
void modifyElement(struct Node* head, int oldVal, int newVal) {
    struct Node* temp = head;
    int modified = 0;

    while (temp != NULL) {
        if (temp->data == oldVal) {
            temp->data = newVal;
            modified = 1;
            printf("Element modified successfully.\n");
            break;
        }
        temp = temp->next;
    }

    if (modified == 0) {
        printf("Element %d not found in the list.\n", oldVal);
    }
}

// Function to delete an element from the list
void deleteElement(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int deleted = 0;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        deleted = 1;
        printf("Element %d deleted successfully.\n", value);
        return;
    }

    while (temp != NULL) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            deleted = 1;
            printf("Element %d deleted successfully.\n", value);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (deleted == 0) {
        printf("Element %d not found in the list.\n", value);
    }
}

// Function to traverse and display the list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;

    return list1;
}

int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    int choice, value, oldVal, newVal;

printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Modify an element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Merge two lists\n");
        printf("6. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &value);
                insertElement(&head, value);
                break;
            case 2:
                printf("Enter the element to be modified: ");
                scanf("%d", &oldVal);
                printf("Enter the new value: ");
                scanf("%d", &newVal);
                modifyElement(head, oldVal, newVal);
                break;
            case 3:
                printf("Enter the element to be deleted: ");
                scanf("%d", &value);
                deleteElement(&head, value);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Create a second list.\n");
                printf("Enter the element to be inserted: ");
                scanf("%d", &value);
                insertElement(&head2, value);
                printf("Merging the two lists...\n");
                head = mergeLists(head, head2);
                printf("Lists merged successfully.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 6);

    return 0;
}
