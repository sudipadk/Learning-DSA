
// Define the maximum size of the queue
#define MAX_SIZE 100

// Initialize the queue
int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int itemCount = 0;

// Function to check if the queue is empty
int isEmpty() {
    return (itemCount == 0);
}

// Function to check if the queue is full
int isFull() {
    return (itemCount == MAX_SIZE);
}

// Function to insert an element into the queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Overflow condition.\n");
        return;
    }
    if (rear == MAX_SIZE - 1) {
        rear = -1;
    }
    rear++;
    queue[rear] = item;
    itemCount++;
    printf("Element %d inserted into the queue.\n", item);
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Underflow condition.\n");
        return -1;
    }
    int item = queue[front];
    front++;
    if (front == MAX_SIZE) {
        front = 0;
    }
    itemCount--;
    printf("Element %d removed from the queue.\n", item);
    return item;
}

// Function to get the front element of the queue without removing it
int getFront() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

// Function to display the elements in the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    int count = 0;
    int index = front;
    while (count < itemCount) {
        printf("%d ", queue[index]);
        index++;
        if (index == MAX_SIZE) {
            index = 0;
        }
        count++;
    }
    printf("\n");
}

// Usage example
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue(); // Output: Elements in the queue: 10 20 30
    dequeue();
    displayQueue(); // Output: Elements in the queue: 20 30
    printf("Front element: %d\n", getFront()); // Output: Front element: 20
    return 0;
}

