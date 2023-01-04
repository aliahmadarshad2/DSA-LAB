#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *left , *right;
};
struct Node* create()
{
	int x;
 struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    cout<<"Enter Data(-1 for no node):";
    cin>>x;
    if(x==-1)
    {
    	return 0;
	}
	new_node->data=x;
   cout<<"Enter left child of"<<x<<":";
   new_node->left=create();
   cout<<"Enter right child of"<<x<<":";
   new_node->right=create();
   return new_node;
}
int main() {
	struct node* root;
	root=0;
create();
 
   return 0;
}
