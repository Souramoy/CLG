#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define MAX 100

// Function to initialize the graph
void initializeGraph(int graph[][MAX], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                graph[i][j] = 0; // Distance to itself is 0
            else
                graph[i][j] = INF; // Initialize other distances as INF
        }
    }
}
// Floyd-Warshall Algorithm
void floydWarshall(int graph[][MAX], int V) {
    int dist[MAX][MAX];
    // Initialize the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    // Main Floyd-Warshall logic
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Detect negative weight cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            printf("Graph contains a negative weight cycle.\n");
            return;
        }
    }
  // Print the shortest distance matrix
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
// Analyze Time Complexity
void analyzeTimeComplexity(int V) {
    printf("\nTime Complexity Analysis:\n");
    printf("1. Iteration over k, i, j (nested loops): O(V^3)\n");
    printf("Overall Time Complexity: O(V^3)\n");
}
// Main Function
int main() {
    int V, E;
    int graph[MAX][MAX];
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    initializeGraph(graph, V);
    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
    }
    floydWarshall(graph, V);
    analyzeTimeComplexity(V);
return 0;
}