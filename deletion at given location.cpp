#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head ;
struct Node* temp ;
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

void delete_from_pos() {
   struct Node* nextnode;
   int pos,i=1;
   temp=head;
   cout<<"Enter position:";
   cin>>pos;
   while(i<pos-1)
   {
   	temp=temp->next;
   	i++;
   }
    nextnode=temp->next;
    temp->next=nextnode->next;
  free(nextnode);
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
  delete_from_pos();
   cout<<"The linked list is(DELETION AT End): ";
   display();
   return 0;
}
