#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
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
void delete_from_pos() {
   struct Node* temp;
   int pos,i=1;
   temp=head;
   cout<<"Enter position:";
   cin>>pos;
   while(i<pos)
   {
   	temp=temp->next;
   	i++;
   }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
  free(temp);
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
	
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The doubly linked list is: ";
   display();
   delete_from_pos();
   cout<<"The doubly linked list is:(After deletion at given postiton) ";
   display();
   return 0;
}
