#include <stdio.h>

#define MAX_ELEMENTS 100

int set[MAX_ELEMENTS];
int subset[MAX_ELEMENTS];
int n, targetSum;

void backtrack(int index, int currentSum) {
    if (currentSum == targetSum) {
        printf("Subset with target sum found: { ");
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }
    
    if (index >= n || currentSum > targetSum) {
        return;
    }

    // Include the current element in the subset
    subset[index] = set[index];
    backtrack(index + 1, currentSum + set[index]);
    
    // Exclude the current element from the subset
    subset[index] = 0;
    backtrack(index + 1, currentSum);
}

void findSubsetsWithSum() {
    backtrack(0, 0);
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    
    printf("Subsets with target sum:\n");
    findSubsetsWithSum();
    
    return 0;
}

