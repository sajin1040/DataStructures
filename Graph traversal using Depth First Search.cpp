#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};


struct AdjList 
{
    struct Node* head;
};

struct Graph 
{
    int numVertices;
    struct AdjList* array;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; ++i) 
	{
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) 
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}


void DFSRecursive(struct Graph* graph, int vertex, int* visited) 
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) 
	{
        int adjVertex = temp->data;
        if (!visited[adjVertex]) 
		{
            DFSRecursive(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) 
{
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) 
	{
        visited[i] = 0;
    }

    printf("Depth-First Traversal (starting from vertex %d):\n", startVertex);
    DFSRecursive(graph, startVertex, visited);

    free(visited);
}

int main() 
{
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    DFS(graph, 0);

    return 0;
}

