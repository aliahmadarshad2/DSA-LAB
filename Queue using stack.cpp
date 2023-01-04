#include<iostream>
#define N 5
using namespace std;
int stack1[N];
int stack2[N] , top1=-1,top2=-1;
int count=0;
void push1(int val)
{
	if(top1>=N-1)
	{
	cout<<"Queue is overflow\n";			
	}
	else
	{
		top1++;
		stack1[top1]=val;
		
	}
}
void push2(int val)
{
	if(top2>=N-1)
	{
	cout<<"Stack is overflow\n";			
	}
	else
	{
		top2++;
		stack2[top2]=val;
		
	}
}
int pop1()
	{
	if(top1<=-1)
	{
	cout<<"Queue is Empty\n";			
	}
	else
	{
			cout<<"\nPopped value is:"<<stack1[top1]<<"\n";	
		top1--;	
	}
	return stack1[top1--];
}
int pop2()
	{
	if(top2<=-1)
	{
	cout<<"Queue is Empty\n";			
	}
	else
	{
			cout<<"\nPopped value is:"<<stack2[top2]<<"\n";	
		top2--;	
	}
	return stack2[top2--];
}
void enqueue(int val)
{
	push1(val);
	count++;
}
void dequeue()
{
	int i;
	if(top1==-1 && top2==-1)
	{
		cout<<"Queue is empty";
	}
	else
	{
		for(i=0;i<count;i++)
		{
			push2(pop1());
		}
		cout<<"dequeue is:"<<pop2();
		count--;
			for(i=0;i<count;i++)
		{
				push1(pop2());
		}
	}
}


void print()
{
if(top1>=0)
	{
	cout<<"Queue elements are:\n";
      for(int i=0; i<=top1; i++)
      cout<<stack1[i]<<" ";		
	}
	else
	{
	cout<<"Queue is Empty\n";	
}	}
int main()
{
	int choice,val;
	do{
	
   cout<<"\npress 1 to Enqueue\npress 2 to Dequeue\npress3 to display\n";
   cin>>choice;
   switch(choice)
   {
   	case 1:
   		{
   			cout<<"Enter number to enqueue\n";
   			cin>>val;
   			enqueue(val);
   			break;
	     }
    case 2:
   		{
   			dequeue();
   			break;
	     }
	case 3:
   		{
   			print();
   			break;
	     }
   }
}
   while(choice!=4);
   return 0;
}
