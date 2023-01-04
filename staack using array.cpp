#include<iostream>
using namespace std;
int stack[10], a=10, top=-1;
void push(int val)
{
	if(top>=a-1)
	{
	cout<<"Stack is overflow\n";			
	}
	else
	{
		top++;
		stack[top]=val;
		
	}
}
void pop()
	{
	if(top<=-1)
	{
	cout<<"Stack is Empty\n";			
	}
	else
	{
			cout<<"\nPopped value is:"<<stack[top]<<"\n";	
		top--;	
	}
}
void print()
{
if(top>=0)
	{
	cout<<"Stack elements are:\n";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";		
	}
	else
	{
	cout<<"Stack is Empty\n";	
}	}
int main()
{
	int choice,val;
	do{
	
   cout<<"\npress 1 to push\npress 2 to pop\npress3 to display\n";
   cin>>choice;
   switch(choice)
   {
   	case 1:
   		{
   			cout<<"Enter number to push\n";
   			cin>>val;
   			push(val);
   			break;
	     }
    case 2:
   		{
   			pop();
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
