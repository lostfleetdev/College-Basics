#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_OFFICES 100 // Maximum number of offices
#define MAX_EDGES 1000  // Maximum number of edges

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Function to find the office with the minimum key value (for Prim's algorithm)
int minKey(int key[], int mstSet[], int numOffices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numOffices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm to find the minimum spanning tree
void primMST(int graph[MAX_OFFICES][MAX_OFFICES], int numOffices) {
    int parent[MAX_OFFICES]; // Array to store the constructed MST
    int key[MAX_OFFICES];    // Key values to pick minimum weight edge
    int mstSet[MAX_OFFICES]; // Track vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < numOffices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0; // All offices are initially not included in the MST
    }

    key[0] = 0;        // Starting from the first office
    parent[0] = -1;   // First node is the root

    for (int count = 0; count < numOffices - 1; count++) {
        // Get the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, numOffices);
        mstSet[u] = 1; // Add the picked vertex to the MST

        // Update the key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < numOffices; v++) {
            // Update key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Prim's Algorithm:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < numOffices; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to find the root of a node (for Kruskal's algorithm)
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Function to perform union of two subsets (for Kruskal's algorithm)
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Function to implement Kruskal's algorithm to find the minimum spanning tree
void kruskalMST(Edge edges[], int numEdges, int numOffices) {
    int parent[MAX_OFFICES];
    for (int i = 0; i < numOffices; i++) {
        parent[i] = -1; // Initialize all subsets as single elements
    }

    // Sort edges based on weight
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("\nKruskal's Algorithm:\n");
    printf("Edge \tWeight\n");
    for (int i = 0; i < numEdges; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        // If including this edge does not cause a cycle
        if (x != y) {
            printf("%d - %d\t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSets(parent, x, y);
        }
    }
}

// Main function
int main() {
    // Adjacency matrix representation of the graph for Prim's algorithm
    int graph[MAX_OFFICES][MAX_OFFICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int numOffices = 5; // Total number of offices
    primMST(graph, numOffices); // Call the function to find the MST using Prim's algorithm

    // Edge list representation of the graph for Kruskal's algorithm
    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]); // Number of edges

    kruskalMST(edges, numEdges, numOffices); // Call the function to find the MST using Kruskal's algorithm

    return 0;
}
