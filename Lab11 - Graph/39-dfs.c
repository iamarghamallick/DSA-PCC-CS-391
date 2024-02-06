#include <stdio.h>
#define MAX 100

// global declaration
int size = 7;  // total number of vertices
int start = 0; // starting vertex ( any valid vertex )
int visited[MAX] = {0, 0, 0, 0, 0, 0, 0};
int g[MAX][MAX] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}}; // adjacency matrix of our graph [https://cwh-full-next-space.fra1.digitaloceanspaces.com/videos/data-structures-and-algorithms-in-hindi-87/Image_2.webp]

void dfs(int start)
{
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < size; i++)
        if (g[start][i] == 1 && visited[i] == 0)
            dfs(i); // it uses stack for this recursive function call
}

int main()
{
    int start = 5;
    dfs(start); // funciton call
    return 0;
}

// // Write a C program for implementing depth first search (DFS) in a graph

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_VERTICES 100

// // Function to perform Depth-First Search
// void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int currentVertex, int visited[])
// {
//     printf("%d ", currentVertex);
//     visited[currentVertex] = 1;

//     for (int i = 0; i < vertices; ++i)
//         if (graph[currentVertex][i] == 1 && !visited[i])
//             dfs(graph, vertices, i, visited);
// }

// int main()
// {
//     int vertices = 5, edges = 4;
//     // printf("Enter the number of vertices: ");
//     // scanf("%d", &vertices);

//     // int graph[MAX_VERTICES][MAX_VERTICES] = {0};

//     int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0, 0},
//                                              {1, 0, 1, 1, 0},
//                                              {1, 1, 0, 0, 1},
//                                              {0, 1, 0, 0, 1},
//                                              {0, 0, 1, 1, 0}};

//     // printf("Enter the number of edges: ");
//     // scanf("%d", &edges);

//     // printf("Enter the edges (format: vertex1 vertex2):\n");
//     // for (int i = 0; i < edges; ++i)
//     // {
//     //     int vertex1, vertex2;
//     //     scanf("%d %d", &vertex1, &vertex2);
//     //     graph[vertex1][vertex2] = 1;
//     //     graph[vertex2][vertex1] = 1; // Assuming an undirected graph
//     // }

//     int startVertex = 0;
//     // printf("Enter the starting vertex for DFS: ");
//     // scanf("%d", &startVertex);

//     int visited[MAX_VERTICES] = {0};

//     printf("DFS traversal starting from vertex %d: ", startVertex);
//     dfs(graph, vertices, startVertex, visited);

//     return 0;
// }

// // C code to implement above approach
// #include <stdio.h>
// #include <stdlib.h>

// // Globally declared visited array
// int vis[100];

// // Graph structure to store number
// // of vertices and edges and
// // Adjacency matrix
// struct Graph
// {
//     int V;
//     int E;
//     int **Adj;
// };

// // Function to input data of graph
// struct Graph *adjMatrix()
// {
//     struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
//     if (!G)
//     {
//         printf("Memory Error\n");
//         return NULL;
//     }
//     G->V = 7;
//     G->E = 7;

//     G->Adj = (int **)malloc((G->V) * sizeof(int *));
//     for (int k = 0; k < G->V; k++)
//     {
//         G->Adj[k] = (int *)malloc((G->V) * sizeof(int));
//     }

//     for (int u = 0; u < G->V; u++)
//     {
//         for (int v = 0; v < G->V; v++)
//         {
//             G->Adj[u][v] = 0;
//         }
//     }
//     G->Adj[0][1] = G->Adj[1][0] = 1;
//     G->Adj[0][2] = G->Adj[2][0] = 1;
//     G->Adj[1][3] = G->Adj[3][1] = 1;
//     G->Adj[1][4] = G->Adj[4][1] = 1;
//     G->Adj[1][5] = G->Adj[5][1] = 1;
//     G->Adj[1][6] = G->Adj[6][1] = 1;
//     G->Adj[6][2] = G->Adj[2][6] = 1;

//     return G;
// }

// // DFS function to print DFS traversal of graph
// void DFS(struct Graph *G, int u)
// {
//     vis[u] = 1;
//     printf("%d ", u);
//     for (int v = 0; v < G->V; v++)
//     {
//         if (!vis[v] && G->Adj[u][v])
//         {
//             DFS(G, v);
//         }
//     }
// }

// // Function for DFS traversal
// void DFStraversal(struct Graph *G)
// {
//     for (int i = 0; i < 100; i++)
//     {
//         vis[i] = 0;
//     }
//     for (int i = 0; i < G->V; i++)
//     {
//         if (!vis[i])
//         {
//             DFS(G, i);
//         }
//     }
// }

// // Driver code
// void main()
// {
//     struct Graph *G;
//     G = adjMatrix();
//     DFStraversal(G);
// }
