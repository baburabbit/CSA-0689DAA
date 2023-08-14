#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int n; // Number of vertices

bool isSafe(int v, int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool hamiltonianCircuitUtil(int path[], int pos) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        }
        return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(path, pos + 1)) {
                return true;
            }

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

bool hamiltonianCircuit() {
    int path[MAX_VERTICES];
    for (int i = 0; i < n; i++) {
        path[i] = -1;
    }

    path[0] = 0; // Start from vertex 0

    if (!hamiltonianCircuitUtil(path, 1)) {
        printf("No Hamiltonian circuit found.\n");
        return false;
    }

    printf("Hamiltonian circuit found:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);

    return true;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamiltonianCircuit();

    return 0;
}

