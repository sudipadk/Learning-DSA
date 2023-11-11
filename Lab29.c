#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void BFS(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 1; i <= vertices; ++i) {
            if (matrix[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void DFS(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex, int visited[MAX_VERTICES]) {
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    for (int i = 1; i <= vertices; ++i) {
        if (matrix[startVertex][i] && !visited[i]) {
            DFS(matrix, vertices, i, visited);
        }
    }
}

int main() {
    int vertices, edges;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &vertices);

    int matrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges in the format 'source destination':\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        matrix[src][dest] = 1;
    }

    int visited[MAX_VERTICES] = {0};

    printf("Breadth-First Traversal: ");
    BFS(matrix, vertices, 1); // Start from vertex 1
    printf("\n");

    // Reset visited array for DFS
    for (int i = 1; i <= vertices; ++i) {
        visited[i] = 0;
    }

    printf("Depth-First Traversal: ");
    for (int i = 1; i <= vertices; ++i) {
        if (!visited[i]) {
            DFS(matrix, vertices, i, visited);
        }
    }
    printf("\n");

    return 0;
}