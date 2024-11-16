#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1000
#define INF INT_MAX
// Structure for a graph edge
typedef struct {
    int dest, weight;
} Edge;
// Structure for a graph node
typedef struct {
    int vertex, distance;
} Node;
// Min-Heap (Priority Queue) for Dijkstra's Algorithm
typedef struct {
    Node heap[MAX];
    int size;
} MinHeap;
// Function prototypes
void initializeGraph(int graph[][MAX], int V);
void addEdge(int graph[][MAX], int u, int v, int weight);
void dijkstra(int graph[][MAX], int V, int src, int dest);
void analyzeTimeComplexity(int V, int E);
// Min-Heap function prototypes
void initializeHeap(MinHeap* minHeap);
void pushHeap(MinHeap* minHeap, int vertex, int distance);
Node popHeap(MinHeap* minHeap);
void decreaseKey(MinHeap* minHeap, int vertex, int distance, int* positions);
int isHeapEmpty(MinHeap* minHeap);
// Min-Heap helper functions
void swapNodes(Node* a, Node* b);
void heapifyDown(MinHeap* minHeap, int idx);
void heapifyUp(MinHeap* minHeap, int idx);
// Initialize the graph
void initializeGraph(int graph[][MAX], int V) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = (i == j) ? 0 : INF;
}
// Add edge to the graph
void addEdge(int graph[][MAX], int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight; // Since it's an undirected graph
}
// Dijkstra's Algorithm
void dijkstra(int graph[][MAX], int V, int src, int dest) {
    int dist[V], visited[V], parent[V];
    MinHeap minHeap;
    initializeHeap(&minHeap);
    int positions[V];
 // Initialize distances, visited, and parents
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
        positions[i] = -1;
    }
   dist[src] = 0;
   pushHeap(&minHeap, src, 0);
    positions[src] = 0;
   while (!isHeapEmpty(&minHeap)) {
        Node current = popHeap(&minHeap);
        int u = current.vertex;
   if (visited[u]) continue;
        visited[u] = 1;
   for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && !visited[v]) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = u;
                    if (positions[v] == -1) {
                        pushHeap(&minHeap, v, newDist);
                        positions[v] = minHeap.size - 1;
                    } else {
                        decreaseKey(&minHeap, v, newDist, positions);
                    }
                }
            }
        }
    }
  // Print the shortest path
    printf("Shortest path from %d to %d is %d\n", src, dest, dist[dest]);
 // Backtrack to print the path
    printf("Path: ");
    int path[MAX], pathSize = 0;
    for (int v = dest; v != -1; v = parent[v]) {
        path[pathSize++] = v;
    }
    for (int i = pathSize - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}
// Time Complexity Analysis
void analyzeTimeComplexity(int V, int E) {
    printf("Time Complexity Analysis:\n");
    printf("1. Priority Queue Operations (insert, decrease-key, and extract-min): O((V + E) log V)\n");
    printf("2. Overall Time Complexity: O((V + E) log V)\n");
}
// Min-Heap Functions
void initializeHeap(MinHeap* minHeap) {
    minHeap->size = 0;
}
void pushHeap(MinHeap* minHeap, int vertex, int distance) {
    minHeap->heap[minHeap->size].vertex = vertex;
    minHeap->heap[minHeap->size].distance = distance;
    heapifyUp(minHeap, minHeap->size++);
}
Node popHeap(MinHeap* minHeap) {
    Node root = minHeap->heap[0];
    minHeap->heap[0] = minHeap->heap[--minHeap->size];
    heapifyDown(minHeap, 0);
    return root;
}
void decreaseKey(MinHeap* minHeap, int vertex, int distance, int* positions) {
    int idx = positions[vertex];
    minHeap->heap[idx].distance = distance;
    heapifyUp(minHeap, idx);
}
int isHeapEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}
void swapNodes(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyDown(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
  if (left < minHeap->size && minHeap->heap[left].distance < minHeap->heap[smallest].distance)
        smallest = left;
    if (right < minHeap->size && minHeap->heap[right].distance < minHeap->heap[smallest].distance)
        smallest = right;
if (smallest != idx) {
        swapNodes(&minHeap->heap[idx], &minHeap->heap[smallest]);
        heapifyDown(minHeap, smallest);
    }
}
void heapifyUp(MinHeap* minHeap, int idx) {
    int parent = (idx - 1) / 2;
    while (idx > 0 && minHeap->heap[idx].distance < minHeap->heap[parent].distance) {
        swapNodes(&minHeap->heap[idx], &minHeap->heap[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}
// Main Function
int main() {
    int graph[MAX][MAX], V, E;
printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);initializeGraph(graph, V);
printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(graph, u, v, weight);
    }
 int src, dest;
    printf("Enter the source and destination: ");
    scanf("%d %d", &src, &dest);
   dijkstra(graph, V, src, dest);
    analyzeTimeComplexity(V, E);
  return 0;  }