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

void delete_at_end() {
   struct Node* temp;
     if (tail==0)   
     {
     	
	 }
	 else{
	 
         temp=tail;
          tail=tail->prev;
         tail->next= NULL;      
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
   insert(7);
   insert(2);
   insert(0);
   insert(5);
   cout<<"The doubly linked list is: ";
   display();

   delete_at_end();
   cout<<"\nThe doubly linked list is(After deletion at end):";
   display();
   return 0;
}
