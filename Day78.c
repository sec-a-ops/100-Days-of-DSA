#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[MAX] = {0};
    int minEdge[MAX];
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        minEdge[i] = INT_MAX;
    }

    minEdge[1] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minVal = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minEdge[j] < minVal) {
                minVal = minEdge[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}
