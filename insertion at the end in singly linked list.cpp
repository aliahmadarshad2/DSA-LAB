#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head ;
struct Node* tail ;

void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;
   tail=head;
   while(tail != 0 &&  tail->next ==0)
   {
   	tail->next=new_node;
   	tail=tail->next;
   }
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
	
   insert(7);
   insert(2);
   insert(0);
   insert(4);
   insert(1);
   cout<<"The linked list is(At the end): ";
   display();
   return 0;
}
