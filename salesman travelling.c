#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n;  
int distance[MAX_CITIES][MAX_CITIES];
int memo[MAX_CITIES][1 << MAX_CITIES];

int tsp(int current, int visited) {
    if (visited == (1 << n) - 1) {
        return distance[current][0];  
    }

    if (memo[current][visited] != -1) {
        return memo[current][visited];
    }

    int minCost = INT_MAX;
    for (int next = 0; next < n; next++) {
        if ((visited & (1 << next)) == 0) {  
            int newVisited = visited | (1 << next);
            int cost = distance[current][next] + tsp(next, newVisited);
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }

    return memo[current][visited] = minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &distance[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }

    int minCost = tsp(0, 1);  
    printf("Minimum cost for the TSP: %d\n", minCost);

    return 0;
}

