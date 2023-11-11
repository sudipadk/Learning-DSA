#include <stdio.h>

void shellSortAscending(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSortDescending(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
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
                shellSortAscending(arr, size);
                printf("Sorted array in ascending order: ");
                printArray(arr, size);
                printf("\n");
                break;
            case 2:
                shellSortDescending(arr, size);
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
