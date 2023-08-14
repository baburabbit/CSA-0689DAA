#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

int containers[MAX_CONTAINERS];
int items[MAX_ITEMS];
int numContainers, numItems;

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int loadContainers() {
    qsort(items, numItems, sizeof(int), compare);

    int containerIndex = 0;

    for (int i = 0; i < numItems; i++) {
        if (containers[containerIndex] >= items[i]) {
            containers[containerIndex] -= items[i];
        } else {
            containerIndex++;
            if (containerIndex >= numContainers) {
                return containerIndex;
            }
            containers[containerIndex] -= items[i];
        }
    }

    return containerIndex + 1;
}

int main() {
    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the capacities of the containers:\n");
    for (int i = 0; i < numContainers; i++) {
        scanf("%d", &containers[i]);
    }

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    int usedContainers = loadContainers();

    printf("Number of containers used: %d\n", usedContainers);

    return 0;
}

