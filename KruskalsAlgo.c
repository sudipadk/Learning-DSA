#include <stdio.h>

#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

void inputGraph() {
  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the weighted adjacency matrix of the graph (%d x %d):\n", n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &Graph[i][j]);
    }
  }
}

int main() {
  inputGraph();

  kruskalAlgo();
  print();

  return 0;
}
