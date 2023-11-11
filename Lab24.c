#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d. Enter a data: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    printArray(arr, size);

    int choice;
    printf("\nSelect sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                heapSort(arr, size);
                printf("Sorted array in ascending order: ");
                printArray(arr, size);
                printf("\n");
                break;
            case 2:
                heapSort(arr, size);
                printf("Sorted array in descending order: ");
                for (int i = size - 1; i >= 0; i--) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 2);

    return 0;
}
