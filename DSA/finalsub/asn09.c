#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for a graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with the given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node**) malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to perform DFS traversal
void DFS(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform BFS traversal
void BFS(Graph* graph, int vertex, int* visited) {
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    queue[rear++] = vertex;
    visited[vertex] = 1;
    while (front < rear) {
        vertex = queue[front++];
        printf("%d ", vertex);
        Node* temp = graph->adjLists[vertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    int visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFS(graph, 0, visited);
    printf("\n");

    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("BFS Traversal: ");
    BFS(graph, 0, visited);
    printf("\n");

    return 0;
}