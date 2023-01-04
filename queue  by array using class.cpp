#include <iostream>
#define MAX 10

using namespace std;
class Queue{
 int front=-1,rear=-1;
      int queue[MAX];
 
      public:
  
      
	void insert(int val)
	{
		if(rear==MAX-1)
		cout<<"overflow";
		else if(front==-1&&rear==-1)
		{
			front=rear=0;
			queue[rear]=val;
            cout<<"\ninserted\n";	
		}
		else
		{
			rear++;
			queue[rear]=val;
            cout<<"\ninserted\n";
		}
	}
	void peek()
	{
		if(rear==front==-1)
		{
			cout<<"Empty";
		}
		else
		{
			cout<<"\n\nPeek is: "<<queue[front];
		}
	}
  void qdelete()
       {
              int val;
  
              if(front==-1||front>rear)
             {
                       cout<<"\nQUEUE UNDERFLOW";
         }
             else
             {
                      val=queue[front];
                      front++;
                      cout<<"\n\nITEM DELETED: "<<val;
             }
       }
	void print()
	{
              if(front==-1 && rear==-1)
              {
                      cout<<"\n\nQUEUE IS EMPTY\n";
              }
              else
              {
                      cout<<"\n\nQUEUE ITEMS\n";
                      for(int i=front;i<=rear;i++)
                      {
                               cout<<queue[i]<<" ";
                      }
              }
	}
};
int main()
{
	Queue obj;
	obj.print();

	obj.insert(1);
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);
	obj.insert(6);
	obj.print();
	obj.peek();
	obj.qdelete();
	obj.print();

	
	return 0;
}
