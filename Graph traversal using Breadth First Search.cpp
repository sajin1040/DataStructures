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

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void BFS(struct Graph* graph, int startVertex) 
{
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) 
	{
        visited[i] = 0;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) 
	{
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->array[currentVertex].head;
        while (temp) 
		{
            int adjVertex = temp->data;
            if (!visited[adjVertex]) 
			{
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

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

    printf("Breadth-First Traversal (starting from vertex 0):\n");
    BFS(graph, 0);

    return 0;
}

