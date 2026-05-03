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

    int source;
    printf("Enter source node: ");
    scanf("%d", &source);

    int dist[MAX], visited[MAX] = {0};

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, minDist = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printf("Shortest distances:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
