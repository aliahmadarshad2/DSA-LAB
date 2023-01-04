#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* tail = NULL;

void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;

        if(tail == NULL)
        {
          
            tail = new_node;
            tail->next=new_node;
        }
        else
        {
            new_node->next=tail->next;
            tail->next = new_node;
			 tail=new_node;    
        }         
}
void insert_at_beg(int new_data)
{
	 struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;

        if(tail == NULL)
        {
          
            tail = new_node;
            tail->next=new_node;
        }
        else
        {
            new_node->next=tail->next;
            tail->next = new_node;
			
        }         
}
void insert_at_end(int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;

        if(tail == NULL)
        {
          
            tail = new_node;
            tail->next=new_node;
        }
        else
        {
            new_node->next=tail->next;
            tail->next = new_node;
			tail=new_node;
        }         
	
}
void insert_at_pos(int new_data)
{
	struct Node* temp;
   int pos,i=1;
   temp=tail;
   cout<<"\nEnter position:";
   cin>>pos;
   if(pos<0)
   {
   	cout<<"Invalid position";
   }
   else if(pos==1)
   {
   	insert_at_beg(new_data);
   }
   else
   {
   	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;
   temp=tail->next;
   while(i<pos-1)
   {
   	temp=temp->next;
   	i++;
   }
    new_node->next=temp->next;
    temp->next=new_node;
}
}
	
void display() {
   struct Node* ptr;
   ptr = tail->next;
   while (ptr->next != tail->next) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<< ptr->data <<" ";
}
int main() {
   insert(7);
   insert(2);
   insert(1);
   cout<<"The circular linked list is(maintaing only tail pointer): ";
   display();
   insert_at_beg(5);
   cout<<"\nThe circular linked list is(insertion at beg): ";
   display();
   insert_at_end(6);
   cout<<"\nThe circular linked list is(insertion at end): ";
   display();
   insert_at_pos(9);
   cout<<"\nThe circular linked list is(insertion at given position): ";
   display();
   return 0;
}
