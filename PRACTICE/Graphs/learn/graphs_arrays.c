#include <stdio.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    // For undirected graph
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void removeEdge(int u, int v) {
    graph[u][v] = 0;
    graph[v][u] = 0;
}

void displayGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 4;
    initializeGraph(vertices);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);

    displayGraph();

    return 0;
}
