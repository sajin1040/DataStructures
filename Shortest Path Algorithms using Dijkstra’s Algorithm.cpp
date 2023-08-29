#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 6 
int minDistance(int dist[], int sptSet[]) 
{
	
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) 
	{
        if (!sptSet[v] && dist[v] < min) 
		{
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int v) 
{
    if (parent[v] == -1) 
	{
        printf("%d ", v);
        return;
    }
    printPath(parent, parent[v]);
    printf("%d ", v);
}


void printSolution(int dist[], int parent[]) 
{
    int src = 0;
    printf("Vertex \t Distance from Source \t Shortest Path\n");
    for (int i = 1; i < V; i++) 
	{
        printf("%d -> %d \t %d \t\t\t", src, i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[V][V], int src) 
{
    int dist[V];     
    int sptSet[V];  
    int parent[V]; 

    for (int i = 0; i < V; i++) 
	{
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) 
	{
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++) 
		{
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) 
			{
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent);
}

int main() 
{
    int graph[V][V] = 
	{
        {0, 2, 0, 0, 1, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };

    dijkstra(graph, 0); 
    return 0;
}

