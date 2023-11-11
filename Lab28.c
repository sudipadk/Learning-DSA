#include <stdio.h>
#include <limits.h>

int minDistance(int dist[], int visited[], int num) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < num; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void displayPath(int parent[], int j, int source) {
    if (j == source) {
        printf(" %d", j + 1);
        return;
    }
    displayPath(parent, parent[j], source);
    printf(" -> %d", j + 1);
}

void dijkstra(int num, int graph[num][num], int source) {
    int dist[num];
    int parent[num];
    int visited[num];

    for (int i = 0; i < num; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < num - 1; count++) {
        int u = minDistance(dist, visited, num);
        visited[u] = 1;

        for (int v = 0; v < num; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest paths from vertex %d:\n", source + 1);
    for (int i = 0; i < num; i++) {
        printf("Vertex(%d - %d): Distance = %d (Path:", source + 1, i + 1, dist[i]);
        if (i == source) {
            printf(" %d", source + 1);
        } else {
            displayPath(parent, i, source);
        }
        printf(")\n");
    }
}

int main() {
    int num;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &num);
    int graph[num][num];
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source = 0; // You can choose the source vertex here
    dijkstra(num, graph, source);
    return 0;
}
