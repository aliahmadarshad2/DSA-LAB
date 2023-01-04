#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head ;
struct Node* temp;

   
void insert(int new_data) {
   int p,i;
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   cout<<"Enter the position:";
   cin>>p;
   if(p<=0)
   {
   	cout<<"invalid position";
   }
   else
   {
   	temp=head;
   	
   while( i<p)
   {
   		temp=temp->next;
   		i++;
   }
   }
   new_node->data = new_data;
   new_node->next = temp->next;
   temp->next=new_node; 
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
	
	insert(9);
	insert(1);
   insert(7);
   insert(2);
   insert(0);
   insert(4);
    insert(1);
    insert(3);
  
   cout<<"The linked list is(At the end): ";
   display();
   return 0;
}
