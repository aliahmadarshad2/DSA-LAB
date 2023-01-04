#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;

        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
            tail->next=new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
			 tail->next=head;    
        }
       
       
            
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr->next != head) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<< ptr->data <<" ";
}
int main() {
   insert(7);
   insert(2);
   insert(1);
   cout<<"The circular linked list is:(maintaaining head and tail both) ";
   display();
   return 0;
}
