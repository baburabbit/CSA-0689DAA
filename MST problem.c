#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5  

int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

int parent[V];  
int key[V];     

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
	int v;
    for ( v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge   Weight\n");
    int i;
    for (i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]) {
	int i;
    for ( i = 0; i < V; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;
	int count;
    bool mstSet[V] = {false};

    for (count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
		int v;
        for (v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    primMST(graph);

    return 0;
}
