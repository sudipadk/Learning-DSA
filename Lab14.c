#include <stdio.h>

#define MAX_SIZE 100 // Define a maximum size for the array

int binarySearch(int arr[], int size, int target) {
    int bottom = 0;
    int top = size - 1;

    while (bottom <= top) {
        int mid = bottom + (top - bottom) / 2; // Calculate midpoint safely

        if (arr[mid] == target) {
            return mid; // Return the index where the target is found
        } else if (arr[mid] < target) {
            bottom = mid + 1;
        } else {
            top = mid - 1;
        }
    }

    return -1; // Return -1 if the target is not found in the array
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1; // Exit the program with an error code
    }

    int arr[MAX_SIZE]; // Using a fixed-size array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d. Enter a data: ", i + 1);
        scanf("%d", &arr[i]);
    }
  
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int index = binarySearch(arr, size, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
