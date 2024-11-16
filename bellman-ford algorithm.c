#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;
// Bellman-Ford Algorithm
void bellmanFord(int V, int E, Edge edges[], int src) {
    int dist[V];
 // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;
// Step 2: Relax all edges (V-1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
  // Step 3: Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
   if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle.\n");
            return;
        }
    }
 // Print the distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}
// Analyze Time Complexity
void analyzeTimeComplexity(int V, int E) {
    printf("\nTime Complexity Analysis:\n");
    printf("1. Relaxation of all edges (V-1) times: O(V * E)\n");
    printf("2. Cycle detection: O(E)\n");
    printf("Overall Time Complexity: O(V * E)\n");
}
// Main Function
int main() {
    int V, E;
  printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
  Edge edges[E];
    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
  int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
 bellmanFord(V, E, edges, src);
    analyzeTimeComplexity(V, E);
  return 0;
}