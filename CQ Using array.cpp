#include <iostream>
#define MAX 10

using namespace std;
class Queue{
 int front=-1,rear=-1;
      int queue[MAX];
 
      public:
  
      
	void insert(int val)
	{
	 if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   else if (front == -1) {
      front = 0;
      rear = 0;
   } 
   else if (rear == MAX - 1)
   {
      rear = 0;
   }
   else
      rear = rear + 1;
   queue[rear] = val ;
}
	
 void qdelete() {
 	
   if (front == -1) {
      cout<<"Queue is empty\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<queue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == MAX - 1)
      front = 0;
      else
      front = front + 1;
   }
}
	void print()
	{
		 
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (f <= r) {
      while (f <= r){
         cout<<queue[f]<<" ";
         f++;
      }
   } else {
      while (f <= MAX - 1) {
         cout<<queue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<queue[f]<<" ";
         f++;
      }
   }
   cout<<endl;

	
}
};
int main()
{
	Queue obj;
	obj.print();
	obj.insert(1);
	obj.insert(2);

	obj.print();
	obj.qdelete();
	obj.print();

	
	return 0;
}

