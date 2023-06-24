#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Graph_t
{
    int numVertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *createGraph(int numVertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjMatrix[i][j] = false;
        }
    }

    return graph;
}

void destroyGraph(Graph *graph)
{
    free(graph);
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = true;
}

void breadthFirstTraversal(Graph *graph, int startVertex)
{
    bool visited[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = false;
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int adjacent = 0; adjacent < graph->numVertices; adjacent++)
        {
            if (graph->adjMatrix[currentVertex][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

int main()
{
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    int n = 2;

    printf("Breadth First Traversal is as (starting from vertex %d):\n", n);
    breadthFirstTraversal(graph, n);
    destroyGraph(graph);

    return 0;
}