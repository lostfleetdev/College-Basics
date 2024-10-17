/* Name    : Raman Bhise 
   Roll no.: 52 
   Class   : IT SY B  
   Batch   : C 
   Subject : DSA Lab*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the adjacency list
struct Node {
    char* vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a node
struct Node* createNode(char* vertex) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to find the index of a vertex
int findVertexIndex(struct Graph* graph, char* vertex) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjLists[i] != NULL && strcmp(graph->adjLists[i]->vertex, vertex) == 0) {
            return i;
        }
    }
    return -1; // Vertex not found
}

// Function to add a vertex if it doesn't exist
int addVertex(struct Graph* graph, char* vertex) {
    // Check if vertex already exists
    if (findVertexIndex(graph, vertex) != -1) {
        return 0; // Vertex already exists
    }

    // Allocate memory for a new adjacency list
    graph->adjLists = realloc(graph->adjLists, (graph->numVertices + 1) * sizeof(struct Node*));
    graph->adjLists[graph->numVertices] = createNode(vertex);
    graph->numVertices++;
    
    return 1; // Vertex added
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, char* src, char* dest) {
    addVertex(graph, src);
    addVertex(graph, dest);

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[findVertexIndex(graph, src)];
    graph->adjLists[findVertexIndex(graph, src)] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[findVertexIndex(graph, dest)];
    graph->adjLists[findVertexIndex(graph, dest)] = newNode;
}

// Depth First Search (DFS) helper function
void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%s ", graph->adjLists[vertex]->vertex); // Print the vertex

    // Recur for all the vertices adjacent to this vertex
    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int adjVertex = findVertexIndex(graph, adjList->vertex);
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        adjList = adjList->next;
    }
}

// Depth First Search (DFS) function
void DFS(struct Graph* graph, char* start) {
    int* visited = calloc(graph->numVertices, sizeof(int));
    int startIndex = findVertexIndex(graph, start);
    printf("DFS Traversal starting from %s: ", start);
    if (startIndex != -1) {
        DFSUtil(graph, startIndex, visited);
    }
    printf("\n");
    free(visited);
}

// Breadth First Search (BFS) function
void BFS(struct Graph* graph, char* start) {
    int* visited = calloc(graph->numVertices, sizeof(int));
    printf("BFS Traversal starting from %s: ", start);
    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = -1, rear = -1;

    // Enqueue the starting vertex
    int startIndex = findVertexIndex(graph, start);
    if (startIndex != -1) {
        rear++;
        queue[rear] = startIndex;
        visited[queue[rear]] = 1;
    }

    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%s ", graph->adjLists[currentVertex]->vertex); // Print the vertex

        // Get all adjacent vertices of the dequeued vertex
        struct Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int adjVertex = findVertexIndex(graph, adjList->vertex);
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1; // Mark as visited
                rear++;
                queue[rear] = adjVertex; // Enqueue the vertex
            }
            adjList = adjList->next;
        }
    }
    printf("\n");
    free(visited);
}

// Main function
int main() {
    struct Graph* g = createGraph(0); // Create an empty graph

    // Adding edges to the graph
    addEdge(g, "A", "B");
    addEdge(g, "A", "C");
    addEdge(g, "B", "D");
    addEdge(g, "C", "E");
    addEdge(g, "C", "F");
    addEdge(g, "E", "G");
    addEdge(g, "F", "G");

    // Perform DFS and BFS
    DFS(g, "A");
    BFS(g, "A");

    // Free allocated memory
    for (int i = 0; i < g->numVertices; i++) {
        struct Node* temp = g->adjLists[i];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(g->adjLists);
    free(g);

    return 0;
}