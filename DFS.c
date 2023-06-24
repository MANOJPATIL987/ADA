#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertexNumber;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    int *visited;
    struct Node **adjacencyLists;
};

struct Node *createNewNode(int v)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertexNumber = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeToGraph(struct Graph *graph, int source, int destination)
{
    struct Node *newNode = createNewNode(destination);
    newNode->next = graph->adjacencyLists[source];
    graph->adjacencyLists[source] = newNode;
    newNode = createNewNode(source);
    newNode->next = graph->adjacencyLists[destination];
    graph->adjacencyLists[destination] = newNode;
}

struct Graph *createNewGraph(int vertices)
{
    int i;
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjacencyLists = malloc(vertices * sizeof(struct Node *));
    graph->visited = malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++)
    {
        graph->adjacencyLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void performDFS(struct Graph *graph, int vertexNumber)
{
    struct Node *adjList = graph->adjacencyLists[vertexNumber];
    struct Node *temp = adjList;
    graph->visited[vertexNumber] = 1;
    printf("%d ", vertexNumber);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertexNumber;
        if (graph->visited[connectedVertex] == 0)
        {
            performDFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int numVertices, numEdges, i;
    int source, destination;
    int startingVertex;
    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d%d", &numVertices, &numEdges);
    struct Graph *graph = createNewGraph(numVertices);
    printf("Add %d edges to the graph (vertex numbering should be from 0 to %d)\n", numEdges, numVertices - 1);
    for (i = 0; i < numEdges; i++)
    {
        scanf("%d%d", &source, &destination);
        addEdgeToGraph(graph, source, destination);
    }
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startingVertex);
    if (startingVertex < numVertices)
    {
        printf("DFS Traversal: ");
        performDFS(graph, startingVertex);
    }
    return 0;
}