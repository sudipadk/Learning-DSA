#include <stdio.h>
int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found in the array
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1; // Indicate an error
    }
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d. Enter a data: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int index = sequentialSearch(arr, size, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}
