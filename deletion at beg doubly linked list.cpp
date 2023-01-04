#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
void insert(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   struct Node*temp;
   newnode->data = newdata;
   newnode->prev = NULL;   
   newnode->next = NULL;
        if(head == NULL)
        {
            head = temp=newnode;
        }
        else
        {
        	temp->next=newnode;
           newnode->prev=temp;
            temp=newnode;
        }
}
void delete_at_beg() {
   struct Node* temp;
        if(head == NULL)
        {
            cout<<"LIST IS EMPTY";
        }
        else
        {
         temp=head;
         head=head->next;
         head->prev= NULL;
          free(temp);
        }
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
	insert(1);
	insert(2);
	insert(3);
   cout<<"The doubly linked list is: ";
   display();
 delete_at_beg();  
   cout<<"\nThe doubly linked list is(After deletion at beg):";
   display();
 
   return 0;
}
