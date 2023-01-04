#include <stdio.h>
#include <stdlib.h>

#define V 4
struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};
  
struct Queue {
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
  
    void enQueue(int x)
    {
        QNode* temp = new QNode(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
  	int peek()
  	{
  		if(front != NULL)
  		return front->data;
	  }
	bool emtpy()
	{
		if(front == NULL)
		{
			return false;
			}	
		else
		 	return true;	
	}
    void deQueue()
    {
        if (front == NULL)
            return;
        QNode* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
          free(temp);
    }
};

void BFS(int adjMatrix[][V],int startVertex) {
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

      Queue q;

  visited[startVertex] = true;
  q.enQueue(startVertex);
 while (q.emtpy()) {	
    int currVertex = q.peek();
    printf("\nVisited:%d\n",currVertex);
    q.deQueue();
    for (int i = 0; i < V; ++i) {
      int adjVertex = i;
      if (adjMatrix[currVertex][i] != 0 && (!visited[i])) {
        visited[adjVertex] = true;
        q.enQueue(adjVertex);
      }
    }
  }
}

DFS(int start,bool visited[V])
{
	
    
    visited[start] = true;

	printf("\n%d",start);
	
	for (int j = 0; j < V; j++) {
		if ((!visited[j])) {
			DFS(j,visited);
		}
	}
}


int minDis(int dist[], bool source[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (source[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void printSolution(int dist[],int src)
{

	printf("\nVertex \t\t shortest Distance from Source i.e %d\n", src);
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
		
}

void dj_all(int adjMatrix[V][V], int src)
{
	int dist[V]; 
	bool source[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, source[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDis(dist, source);
		source[u] = true;
		for (int v = 0; v < V; v++)
			if (!source[v] && adjMatrix[u][v] && dist[u] != INT_MAX
				&& dist[u] + adjMatrix[u][v] < dist[v])
				dist[v] = dist[u] + adjMatrix[u][v];
	}
	printSolution(dist,src);
}
void dj_specific(int adjMatrix[V][V], int src,int des)
{
	int dist[V]; 
	bool source[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, source[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDis(dist, source);
		source[u] = true;
		for (int v = 0; v < V; v++)
			if (!source[v] && adjMatrix[u][v] && dist[u] != INT_MAX
				&& dist[u] + adjMatrix[u][v] < dist[v])
				dist[v] = dist[u] + adjMatrix[u][v];
	}
		printf("The shortest Distance of vertex %d from Source i.e %d is: %d\n", des,src, dist[des]);	
}



void printMatrix(int arr[][V]) {
  int i, j;
printf("\n=========Representation in Adjacent Matrix======\n");
  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d \t", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void)

{

int selection;
  int adjMatrix[V][V];
  int x;

  int  i, j;
 printf("\n========Graph containing %d vertices==========\n",V);
      for(i=0;i<V;i++)
      {
        for(j=0;j<V;j++)
        {
            printf("\nEnter weight at edge ( %d  %d)=  ",i,j);
            scanf("%d",&adjMatrix[i][j]);
        }
      } 
  printMatrix(adjMatrix);
do{
	printf("\n ==========Menu==========");
	printf("\nPress");
	printf("\n1.Depth first search");
	printf("\n2.Breadth first search");
	printf("\n3.Shortest path search to all destination(Dijkstra's algorithm)");
	printf("\n4.Shortest path search to specific destination(Dijkstra's algorithm)");
    printf("\n5.Exit ");
    printf("\nEnter selection: " );
    scanf("%d",&selection);

switch(selection)
{

	case 1:
   		{
   			bool visited[V];
            for (int i = 0; i < V; i++)
              visited[i] = false;	 
               	DFS(0,visited);
   			    break;
	     }
    case 2:
   		{
   			int y;
   			printf("\nEnter the vertex:");
   			scanf("%d",&y);
   		     BFS(adjMatrix,y);
   			break;
   		
	     }
	case 3:
   		{
   			int x;
   			printf("Enter the source to find distace to all destination:");
   			scanf("%d",&x);
   	    	dj_all(adjMatrix, x);
   			break;
	     }
	case 4:
   		{int x,y;
   			printf("Enter the source:");
   			scanf("%d",&x);
   			printf("Enter the destination:");
   			scanf("%d",&y);
   	        dj_specific(adjMatrix, x,y);
   			break;
	     }
}
}
while(selection!=5);
return 0;

}

 
