#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
void insert_at_beg(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   struct Node*tail;
   newnode->data = newdata;
   newnode->prev = NULL;   
   newnode->next = NULL;
        if(head == NULL)
        {
            head = tail=newnode;
        }
        else
        {
        
           head->prev=newnode;
           newnode->next=head;
            head=newnode;
        }
}
void insert_at_end(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   struct Node*tail;
   newnode->data = newdata;
   newnode->prev = NULL;   
   newnode->next = NULL;
  if(head == NULL)
        {
            head = tail=newnode;
        }
        else
        {
        
           tail->next=newnode;
           newnode->prev=tail;
            tail=newnode;
        }
}
insert_at_position(int newdata)
{
	 int p,i=1;
   cout<<"Enter the position(for at):";
   cin>>p;
   if(p==1)
   {
   	insert_at_beg(newdata);
   }
   else
   {
   	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   	struct Node *temp;
   	new_node->data = newdata;
   new_node->prev = NULL;   
   new_node->next = NULL;
   	temp=head;
   	
   while( i<p-1)
   {
   		temp=temp->next;
   		i++;
   }
   new_node->prev=temp;
   new_node->next=temp->next;
   temp->next=new_node;
   new_node->next->prev=new_node;
   }
   
}
insert_after_position(int newdata)
{
	 int p,i=1;
   cout<<"Enter the position(for after):";
   cin>>p;
   	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   	struct Node *temp;
   	new_node->data = newdata;
   new_node->prev = NULL;   
   new_node->next = NULL;
   	temp=head;  	
   while( i<p)
   {
   		temp=temp->next;
   		i++;
   }
   new_node->prev=temp;
   new_node->next=temp->next;
   temp->next=new_node;
   new_node->next->prev=new_node;
   }
   

void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
	
	insert_at_end(6);
   insert_at_beg(3);
   insert_at_beg(4);
   insert_at_beg(5);
   insert_at_position(8);
insert_after_position(7);
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}
