#include <stdio.h>
#define V 4

// Initialize the matrix to zero
void matrix(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

// Add edges
void Edge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}
// Print the matrix
void printMatrix(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int adjMatrix[V][V];
  matrix(adjMatrix);
  Edge(adjMatrix, 0, 1);
  Edge(adjMatrix, 0, 2);
  Edge(adjMatrix, 0, 3);
  Edge(adjMatrix, 1, 0);
  Edge(adjMatrix, 1, 2);
  Edge(adjMatrix, 2, 0);
  Edge(adjMatrix, 2, 1);
  Edge(adjMatrix, 3, 0);
  printMatrix(adjMatrix);
  return 0;
}
