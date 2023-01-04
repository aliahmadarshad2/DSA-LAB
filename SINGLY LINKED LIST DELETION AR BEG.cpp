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

        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
}

void delete_from_beg() {
   struct Node* temp;
   temp=head;
   head = head->next;
  free(temp);
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
	
	
	insert(1);
   insert(7);
   insert(2);
   insert(0);
   insert(4);
    insert(1);
    insert(3);
  delete_from_beg();
   cout<<"The linked list is(DELETION AT BEG): ";
   display();
   return 0;
}
