#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph node
struct Node {
    int vertex;
    struct Node* next;
};

// Define the structure for a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;  // Array to keep track of visited nodes
};

// Function to create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;  // Initialize all vertices as not visited
    }
    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS algorithm
void BFS(struct Graph* graph, int startVertex) {
    struct Node* adjList = graph->adjLists[startVertex];
    struct Node* temp;

    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = -1, rear = -1;

    // Mark the starting vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        // Dequeue a vertex from the queue
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        temp = graph->adjLists[currentVertex];
        while (temp) {
            int connectedVertex = temp->vertex;

            // If the vertex is not visited, mark it visited and enqueue it
            if (graph->visited[connectedVertex] == 0) {
                graph->visited[connectedVertex] = 1;
                queue[++rear] = connectedVertex;
            }
            temp = temp->next;
        }
    }
}

// Function to perform BFS traversal starting from a vertex
void BFS_traversal(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            BFS(graph, i);
        }
    }
}

// Main function to test the BFS implementation
int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("Breadth-First Search traversal:\n");
    BFS_traversal(graph);

    return 0;
}
