## BFS - with queue
## Input: A graph G = (V, E) and source node s in V
## Algorithm:
    Mark all nodes as unvisited
    Mark source node as visited
    enqueue(source node)
    while(Queue is not empty) {
        node = deque();
        for each unvisited neighbour v of node {
            mark v as visited;
            enque(v);
        }
    }

## DFS - using stack

## Input: A graph G = (V, E) and source node s in V
## Algorithm:
    Start by putting any one of the graph's vertices of a stack.
    Take the top item of the stack and add it to the visited list.
    Push that vertex's adjacent nodes, which are not visited.