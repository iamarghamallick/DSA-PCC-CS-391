// Write a C program for implementing breadth first search (BFS) in a graph

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

// Function to perform Breadth-First Search
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start)
{
    int queue[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear)
    {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; ++i)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
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
    // printf("Enter the starting vertex for BFS: ");
    // scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);
    bfs(graph, vertices, startVertex);

    return 0;
}
