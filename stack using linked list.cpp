#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* top=NULL ;

void push(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = top;
   top=new_node;
          
}
void pop() {
   struct Node* temp;
   temp=top;
   top = top->next;
  free(temp);
}
void display() {
   struct Node* ptr;
   ptr = top;
   if(top == NULL)
        {
            cout<<"Stack is empty";  
        } 
		else
		{
		    
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
  }
   }
   
}
int main() {
	
   push(1);
    push(2);
     push(3);
   cout<<"The Stack using linked list: ";
   display();
   pop();
    cout<<"\nThe Stack using linked list(After first pop): ";
   display();
   return 0;
}
