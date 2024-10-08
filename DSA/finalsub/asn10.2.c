#include <stdio.h>
#include <stdlib.h>

#define V 5 // Number of vertices 
#define E 10 // Number of edges 

// Structure to represent a graph edge 
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a graph 
typedef struct Graph {
    Edge* edge;
    int v, e;
} Graph;

// Function to create a graph with V vertices and E edges 
Graph* createGraph(int v, int e) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->v = v;  // Assign the number of vertices from the function arguments
    graph->e = e;  // Assign the number of edges from the function arguments
    graph->edge = (Edge*) malloc(e * sizeof(Edge)); 
    return graph;
}

// Function to find the set of an element in the Union-Find data structure 
int find(int parent[], int i) {
    if (parent[i] == -1) 
        return i; 
    return find(parent, parent[i]);
}

// Function to perform the union of two sets in the Union-Find data structure 
void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Function to compare two edges based on their weights 
int compare(const void* a, const void* b) {
    Edge* a1 = (Edge*) a;
    Edge* b1 = (Edge*) b;
    return a1->weight - b1->weight;
}

// Function to implement Kruskal's algorithm 
void kruskalMST(Graph* graph) {
    int parent[V]; 
    for (int i = 0; i < V; i++) 
        parent[i] = -1;
    
    // Sort all edges in non-decreasing order of their weights 
    qsort(graph->edge, graph->e, sizeof(Edge), compare);
    
    Edge result[V]; // Array to store the resulting MST
    int i = 0, e = 0; // i: index for sorted edges, e: index for result[] 
    
    while (e < V - 1) {
        Edge next_edge = graph->edge[i++];  // Pick the smallest edge
        
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        
        if (x != y) {  // If it does not form a cycle
            result[e++] = next_edge;  // Include this edge in the MST
            unionSet(parent, x, y);
        }
    }
    
    // Print the constructed MST 
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++) 
        printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    Graph* graph = createGraph(V, E);  // Create a graph with V vertices and E edges
    
    // Define the edges of the graph 
    graph->edge[0] = (Edge){0, 1, 2};
    graph->edge[1] = (Edge){0, 2, 4};
    graph->edge[2] = (Edge){1, 2, 1};
    graph->edge[3] = (Edge){1, 3, 7};
    graph->edge[4] = (Edge){2, 3, 3};
    graph->edge[5] = (Edge){2, 4, 5};
    graph->edge[6] = (Edge){3, 4, 8};
    graph->edge[7] = (Edge){0, 3, 6};
    graph->edge[8] = (Edge){1, 4, 9};
    graph->edge[9] = (Edge){2, 3, 2};

    // Apply Kruskal's MST algorithm 
    kruskalMST(graph);

    return 0;
}   