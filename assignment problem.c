#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10

int n;
int costMatrix[MAX_N][MAX_N];
bool assignedRows[MAX_N], assignedCols[MAX_N];
int minCost = INT_MAX;

void initialize() {
    for (int i = 0; i < n; i++) {
        assignedRows[i] = false;
        assignedCols[i] = false;
    }
}

void reduceMatrix(int reducedMatrix[MAX_N][MAX_N]) {
    for (int i = 0; i < n; i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (reducedMatrix[i][j] < minVal) {
                minVal = reducedMatrix[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            reducedMatrix[i][j] -= minVal;
        }
    }
    
    for (int i = 0; i < n; i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (reducedMatrix[j][i] < minVal) {
                minVal = reducedMatrix[j][i];
            }
        }
        for (int j = 0; j < n; j++) {
            reducedMatrix[j][i] -= minVal;
        }
    }
}

void assignTask(int reducedMatrix[MAX_N][MAX_N], int row, int col, int totalCost) {
    assignedRows[row] = true;
    assignedCols[col] = true;
    totalCost += costMatrix[row][col];

    if (row == n - 1) {
        if (totalCost < minCost) {
            minCost = totalCost;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!assignedRows[i]) {
            for (int j = 0; j < n; j++) {
                if (!assignedCols[j] && (reducedMatrix[i][j] == 0)) {
                    assignedRows[i] = true;
                    assignedCols[j] = true;
                    assignTask(reducedMatrix, i, j, totalCost);
                    assignedRows[i] = false;
                    assignedCols[j] = false;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of workers/jobs: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    int reducedMatrix[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reducedMatrix[i][j] = costMatrix[i][j];
        }
    }

    initialize();
    reduceMatrix(reducedMatrix);
    assignTask(reducedMatrix, 0, 0, 0);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}

