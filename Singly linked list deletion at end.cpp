#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head ;
struct Node* temp ;
void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;

        if(head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
}

void delete_from_end() {
   struct Node* prevnode;
   temp=head;
   while(temp->next!=0)
   {
   	prevnode=temp;
   	temp=temp->next;
   }
    if(temp==head)
        {
            head = 0;
        }
        else
        {
           prevnode->next=0;
        }
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
    display();
    cout<<"\n";
  delete_from_end();
   cout<<"The linked list is(DELETION AT End): ";
   display();
   return 0;
}
