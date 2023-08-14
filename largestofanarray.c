#include <stdio.h>

int findLargest(int arr[], int size) {
    int largest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 56, 23, 78};
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargest(arr, size);

    printf("The largest element in the array is: %d\n", largest);

    return 0;
}

