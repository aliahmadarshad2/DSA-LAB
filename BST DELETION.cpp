#include<iostream>
#include <stdlib.h>
using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = val;
   new_node->left = new_node->right = NULL;
   return new_node;
}
void preorder(struct node *root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}
void inorder(struct node *root) {
   if (root != NULL) {
   	inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
   }
}
void postorder(struct node *root) {
   if (root != NULL) {
     
      postorder(root->left);
      postorder(root->right);
       cout<<root->data<<" ";
   }
}
struct node* insertNode(struct node* new_node, int val) {
   if (new_node == NULL) return createNode(val);
   if (val < new_node->data)
   new_node->left = insertNode(new_node->left, val);
   else if (val > new_node->data)
   new_node->right = insertNode(new_node->right, val);
   return new_node;
    
}
int min(struct node* root) {
   if (root == NULL) 
   cout<<"Empty";
   node* current = root;
   while (current->left!=NULL)
   {
   	current=current->left;
   }
   
    return current->data;
}
struct node* Delete(struct node* root, int val) {
	struct node *temp;
   if (root == NULL) return root;
   else if (val < root->data)
  Delete(root->left, val);
  else if (val > root->data)
  Delete(root->right, val);
   else
   {
   	if(root->left==NULL && root->right==NULL)
   	{
   		delete root;
   		root=NULL;
   		return root;
	   }
	   else if(root->left==NULL)
	   {
	   	struct node *temp=root;
	   	root=root->right;
	   	free(temp);
	   	return root;
	   }
	   else if(root->right==NULL)
	   {
	   	struct node *temp=root;
	   	root=root->left;
	   	free(temp);
	   	return root;
	   }
	   else
	   {
	   	
	   	temp= min(root->right);
	   	root->data=temp->data;
	   	root->right=Delete(root->right,temp->data);
	   }
   }
    
}
int main() {
   struct node *root = NULL;
   root = insertNode(root, 4);
   insertNode(root, 5);
   insertNode(root, 2);
   insertNode(root, 9);
   insertNode(root, 1);
   insertNode(root, 3);
   cout<<"Pre-Order traversal of the Binary Search Tree is: ";
   preorder(root);
    cout<<"\nIN-Order traversal of the Binary Search Tree is: ";
   inorder(root);
    cout<<"\nPOST-Order traversal of the Binary Search Tree is: ";
   postorder(root);
   Delete(root,9);
   cout<<"Pre-Order traversal of the Binary Search Tree is: ";
   preorder(root);
    cout<<"\nIN-Order traversal of the Binary Search Tree is: ";
   inorder(root);
    cout<<"\nPOST-Order traversal of the Binary Search Tree is: ";
   postorder(root);
   
   return 0;
}
