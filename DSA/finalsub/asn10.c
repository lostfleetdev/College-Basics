#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_OFFICES 100 // Maximum number of offices

// Function to find the office with the minimum key value
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
    printf("Edge \tWeight\n");
    for (int i = 1; i < numOffices; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Main function
int main() {
    // Adjacency matrix representation of the graph
    int graph[MAX_OFFICES][MAX_OFFICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    int numOffices = 5; // Total number of offices
    primMST(graph, numOffices); // Call the function to find the MST

    return 0;
}
