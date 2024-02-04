// Write a C program for implementing depth first search (DFS) in a graph

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

// Function to perform Depth-First Search
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int currentVertex, int visited[])
{
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;

    for (int i = 0; i < vertices; ++i)
        if (graph[currentVertex][i] == 1 && !visited[i])
            dfs(graph, vertices, i, visited);
}

int main()
{
    int vertices = 5, edges = 4;
    // printf("Enter the number of vertices: ");
    // scanf("%d", &vertices);

    // int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0, 0},
                                             {1, 0, 1, 1, 0},
                                             {1, 1, 0, 0, 1},
                                             {0, 1, 0, 0, 1},
                                             {0, 0, 1, 1, 0}};

    // printf("Enter the number of edges: ");
    // scanf("%d", &edges);

    // printf("Enter the edges (format: vertex1 vertex2):\n");
    // for (int i = 0; i < edges; ++i)
    // {
    //     int vertex1, vertex2;
    //     scanf("%d %d", &vertex1, &vertex2);
    //     graph[vertex1][vertex2] = 1;
    //     graph[vertex2][vertex1] = 1; // Assuming an undirected graph
    // }

    int startVertex = 0;
    // printf("Enter the starting vertex for DFS: ");
    // scanf("%d", &startVertex);

    int visited[MAX_VERTICES] = {0};

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(graph, vertices, startVertex, visited);

    return 0;
}
