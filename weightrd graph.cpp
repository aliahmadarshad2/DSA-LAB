#include <stdio.h>
#define V 5
// Initialize the matrix to zero
void matrix(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}
// Add edges
void Edge(int arr[][V], int i, int j,int x) {
  arr[i][j] = x;
}
// Print the matrix
void printMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d \t", arr[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int adjMatrix[V][V];
  int x;
  matrix(adjMatrix);
  Edge(adjMatrix, 0, 1, 2);
  Edge(adjMatrix, 0, 2, 3);
  Edge(adjMatrix, 1, 0, 2);
  Edge(adjMatrix, 1, 2, 15);
  Edge(adjMatrix, 1, 3, 2);
  Edge(adjMatrix, 2, 0, 3);
  Edge(adjMatrix, 2, 1, 15);
  Edge(adjMatrix, 2, 4, 13);
  Edge(adjMatrix, 3, 1, 2);
  Edge(adjMatrix, 3, 4, 9);
  Edge(adjMatrix, 4, 2, 13);
  Edge(adjMatrix, 4, 3, 9);
  printMatrix(adjMatrix);
  return 0;
}
