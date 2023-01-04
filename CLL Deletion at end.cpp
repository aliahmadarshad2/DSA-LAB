#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* tail = NULL;
struct Node* head = NULL;
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
void delete_at_end() {
	struct Node* temp;
	struct Node* prev;
	temp=tail->next;
        if(tail == NULL)
        {
       cout<<"list is empty";
        }
        else if(temp->next==temp)
        {
        	tail=0;
        	free(temp);
		}
        else
        {    
            while(temp->next!=tail->next)
            {
            	prev=temp;
             temp=temp->next;	
			}
            prev->next = temp->next;
            tail=prev;
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
   delete_at_end();
   cout<<"\nThe circular linked list is(after deletion at end): ";
   display();
   return 0;
}
