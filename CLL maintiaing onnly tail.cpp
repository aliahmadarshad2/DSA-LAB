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
   return 0;
}
