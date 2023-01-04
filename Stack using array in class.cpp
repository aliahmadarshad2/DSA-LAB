#include<iostream>
using namespace std;

class stack{
	int val,choice,stack[10],top=-1,a=10;
	public:
		
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
	cout<<"\nStack elements are:\n";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";		
	}
	else
	{
	cout<<"\nStack is Empty\n";	
}	
}

};

int main()
{
	stack myobj;	
	myobj.push(2);
	myobj.print();
	myobj.push(3);
	myobj.print();
	myobj.push(4);
	myobj.print();
	myobj.pop();
	myobj.print();
	stack myobj1;
	myobj1.print();
   return 0;
}
