#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void selectionSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(&arr[i], &arr[maxIndex]);
        }
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
                selectionSortAscending(arr, size);
                printf("Sorted array in ascending order: ");
                printArray(arr, size);
                printf("\n");
                break;
            case 2:
                selectionSortDescending(arr, size);
                printf("Sorted array in descending order: ");
                printArray(arr, size);
                printf("\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 2);

    return 0;
}
