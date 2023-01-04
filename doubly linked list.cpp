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
   return 0;
}
