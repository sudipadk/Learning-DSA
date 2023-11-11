#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
    int elements[MAX_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(CircularQueue *queue) {
    return queue->size == 0;
}

int isFull(CircularQueue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(CircularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->elements[queue->rear] = element;
    queue->size++;

    printf("Enqueued element: %d\n", element);
}

void dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }

    printf("Dequeued element: %d\n", queue->elements[queue->front]);
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
}

void displayQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i, count;
    for (i = queue->front, count = 0; count < queue->size; i = (i + 1) % MAX_SIZE, count++)
        printf("%d ", queue->elements[i]);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    int choice, element;
    while (1) {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

