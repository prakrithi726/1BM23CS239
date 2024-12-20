
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int stack[MAX_NODES];
int top = -1;
int nodes;





int DFS(int startNode) {
    int visitedCount = 0;
    stack[++top] = startNode;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            visited[node] = 1;
            visitedCount++;
            for (int i = 0; i < nodes; i++) {
                if (graph[node][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    return visitedCount;
}






int main() {
    int edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v) where u and v are node indices starting from 0:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    int visitedNodes = DFS(0);

    if (visitedNodes == nodes) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}






output - --------
Enter the number of nodes: 4
Enter the number of edges: 3
Enter the edges (u v) where u and v are node indices starting from 0:
0 1
1 2
2 3
The graph is connected.

Enter the number of nodes: 5
Enter the number of edges: 3
Enter the edges (u v) where u and v are node indices starting from 0:
0 1
1 2
3 4
The graph is not connected.

