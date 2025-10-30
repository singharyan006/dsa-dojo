#include <stdio.h>
#include <limits.h>

#define NUM_VERTICES 5  // Number of vertices in the graph

int findMinDistanceVertex(int distance[], int visited[]) {
    int minDistance = INT_MAX, minVertex;
    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
        if (visited[vertex] == 0 && distance[vertex] <= minDistance) {
            minDistance = distance[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}

void dijkstra(int graph[NUM_VERTICES][NUM_VERTICES], int sourceVertex) {
    int distance[NUM_VERTICES];
    int visited[NUM_VERTICES];

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < NUM_VERTICES; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance from source to itself is always 0
    distance[sourceVertex] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        int currentVertex = findMinDistanceVertex(distance, visited);
        visited[currentVertex] = 1;

        // Update distance values of adjacent vertices
        for (int adjacentVertex = 0; adjacentVertex < NUM_VERTICES; adjacentVertex++) {
            if (!visited[adjacentVertex] && graph[currentVertex][adjacentVertex] && 
                distance[currentVertex] != INT_MAX && 
                distance[currentVertex] + graph[currentVertex][adjacentVertex] < distance[adjacentVertex]) {
                distance[adjacentVertex] = distance[currentVertex] + graph[currentVertex][adjacentVertex];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex \t Distance from Source %d\n", sourceVertex);
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
