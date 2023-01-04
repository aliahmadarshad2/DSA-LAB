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
void delete_at_beg() {
	struct Node* temp;
        if(tail == NULL)
        {
       cout<<"list is empty";
        }
        else
        {
            temp=tail->next;
            tail->next = temp->next;
			 free(temp);    
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
   delete_at_beg();
   cout<<"\nThe circular linked list is(after deletion at beg): ";
   display();
   return 0;
}
