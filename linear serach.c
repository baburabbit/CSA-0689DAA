#include <stdio.h>

int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;  
        }
    }
    return -1; 
}

int main() {
    int array[] = {12, 45, 67, 89, 34, 56, 23, 78};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int index = linearSearch(array, size, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

