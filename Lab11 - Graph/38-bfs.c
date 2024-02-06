#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    return front == -1 && rear == -1;
}

int isFull()
{
    return rear == MAX - 1;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    q[++rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        exit(0);
    }
    if (front == rear)
    {
        int temp = q[front];
        front = rear = -1;
        return temp;
    }
    int temp = q[front++];
    return temp;
}

// BFS Implementation
// Algorithm:
//      Mark all nodes as unvisited
//      Mark start node as visited
//      enqueue(start node)
//      while (Queue is not empty) {
//      node = deque();
//          for each unvisited neighbour v of node {
//              mark v as visited;
//              enqueue(v);
//          }
//      }

void bfs(int *g, int size, int start)
{
    int visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = 0;

    printf("%d ", start);
    visited[start] = 1;
    enqueue(start); // enqueue start vertex for exploration

    while (!isEmpty())
    {
        int node = dequeue();
        for (int i = 0; i < size; i++)
        {
            if (*(g + node * size + i) == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int size = 7;  // total number of vertices
    int start = 0; // starting vertex ( any valid vertex )
    int g[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}}; // adjacency matrix of our graph [https://cwh-full-next-space.fra1.digitaloceanspaces.com/videos/data-structures-and-algorithms-in-hindi-87/Image_2.webp]

    bfs(&g[0][0], size, start); // funciton call

    return 0;
}

// // Write a C program for implementing breadth first search (BFS) in a graph

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_VERTICES 100

// // Function to perform Breadth-First Search
// void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start)
// {
//     int queue[MAX_VERTICES];
//     int visited[MAX_VERTICES] = {0};
//     int front = -1, rear = -1;

//     queue[++rear] = start;
//     visited[start] = 1;

//     while (front != rear)
//     {
//         int currentVertex = queue[++front];
//         printf("%d ", currentVertex);

//         for (int i = 0; i < vertices; ++i)
//         {
//             if (graph[currentVertex][i] == 1 && !visited[i])
//             {
//                 queue[++rear] = i;
//                 visited[i] = 1;
//             }
//         }
//     }
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
//     // printf("Enter the starting vertex for BFS: ");
//     // scanf("%d", &startVertex);

//     printf("BFS traversal starting from vertex %d: ", startVertex);
//     bfs(graph, vertices, startVertex);

//     return 0;
// }

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_VERTICES 50

// // This struct represents a directed graph using
// // adjacency list representation
// typedef struct Graph_t
// {
//     // No. of vertices
//     int V;
//     bool adj[MAX_VERTICES][MAX_VERTICES];
// } Graph;

// // Constructor
// Graph *Graph_create(int V)
// {
//     Graph *g = malloc(sizeof(Graph));
//     g->V = V;

//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             g->adj[i][j] = false;
//         }
//     }

//     return g;
// }

// // Destructor
// void Graph_destroy(Graph *g) { free(g); }

// // Function to add an edge to graph
// void Graph_addEdge(Graph *g, int v, int w)
// {
//     // Add w to v’s list.
//     g->adj[v][w] = true;
// }

// // Prints BFS traversal from a given source s
// void Graph_BFS(Graph *g, int s)
// {
//     // Mark all the vertices as not visited
//     bool visited[MAX_VERTICES];
//     for (int i = 0; i < g->V; i++)
//     {
//         visited[i] = false;
//     }

//     // Create a queue for BFS
//     int queue[MAX_VERTICES];
//     int front = 0, rear = 0;

//     // Mark the current node as visited and enqueue it
//     visited[s] = true;
//     queue[rear++] = s;

//     while (front != rear)
//     {

//         // Dequeue a vertex from queue and print it
//         s = queue[front++];
//         printf("%d ", s);

//         // Get all adjacent vertices of the dequeued
//         // vertex s.
//         // If an adjacent has not been visited,
//         // then mark it visited and enqueue it
//         for (int adjacent = 0; adjacent < g->V;
//              adjacent++)
//         {
//             if (g->adj[s][adjacent] && !visited[adjacent])
//             {
//                 visited[adjacent] = true;
//                 queue[rear++] = adjacent;
//             }
//         }
//     }
// }

// // Driver code
// int main()
// {
//     // Create a graph
//     Graph *g = Graph_create(4);
//     Graph_addEdge(g, 0, 1);
//     Graph_addEdge(g, 0, 2);
//     Graph_addEdge(g, 1, 2);
//     Graph_addEdge(g, 2, 0);
//     Graph_addEdge(g, 2, 3);
//     Graph_addEdge(g, 3, 3);

//     printf("Following is Breadth First Traversal "
//            "(starting from vertex 2) \n");
//     Graph_BFS(g, 2);
//     Graph_destroy(g);

//     return 0;
// }
