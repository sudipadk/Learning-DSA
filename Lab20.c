#include <stdio.h>

void insertionSortAscending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
                insertionSortAscending(arr, size);
                printf("Sorted array in ascending order: ");
                printArray(arr, size);
                printf("\n");
                break;
            case 2:
                insertionSortDescending(arr, size);
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
