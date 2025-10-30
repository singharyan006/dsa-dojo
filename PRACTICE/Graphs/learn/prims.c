#include <stdio.h>
#include <limits.h>

#define NUM_VERTICES 5

int findMinKeyVertex(int edgeWeight[], int includedInMST[]) {
    int minWeight = INT_MAX, minVertex;
    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
        if (includedInMST[vertex] == 0 && edgeWeight[vertex] < minWeight) {
            minWeight = edgeWeight[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}

void prim(int graph[NUM_VERTICES][NUM_VERTICES]) {
    int parent[NUM_VERTICES];           // Array to store constructed MST
    int edgeWeight[NUM_VERTICES];       // Key values used to pick minimum weight edge
    int includedInMST[NUM_VERTICES];    // To track vertices included in MST

    // Initialize all keys as infinite and MST set as empty
    for (int i = 0; i < NUM_VERTICES; i++) {
        edgeWeight[i] = INT_MAX;
        includedInMST[i] = 0;
    }

    // Start with first vertex - make key 0 so it's picked first
    edgeWeight[0] = 0;    
    parent[0] = -1;  // First node is always root of MST

    // The MST will have NUM_VERTICES vertices
    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int currentVertex = findMinKeyVertex(edgeWeight, includedInMST);
        includedInMST[currentVertex] = 1;

        // Update key values and parent index of adjacent vertices
        for (int adjacentVertex = 0; adjacentVertex < NUM_VERTICES; adjacentVertex++) {
            // Update only if: edge exists, vertex not in MST, and weight is smaller than current key
            if (graph[currentVertex][adjacentVertex] && 
                includedInMST[adjacentVertex] == 0 && 
                graph[currentVertex][adjacentVertex] < edgeWeight[adjacentVertex]) {
                parent[adjacentVertex] = currentVertex;
                edgeWeight[adjacentVertex] = graph[currentVertex][adjacentVertex];
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < NUM_VERTICES; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Adjacency matrix representation of the graph (undirected weighted graph)
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph);

    return 0;
}
