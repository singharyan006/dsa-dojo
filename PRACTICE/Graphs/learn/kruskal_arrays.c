#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

int parent[MAX_EDGES];
int rank[MAX_EDGES];

// Find set with path compression
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union sets by rank
void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to sort edges by weight using selection sort
void sortEdges(int u[], int v[], int weight[], int E) {
    for (int i = 0; i < E - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < E; j++) {
            if (weight[j] < weight[min_idx])
                min_idx = j;
        }
        // Swap weights
        int tempW = weight[i];
        weight[i] = weight[min_idx];
        weight[min_idx] = tempW;
        // Swap u
        int tempU = u[i];
        u[i] = u[min_idx];
        u[min_idx] = tempU;
        // Swap v
        int tempV = v[i];
        v[i] = v[min_idx];
        v[min_idx] = tempV;
    }
}

void kruskal(int u[], int v[], int weight[], int V, int E) {
    // Initialize Union-Find
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sortEdges(u, v, weight, E);

    printf("Edges in MST:\n");
    int e = 0; // MST edges count
    for (int i = 0; i < E && e < V - 1; i++) {
        int x = find(u[i]);
        int y = find(v[i]);

        if (x != y) {
            printf("%d -- %d == %d\n", u[i], v[i], weight[i]);
            unionSets(x, y);
            e++;
        }
    }
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    int u[] = {0, 0, 0, 1, 2};         // Edge start vertices
    int v[] = {1, 2, 3, 3, 3};         // Edge end vertices
    int weight[] = {10, 6, 5, 15, 4};  // Edge weights

    kruskal(u, v, weight, V, E);

    return 0;
}
