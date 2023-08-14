#include <stdio.h>

void printMinMaxSequence(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            max = arr[i];
        } else {
            printf("Minimum: %d, Maximum: %d\n", min, max);
            min = arr[i];
            max = arr[i];
        }
    }
    
    printf("Minimum: %d, Maximum: %d\n", min, max);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printMinMaxSequence(arr, n);
    
    return 0;
}
