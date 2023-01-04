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
 void delete_from_pos() {
   struct Node* temp;
   
	struct Node* nextnode;
   int pos,i=1;
   temp=tail->next;
   cout<<"\nEnter position:";
   cin>>pos;
   if(pos==1)
   {
   	delete_at_beg();
   }
   else
   {
   
   while(i<pos-1)
   {	
   
   	temp=temp->next;
   	i++;
   }
   nextnode=temp->next;
    temp->next=nextnode->next;
  free(nextnode);
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
   insert(5);
   insert(4);
   insert(3);
   cout<<"The circular linked list is(maintaing only tail pointer): ";
   display();
   delete_from_pos();
   cout<<"\nThe circular linked list is(after deletion at position): ";
   display();
   return 0;
}
