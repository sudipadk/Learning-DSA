#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5

int minKey(int key[], int MSTset[])
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++)
    {
        if (MSTset[i] == 0 && key[i] < min)
            min = key[i], min_index = i;
    }
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V])
{
    int totalWeight = 0; // Initialize a variable to keep track of the total weight

    printf("Edge Weight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d-%d: %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]]; // Add the weight to the total
    }

    printf("Total Weight of Minimum Spanning Tree: %d\n", totalWeight); // Print the total weight
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int MSTset[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        MSTset[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, MSTset);
        MSTset[u] = 1;
        for (int i = 0; i < V; i++)
        {
            if (graph[u][i] && MSTset[i] == 0 && graph[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }

    printMST(parent, V, graph);
}

int main()
{
    int graph[V][V];

    printf("Enter the graph's edge weights (%d x %d matrix):\n", V, V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);
    return 0;
}
