#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto the stack.\n");
    } else {
        top++;
        stack[top] = element;
        printf("Element %d pushed onto the stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop element from the stack.\n");
    } else {
        int poppedElement = stack[top];
        top--;
        printf("Element %d popped from the stack.\n", poppedElement);
    }
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    
        printf("Stack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}
