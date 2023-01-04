#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* rear = NULL;



void enqueue(int new_data)
{
	 struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;

        if(rear == NULL)
        {
          
            rear = new_node;
            rear->next=new_node;
        }
        else
        {
            new_node->next=rear->next;
            rear->next = new_node;
			
        }         
}
void dequeue() {
	struct Node* front;
        if(rear == NULL)
        {
       cout<<"list is empty";
        }
        else
        {
            front=rear->next;
            rear->next = front->next;
			 free(front);    
        }
    }
       

	
void display() {
   struct Node* ptr;
   ptr =rear->next;
   while (ptr->next != rear->next) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<< ptr->data <<" ";
}
int main() {
   enqueue(7);
   enqueue(2);
   enqueue(1);
   cout<<"The circular Queue using liked list is ";
   display();
   dequeue();
   cout<<"\nThe circular linked list After dequeue: ";
   display();
   
   return 0;
}
